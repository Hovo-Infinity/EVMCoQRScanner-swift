//
//  MPQRScanViewController.swift
//  EMVCQRScanner
//
//  Created by Hovhannes Stepanyan on 7/18/18.
//  Copyright © 2018 Hovhannes Stepanyan. All rights reserved.
//

import UIKit
import AVFoundation
import MasterpassQRScanSDK

class MPQRScanViewController: UIViewController, QRCodeReaderDelegate {

    lazy var reader: QRCodeReaderViewController = {
        return QRCodeReaderViewController(builder: QRCodeReaderViewControllerBuilder {
            let readerView = $0.readerView
            
            // Setup overlay view
            let overlayView = readerView.getOverlay()
            overlayView.cornerColor = UIColor.black
            overlayView.cornerWidth = 6
            overlayView.cornerLength = 75
            overlayView.indicatorSize = CGSize(width: 250, height: 250)
            
            // Setup scanning region
            $0.scanRegionSize = CGSize(width: 250, height: 250)
            
            // Hide torch button provided by the default view
            $0.showTorchButton = true
            
            // Hide cancel button provided by the default view
            $0.showCancelButton = false
            
            // Don't start scanning when this view is loaded i.e initialized
            $0.startScanningAtLoad = false
            
            $0.showSwitchCameraButton = true;
            
        })
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        guard QRCodeReader.isAvailable() && QRCodeReader.supportsQRCode() else {
            showAlert(title: "error", message: "Somthig went wrong,\n check condition ``QRCodeReader.isAvailable() && QRCodeReader.supportsQRCode()``")
            return
        }
        reader.delegate = self
        self.addChildViewController(reader)
        self.view.addSubview(reader.view)
        reader.view.centerXAnchor.constraint(equalTo: self.view.centerXAnchor).isActive = true
        reader.view.centerYAnchor.constraint(equalTo: self.view.centerYAnchor).isActive = true
        reader.didMove(toParentViewController: self)
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        reader.startScanning()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        reader.stopScanning()
    }
    
    // MARK: QRCodeReaderDelegate
    
    func reader(_ reader: QRCodeReaderViewController, didScanResult result: String) {
        EVMCoHelper.sharedInstance().setQRCode(result)
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
        reader.stopScanning()
    }
    
    func readerDidCancel(_ reader: QRCodeReaderViewController) {
        reader.stopScanning()
    }
    
    func showAlert(title: String, message: String) {
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Ok", style: .cancel, handler: { (_) in
            self.navigationController?.popViewController(animated: true)
        }))
        present(alert, animated: true, completion: nil)
    }
}
