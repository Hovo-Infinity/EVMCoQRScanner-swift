//
//  EVMCoHelper.swift
//  EMVCQRScanner
//
//  Created by Hovhannes Stepanyan on 7/17/18.
//  Copyright © 2018 Hovhannes Stepanyan. All rights reserved.
//

import Foundation

enum DataObjectTypes : Int {
    case payloadFormatIndicator = 0
    case pointOfInitiationMethod
    case merchantAccountInfo
    case merchantCategoryCode
    case transactionCurrency
    case transactionAmount
    case tipOrConvenienceIndicator
    case valueOfConvenienceFeeFixed
    case valueOfConvenienceFeePercentage
    case countryCode
    case merchantName
    case merchantCity
    case postalCode
    case additionalDataFieldTemplate
    case merchantInformationLanguageTemplate
    case rfuForEMVCo
    case unreservedTemplates
    case crc
}


class DataObject: TemplateClassData {
    var value = [NSObject]()
    
    func additionalDataObjectFromString() -> [NSObject] {
        let code = "\(self.stringValue)"
        var array = [AdditionalDataObject]()
        var splitedStrings = [String]()
        var index: Int = 0
        let len: Int = 2
        while index < code.count {
            let count = Int((code as NSString).substring(with: NSRange(location: index + 2, length: len))) ?? 0
            let part: String = (code as NSString).substring(with: NSRange(location: index, length: count + 4))
            index += count + 4
            splitedStrings.append(part)
        }
        for string: String in splitedStrings {
            let obj = AdditionalDataObject()
            let Id = Int(((string as NSString).substring(to: 2))) ?? 0
            obj.id = Id
            obj.len = Int((string as NSString).substring(with: NSRange(location: 2, length: 2))) ?? 0
            obj.stringValue = (string as NSString).substring(from: 4)
            switch Id {
            case 1:
                obj.name = "Bill Number"
            case 2:
                obj.name = "Mobile Number"
            case 3:
                obj.name = "Store Label"
            case 4:
                obj.name = "Loyalty Number"
            case 5:
                obj.name = "Reference Label"
            case 6:
                obj.name = "Customer Label"
            case 7:
                obj.name = "Terminal Label"
            case 8:
                obj.name = "Purpose of Transaction"
            case 9:
                obj.name = "Additional Consumer Data Request"
            case 10...49:
                obj.name = "RFU for EMVCo"
            case 50...99:
                obj.name = "Payment System specific templates"
            default:
                break
            }
            array.append(obj)
        }
        return array
    }

    func merchantInformation() -> [NSObject] {
        let strings = EVMCoHelper.splitedStrings(fromCode: "\(self)")
        var array = [NSObject]()
        for string: String in strings {
            let obj = MerchantInformation()
            let Id = Int((string as NSString).substring(to: 2))!
            obj.id = Id
            obj.len = Int((string as NSString).substring(with: NSRange(location: 2, length: 2))) ?? 0
            obj.stringValue = (string as NSString).substring(from: 4)
            switch Id {
            case 0:
                obj.name = "Language Preference"
            case 1:
                obj.name = "Merchant Name—Alternate Language"
            case 2:
                obj.name = "Merchant City—Alternate Language"
            case 3...99:
                obj.name = "RFU for EMVCo"
            default:
                break
            }
            array.append(obj)
        }
        return array
    }

    func merchantAccountInformation() -> [NSObject] {
        let strings = EVMCoHelper.splitedStrings(fromCode: "\(self.stringValue)")
        var array = [NSObject]()
        for string: String in strings {
            let obj = MerchantInformation()
            let Id = Int(((string as NSString).substring(to: 2)))!
            obj.id = Id
            obj.len = Int((string as NSString).substring(with: NSRange(location: 2, length: 2))) ?? 0
            obj.stringValue = (string as NSString).substring(from: 4)
            switch Id {
            case 0:
                obj.name = "Globally Unique Identifier"
            case 1...99:
                obj.name = "Payment network specific"
            default:
                break
            }
            array.append(obj)
        }
        return array
    }

