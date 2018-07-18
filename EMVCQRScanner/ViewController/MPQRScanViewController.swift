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
import MasterpassQRCoreSDK

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
    
    var tableDataSource = [String: NSObject]()
    
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
        parseQRCode(code: result)
        /*EVMCoHelper.sharedInstance().setQRCode(result)
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
        })*/
        reader.stopScanning()
    }
    
    func readerDidCancel(_ reader: QRCodeReaderViewController) {
        reader.stopScanning()
    }
    
    // MARK: - helpers
    func parseQRCode(code: String) {
        do {
            // Parse qr code
            let pushData = try MPQRParser.parse(string:code)
            // PushPaymentData is subclass of NSObject, so to get properties names and values I must use reflections
            let propNames = pushData.getPropertiesNames()
            for propName in propNames! {
                guard let value = pushData.value(forKeyPath: propName) as? NSObject else { continue }
                if value is String {
                    tableDataSource[propName] = value
                } else {
                    let dictValue = NSMutableDictionary()
                    let subPropNames = value.getPropertiesNames()
                    for subPropName in subPropNames! {
                        guard let subValue = value.value(forKeyPath: subPropName) as? String else { continue }
                        dictValue[subPropName] = subValue
                    }
                    tableDataSource[propName] = dictValue
                }
            }
            DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + Double(Int64(0.5 * Double(NSEC_PER_SEC))) / Double(NSEC_PER_SEC), execute: {
                let vc = UIStoryboard(name: "Main", bundle: Bundle.main).instantiateViewController(withIdentifier: "TableViewController") as? TableViewController
                let tableViewDataSource = TableViewDataSource()
                tableViewDataSource.numberOfSections = 1
                tableViewDataSource.numberOfItemsInSection = { _ in
                    return self.tableDataSource.count
                }
                tableViewDataSource.nameForIndexPath = { indexPath in
                    let index = indexPath.row
                    return Array(self.tableDataSource)[index].key
                }
                tableViewDataSource.descriptionForIndexPath = { indexPath in
                    let index = indexPath.row
                    return Array(self.tableDataSource)[index].value.debugDescription
                }
                vc?.tableDataSource = tableViewDataSource
                if let aVc = vc {
                    self.show(aVc, sender: nil)
                }
            })
        } catch let error as MPQRError{
            if let str = error.getString(){
                showAlert(title: "Error", message: "\(str)")
            } else {
                showAlert(title: "Unknown error occurred", message: "\(error)")
            }
        } catch {
            showAlert(title: "Unknown error occurred", message: "\(error)")
        }
    }
    
    func showAlert(title: String, message: String) {
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Ok", style: .cancel, handler: { (_) in
            self.navigationController?.popViewController(animated: true)
        }))
        present(alert, animated: true, completion: nil)
    }
}

extension NSObject {
    func getPropertiesNames() -> Array<String>? {
        var arr = [String]()
        var count = UInt32()
        guard let properties = class_copyPropertyList(self.classForCoder, &count) else {
            return nil
        }
        for i in 0..<count {
            let property: objc_property_t = properties[Int(i)]
            guard let name = NSString(utf8String: property_getName(property)) as String? else {
                continue
            }
            arr.append(name)
        }
        return arr
    }
}
