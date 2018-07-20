//
//  EURMerchantScanerViewController.swift
//  EMVCQRScanner
//
//  Created by Hovhannes Stepanyan on 7/20/18.
//  Copyright © 2018 Hovhannes Stepanyan. All rights reserved.
//

import UIKit
import EURMerchantQrCodeReader

class EURMerchantScanerViewController: UIViewController, EURScanViewControllerDelegate {
    
    lazy var scanner: EURScanViewController = {
        let scanner = EURScanViewController(delegate: self)
        scanner.view.frame = self.view.bounds
        return scanner
    }()
    var tableDataSource = [String: NSObject]()

    override func viewDidLoad() {
        super.viewDidLoad()
        addChildViewController(scanner)
        view.addSubview(scanner.view)
        scanner.didMove(toParentViewController: self)
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
    }

    // MARK : - EURScanViewControllerDelegate
    func scanViewController(_ scanViewController: EURScanViewController, successfullyScanned merchantQrCodeObject: EURMerchantQrCodeObject, withValidCRC validCRC: Bool) {
        if validCRC {
            let propNames = merchantQrCodeObject.getPropertiesNames()
            for propName in propNames! {
                guard let value = merchantQrCodeObject.value(forKeyPath: propName) as? NSObject else { continue }
                if value is String && (value as? String)?.isEmpty == false {
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
        } else {
            showAlert(title: "Error", message: "invalid CRC")
        }
    }
    
    func scanViewController(_ scanViewController: EURScanViewController, finishedWithError error: Error) {
        showAlert(title: "Error", message: error.localizedDescription)
    }
}