    func templateData() -> [NSObject] {
        let strings = EVMCoHelper.splitedStrings(fromCode: "\(self.stringValue)")
        var array = [NSObject]()
        for string: String in strings {
            let obj = MerchantInformation()
            let Id = Int(((string as NSString).substring(to: 2)))!
            obj.id = Id
            obj.len = Int((string as NSString).substring(with: NSRange(location: 2, length: 2))) ?? 0
            obj.stringValue = (string as NSString).substring(from: 4)
            switch Id {
            case 0:
                obj.name = "Globally Unique Identifier"
            case 1...99:
                obj.name = "Context Specific Data"
            default:
                break
            }
            array.append(obj)
        }
        return array
    }

    override var debugDescription: String {
        var desc = "id = \(id)\nname = \(name)\nlength = \(len)\nvalue = [\n"
        for object: NSObject in value {
            desc = desc + ("\(object.debugDescription)\n")
        }
        return desc + ("]\n")
    }

}


class EVMCoHelper: NSObject {
    private static var shared: EVMCoHelper? = nil
    private(set) var objects = [DataObject?]()
    private var _code: String?
    private(set) var code: String {
        get {
            return _code!
        }
        set {
            _code = newValue
            var arr = [DataObject?]()
            let strings = EVMCoHelper.splitedStrings(fromCode: code)
            var count = 0
            for string: String in strings {
                count += string.count
                let obj: DataObject? = EVMCoHelper.dataObject(from: string)
                arr.append(obj)
            }
            if count == newValue.count {
                isValid = true
                objects = arr
            }
        }
    }
    private(set) var isValid = false
    class func sharedInstance() -> EVMCoHelper {
        if (shared == nil) {
            shared = EVMCoHelper()
        }
        return shared!
    }
    
    func setQRCode(_ code: String) {
        self.code = code
    }
    
    func get(_ type: DataObjectTypes) -> DataObject {
        switch type {
        case .payloadFormatIndicator:
            return objects.filter { NSPredicate(format: "Id = 0").evaluate(with: $0) }.first!!
        case .pointOfInitiationMethod:
            return objects.filter { NSPredicate(format: "Id = 1").evaluate(with: $0) }.first!!
        case .merchantAccountInfo:
            return objects.filter { NSPredicate(format: "Id >= 2 AND Id <= 51").evaluate(with: $0) }.first!!
        case .merchantCategoryCode:
            return objects.filter { NSPredicate(format: "Id = 52").evaluate(with: $0) }.first!!
        case .transactionCurrency:
            return objects.filter { NSPredicate(format: "Id = 53").evaluate(with: $0) }.first!!
        case .transactionAmount:
            return objects.filter { NSPredicate(format: "Id = 54").evaluate(with: $0) }.first!!
        case .tipOrConvenienceIndicator:
            return objects.filter { NSPredicate(format: "Id = 55").evaluate(with: $0) }.first!!
        case .valueOfConvenienceFeeFixed:
            return objects.filter { NSPredicate(format: "Id = 56").evaluate(with: $0) }.first!!
        case .valueOfConvenienceFeePercentage:
            return objects.filter { NSPredicate(format: "Id = 57").evaluate(with: $0) }.first!!
        case .countryCode:
            return objects.filter { NSPredicate(format: "Id = 58").evaluate(with: $0) }.first!!
        case .merchantName:
            return objects.filter { NSPredicate(format: "Id = 59").evaluate(with: $0) }.first!!
        case .merchantCity:
            return objects.filter { NSPredicate(format: "Id = 60").evaluate(with: $0) }.first!!
        case .postalCode:
            return objects.filter { NSPredicate(format: "Id = 61").evaluate(with: $0) }.first!!
        case .additionalDataFieldTemplate:
            return objects.filter { NSPredicate(format: "Id = 62").evaluate(with: $0) }.first!!
        case .merchantInformationLanguageTemplate:
            return objects.filter { NSPredicate(format: "Id = 64").evaluate(with: $0) }.first!!
        case .rfuForEMVCo:
            return objects.filter { NSPredicate(format: "Id >= 65 AND Id <= 79").evaluate(with: $0) }.first!!
        case .unreservedTemplates:
            return objects.filter { NSPredicate(format: "Id >= 80 AND Id <= 99").evaluate(with: $0) }.first!!
        case .crc:
            return objects.filter { NSPredicate(format: "Id = 63").evaluate(with: $0) }.first!!
        }
    }
    
