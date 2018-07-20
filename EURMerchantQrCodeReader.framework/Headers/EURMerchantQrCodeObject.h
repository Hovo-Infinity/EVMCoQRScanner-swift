//
//  EURMerchantQrCodeObject.h
//  EURMerchantQrCodeReader
//
//  Copyright © 2018 Euromeric. All rights reserved.
//

#import <Foundation/Foundation.h>

/** An object containing all the parsed information from a EMV Compliant Merchant QR Code. Instances of this object are returned by the EURScanViewController. */
@interface EURMerchantQrCodeObject : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;


// Merchant Account Information

/** An array containing all Visa Merchant Identifiers contained in the QR Code. */
@property (nonatomic, copy, readonly, nonnull) NSArray<NSString *> *visaMerchantIdentifiers;
/** An array containing all MasterCard Merchant Identifiers contained in the QR Code. */
@property (nonatomic, copy, readonly, nonnull) NSArray<NSString *> *mastercardMerchantIdentifiers;
/** An array containing all Discover Merchant Identifiers contained in the QR Code. */
@property (nonatomic, copy, readonly, nonnull) NSArray<NSString *> *discoverMerchantIdentifiers;
/** An array containing all American Express Merchant Identifiers contained in the QR Code. */
@property (nonatomic, copy, readonly, nonnull) NSArray<NSString *> *amexMerchantIdentifiers;
/** An array containing all JCB Merchant Identifiers contained in the QR Code. */
@property (nonatomic, copy, readonly, nonnull) NSArray<NSString *> *jcbMerchantIdentifiers;
/** An array containing all UnionPay Merchant Identifiers contained in the QR Code. */
@property (nonatomic, copy, readonly, nonnull) NSArray<NSString *> *unionpayMerchantIdentifiers;
/** A dictionary of all Additional Payment Network Identifiers (ID "26" to "51") contained in the QR Code. The dictionary key is the ID of the Merchant Account Information Template. The dictionary value is another dictionary, containing all the template Data Object IDs as keys, and the template Data Objects as values. */
@property (nonatomic, copy, readonly, nonnull) NSDictionary<NSString *, NSDictionary<NSString *, NSString *> *> *additionalPaymentNetworkIdentifiers;


// Root Data Objects

/** Merchant Category Code (Data Object ID "52") */
@property (nonatomic, copy, readonly, nonnull) NSString *merchantCategoryCode;
/** Transaction Currency (Data Object ID "53") */
@property (nonatomic, copy, readonly, nonnull) NSString *transactionCurrency;
/** Transaction Amount (Data Object ID "54") */
@property (nonatomic, copy, readonly, nonnull) NSString *transactionAmount;
/** Tip or Convenience Indicator (Data Object ID "55") */
@property (nonatomic, copy, readonly, nonnull) NSString *tipOrConvenienceIndicator;
/** Value of Convenience Fee Fixed (Data Object ID "56") */
@property (nonatomic, copy, readonly, nonnull) NSString *valueOfConvenienceFeeFixed;
/** Value of Convenience Fee Percentage (Data Object ID "57") */
@property (nonatomic, copy, readonly, nonnull) NSString *valueOfConvenienceFeePercentage;
/** Country Code (Data Object ID "58") */
@property (nonatomic, copy, readonly, nonnull) NSString *countryCode;
/** Merchant Name (Data Object ID "59") */
@property (nonatomic, copy, readonly, nonnull) NSString *merchantName;
/** Merchant City (Data Object ID "60") */
@property (nonatomic, copy, readonly, nonnull) NSString *merchantCity;
/** Postal Code (Data Object ID "61") */
@property (nonatomic, copy, readonly, nonnull) NSString *postalCode;
/** CRC (Data Object ID "63") */
@property (nonatomic, copy, readonly, nonnull) NSString *crc;
/** A dictionary of all Unreserved Templates (ID "80" to "99") contained in the QR Code. The dictionary key is the ID of the Unreserved Template. The dictionary value is another dictionary, containing all the template Data Object IDs as keys, and the template Data Objects as values. */
@property (nonatomic, copy, readonly, nonnull) NSDictionary<NSString *, NSDictionary<NSString *, NSString *> *> *unreservedTemplates;


// Data Objects for Additional Data Field

/** Bill Number (Data Object ID "01" of template ID "62") */
@property (nonatomic, copy, readonly, nonnull) NSString *billNumber;
/** Mobile Number (Data Object ID "02" of template ID "62") */
@property (nonatomic, copy, readonly, nonnull) NSString *mobileNumber;
/** Store Label (Data Object ID "03" of template ID "62") */
@property (nonatomic, copy, readonly, nonnull) NSString *storeLabel;
/** Loyalty Number (Data Object ID "04" of template ID "62") */
@property (nonatomic, copy, readonly, nonnull) NSString *loyaltyNumber;
/** Reference Label (Data Object ID "05" of template ID "62") */
@property (nonatomic, copy, readonly, nonnull) NSString *referenceLabel;
/** Customer Label (Data Object ID "06" of template ID "62") */
@property (nonatomic, copy, readonly, nonnull) NSString *customerLabel;
/** Terminal Label (Data Object ID "07" of template ID "62") */
@property (nonatomic, copy, readonly, nonnull) NSString *terminalLabel;
/** Purpose of Transaction (Data Object ID "08" of template ID "62") */
@property (nonatomic, copy, readonly, nonnull) NSString *purposeOfTransaction;
/** Additional Consumer Data Request (Data Object ID "09" of template ID "62") */
@property (nonatomic, copy, readonly, nonnull) NSString *additionalConsumerDataRequest;
/** A dictionary of all Payment System Specific Templates (ID "50" to "99" of template ID "62") contained in the QR Code. The dictionary key is the ID of the Unreserved Template. The dictionary value is another dictionary, containing all the template Data Object IDs as keys, and the template Data Objects as values. */
@property (nonatomic, copy, readonly, nonnull) NSDictionary<NSString *, NSDictionary<NSString *, NSString *> *> *paymentSystemSpecificTemplates;


// Data Objects for Merchant Information

/** Language Preference (Data Object ID "00" of template ID "64") */
@property (nonatomic, copy, readonly, nonnull) NSString *merchantLanguagePreference;
/** Merchant Name - Alternate Language (Data Object ID "01" of template ID "64") */
@property (nonatomic, copy, readonly, nonnull) NSString *merchantNameAlternateLanguage;
/** Merchant City - Alternate Language (Data Object ID "02" of template ID "64") */
@property (nonatomic, copy, readonly, nonnull) NSString *merchantCityAlternateLanguage;


@end
