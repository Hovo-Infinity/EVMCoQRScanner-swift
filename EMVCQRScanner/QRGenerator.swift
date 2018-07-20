//
//  QRGenerator.swift
//  EMVCQRScanner
//
//  Created by Hovhannes Stepanyan on 7/19/18.
//  Copyright © 2018 Hovhannes Stepanyan. All rights reserved.
//

import UIKit

class QRGenerator: NSObject {
    class func generateQRFrom(_ string: String) -> UIImage? {
        let data = string.data(using: String.Encoding.utf8)
        if let filter = CIFilter(name: "CIQRCodeGenerator") {
            filter.setValue(data, forKey: "inputMessage")
            let transform = CGAffineTransform(scaleX: 3, y: 3)
            if let output = filter.outputImage?.transformed(by: transform) {
                return UIImage(ciImage: output)
            }
        }
        return nil
    }
}
