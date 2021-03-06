//
//  ScannerViewController.swift
//  EMVCQRScanner
//
//  Created by Hovhannes Stepanyan on 7/17/18.
//  Copyright © 2018 Hovhannes Stepanyan. All rights reserved.
//

import UIKit
import AVFoundation

class ScannerViewController: UIViewController, AVCaptureMetadataOutputObjectsDelegate {

    @IBOutlet private var messageLabel: UILabel!
    @IBOutlet weak var torchButton: UIBarButtonItem!
    var captureSession: AVCaptureSession?
    var videoPreviewLayer: AVCaptureVideoPreviewLayer?
    var qrCodeFrameView: UIView?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = "Scan"
        let device: AVCaptureDevice? = AVCaptureDevice.devices(for: AVMediaType.video).first(where: {$0.position == .back})
        var input: AVCaptureDeviceInput? = nil
        if let aDevice = device {
            input = try? AVCaptureDeviceInput(device: aDevice)
        }
        captureSession = AVCaptureSession()
        if let anInput = input {
            captureSession?.addInput(anInput)
        }
        let output = AVCaptureMetadataOutput()
        output.setMetadataObjectsDelegate(self, queue: DispatchQueue.main)
        if (captureSession?.canAddOutput(output))! {
            captureSession?.addOutput(output)
        }
        output.metadataObjectTypes = [.qr]
        let videoLayer = AVCaptureVideoPreviewLayer(session: captureSession!)
        videoLayer.videoGravity = .resizeAspectFill
        videoLayer.frame = view.layer.bounds
        videoPreviewLayer = videoLayer
        view.layer.addSublayer(videoPreviewLayer!)
        view.bringSubview(toFront: messageLabel)
        let qrCodeFrameView = UIView()
        qrCodeFrameView.layer.borderColor = UIColor.green.cgColor
        qrCodeFrameView.layer.borderWidth = 2.0
        view.addSubview(qrCodeFrameView)
        view.bringSubview(toFront: qrCodeFrameView)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        qrCodeFrameView?.frame = CGRect.zero
        messageLabel.text = "No QR detected"
        captureSession?.startRunning()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        captureSession?.stopRunning()
    }
    
    // MARK: - Action
    
    @IBAction func torch(_ sender: UIBarButtonItem) {
        guard let flashLight = AVCaptureDevice.devices(for: .video).first(where: {$0.position == .back}) else { return }
        if flashLight.isTorchAvailable  && flashLight.isTorchModeSupported(.on) {
            do {
                try flashLight.lockForConfiguration()
                if flashLight.isTorchActive {
                    flashLight.torchMode = .off
                } else {
                    flashLight.torchMode = .on
                }
                flashLight.unlockForConfiguration()
            } catch {
                print(error.localizedDescription)
            }
        }
    }
    
    @IBAction func flipCamera(_ sender: UIBarButtonItem) {
        guard let session = captureSession,
            let input = captureSession?.inputs.first else { return }
        session.beginConfiguration()
        guard let deviceInput = input as? AVCaptureDeviceInput else {
            session.commitConfiguration()
            return
        }
        session.removeInput(input)
        let newPosition = deviceInput.device.position == .back ? AVCaptureDevice.Position.front : AVCaptureDevice.Position.back
        torchButton.isEnabled = newPosition == .back
        let newCamera = AVCaptureDevice.devices(for: .video).first(where: { $0.position == newPosition })
        if let anNewCamera = newCamera {
            do {
                let newInput = try AVCaptureDeviceInput(device: anNewCamera)
                if session.canAddInput(newInput) {
                    session.addInput(newInput)
                }
            } catch {
                print(error.localizedDescription)
            }
        }
        session.commitConfiguration()
    }
    
    // MARK: - AVCaptureMetadataOutputObjectsDelegate
    
    func metadataOutput(_ output: AVCaptureMetadataOutput, didOutput metadataObjects: [AVMetadataObject], from connection: AVCaptureConnection) {
        if metadataObjects.count == 0 {
            qrCodeFrameView?.frame = CGRect.zero
            messageLabel.text = "No QR detected"
        } else {
            let metadataObject = metadataObjects.first as? AVMetadataMachineReadableCodeObject
            if metadataObject?.type == AVMetadataObject.ObjectType.qr {
                var transformedObject: AVMetadataObject? = nil
                if let anObject = metadataObject {
                    transformedObject = videoPreviewLayer?.transformedMetadataObject(for: anObject)
                }
                qrCodeFrameView?.frame = (transformedObject?.bounds)!
                if let stringValue = metadataObject?.stringValue {
                    messageLabel.text = metadataObject?.stringValue
                    EVMCoHelper.sharedInstance().setQRCode(stringValue)
                    if EVMCoHelper.sharedInstance().isValid {
                        captureSession?.stopRunning()
                        DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + Double(Int64(0.5 * Double(NSEC_PER_SEC))) / Double(NSEC_PER_SEC), execute: {
                            let vc = UIStoryboard(name: "Main", bundle: Bundle.main).instantiateViewController(withIdentifier: "TableViewController") as? TableViewController
                            let tableDataSource = TableViewDataSource()
                            tableDataSource.numberOfSections = 1
                            tableDataSource.numberOfItemsInSection = { _ in
                                return EVMCoHelper.sharedInstance().objects.count
                            }
                            tableDataSource.nameForIndexPath = { indexPath in
                                let index = indexPath.row
                                let obj = EVMCoHelper.sharedInstance().objects[index]
                                return (obj?.name)!
                            }
                            tableDataSource.descriptionForIndexPath = { indexPath in
                                let index = indexPath.row
                                let obj = EVMCoHelper.sharedInstance().objects[index]
                                return obj?.debugDescription
                            }
                            vc?.tableDataSource = tableDataSource
                            if let aVc = vc {
                                self.show(aVc, sender: nil)
                            }
                        })
                    } else {
                        showAlert(title: "Invalid EVM format", message: stringValue)
                    }
                }
            }
        }
    }

    override var preferredStatusBarStyle: UIStatusBarStyle {
        return .lightContent
    }
}