    class func splitedStrings(fromCode code: String) -> [String] {
        var index: Int = 0
        let len: Int = 2
        var splitedStrings = [String]()
        while index < code.count {
            if index + len + 2 <= code.count {
                let count = Int((code as NSString).substring(with: NSRange(location: index + 2, length: len))) ?? 0
                if index + count + 4 <= code.count {
                    let part: String = (code as NSString).substring(with: NSRange(location: index, length: count + 4))
                    index += count + 4
                    splitedStrings.append(part)
                }
            } else {
                break
            }
        }
        return splitedStrings
    }
    
    class func dataObject(from string: String) -> DataObject? {
        guard let Id = Int((string as NSString).substring(to: 2)) else { return nil }
        let obj = DataObject()
        obj.id = Id
        obj.len = Int((string as NSString).substring(with: NSRange(location: 2, length: 2))) ?? 0
        obj.stringValue = (string as NSString).substring(from: 4)
        switch Id {
        case 0:
            obj.name = "Payload Format Indicator"
            obj.value = [obj.stringValue as NSString]
        case 1:
            obj.name = "Point of Initiation Method"
            obj.value = ["\(obj.stringValue) \n Note: The value of \"11\" should be used when the same QR Code is shown for more than one transaction and the value of \"12\" should be used when a new QR Code is shown for each transaction."  as NSString]
        case 2, 3:
            obj.name = "Reserved for Visa"
            obj.value = [obj.stringValue as NSString]
        case 4, 5:
            obj.name = "Reserved for Mastercard"
            obj.value = [obj.stringValue as NSString]
        case 6, 7, 8:
            obj.name = "Reserved by EMVCo"
            obj.value = [obj.stringValue as NSString]
        case 9, 10:
            obj.name = "Reserved for Discover"
            obj.value = [obj.stringValue as NSString]
        case 11, 12:
            obj.name = "Reserved for Amex"
            obj.value = [obj.stringValue as NSString]
        case 13, 14:
            obj.name = "Reserved for JCB"
            obj.value = [obj.stringValue as NSString]
        case 15, 16:
            obj.name = "Reserved for UnionPay"
            obj.value = [obj.stringValue as NSString]
        case 17...25:
            obj.name = "Reserved by EMVCo"
            obj.value = [obj.stringValue as NSString]
        case 26...51:
            obj.name = "Templates reserved for additional payment networks"
            obj.value = obj.merchantAccountInformation()
        case 52:
            obj.name = "Merchant Category Code"
            obj.value = [obj.stringValue as NSString]
        case 53:
            obj.name = "Transaction Currency"
            obj.value = [obj.stringValue as NSString]
        case 54:
            obj.name = "Transaction Amount"
            obj.value = [obj.stringValue as NSString]
        case 55:
            obj.name = "Tip or Convenience Indicator"
            obj.value = [obj.stringValue as NSString]
        case 56:
            obj.name = "Value of Convenience Fee Fixed"
            obj.value = [obj.stringValue as NSString]
        case 57:
            obj.name = "Value of Convenience Fee Percentage"
            obj.value = [obj.stringValue as NSString]
        case 58:
            obj.name = "Country Code"
            obj.value = [obj.stringValue as NSString]
        case 59:
            obj.name = "Merchant Name"
            obj.value = [obj.stringValue as NSString]
        case 60:
            obj.name = "Merchant City"
            obj.value = [obj.stringValue as NSString]
        case 61:
            obj.name = "Postal Code"
            obj.value = [obj.stringValue as NSString]
        case 62:
            obj.name = "Additional Data Field Template"
            obj.value = obj.additionalDataObjectFromString()
        case 63:
            obj.name = "CRC"
            obj.value = [obj.stringValue as NSString]
        case 64:
            obj.name = "Merchant Information— Language Template"
            obj.value = obj.merchantInformation()
        case 65...79:
            obj.name = "RFU for EMVCo"
            obj.value = [obj.stringValue as NSString]
        default:
            // case 80 ... 99:
            obj.name = "Unreserved Templates"
            obj.value = obj.templateData()
        }
        return obj
    }

}
