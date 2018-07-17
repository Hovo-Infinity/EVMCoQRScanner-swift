//
//  TemplateClassData.swift
//  EMVCQRScanner
//
//  Created by Hovhannes Stepanyan on 7/17/18.
//  Copyright © 2018 Hovhannes Stepanyan. All rights reserved.
//

import Foundation

class TemplateClassData: NSObject {
    var name = ""
    var id: Int = 0
    var len: Int = 0
    var stringValue = ""
    override var debugDescription: String {
        return "id = \(id)\nname = \(name)\nlength = \(len)\nvalue = \(stringValue)\n"
    }
}

class AdditionalDataObject: TemplateClassData {
}

class MerchantInformation: TemplateClassData {
}

class MerchantAccountInformation: TemplateClassData {
}
