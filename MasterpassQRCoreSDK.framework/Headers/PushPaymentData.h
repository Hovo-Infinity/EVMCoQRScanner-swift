//
//  PushPaymentData.h
//  ErrorObjCinSwift
//
//  Created by MasterCard on 14/9/17.
//  Copyright © 2017 MasterCard. All rights reserved.
//

#import "AbstractData.h"

@class MAIData;
@class AdditionalData;
@class LanguageData;
@class UnrestrictedData;

/**
 Class that contain the main data of MPQR
 */
@interface PushPaymentData : AbstractData
{
    NSString* dynamicPOISuffix;
}

/**
 Validate merchant fields
 
 Atleast `1` field related to merchant identifiers should exist.
 
 @note Throws: `MPQRError.missingTag` exception if the none of the merchant tags is found
 */
- (BOOL) validateMerchantIdentifiers:(NSError*_Nullable *_Nullable) error;

/**
 Validate tip fields
 
 Logic for validation is as following:
 1. If the `tipIndicator` tag `PPTag.TAG_55_TIP_INDICATOR` does not exist then tip fields are *valid*
 
 2. If the `tipIndicator` is `TipConvenienceIndicator.promptedToEnterTip` then it
 * Must **NOT** have `PPTag.TAG_56_CONVENIENCE_FEE_FIXED` else it throws `MPQRError.conflictingTag`
 * Must **NOT** have `PPTag.TAG_57_CONVENIENCE_FEE_PERCENTAGE` else it throws `MPQRError.conflictingTag`
 
 3. If the `tipIndicator` is `TipConvenienceIndicator.flatConvenienceFee` then it
 * **MUST** have `PPTag.TAG_56_CONVENIENCE_FEE_FIXED` else it throws `MPQRError.missingTag`
 * Must **NOT** have `PPTag.TAG_57_CONVENIENCE_FEE_PERCENTAGE` else it throws `MPQRError.conflictingTag`
 
 4. If the `tipIndicator` is `TipConvenienceIndicator.percentageConvenienceFee` then it
 * **MUST** have `PPTag.TAG_57_CONVENIENCE_FEE_PERCENTAGE` else it throws `MPQRError.missingTag`
 * Must **NOT** have `PPTag.TAG_56_CONVENIENCE_FEE_FIXED` else it throws `MPQRError.conflictingTag`
 
 5. Else tip fields are valid
 
 @note Throws:
 * `MPQRError.conflictingTag` exception if the tags are conflicting.
 * `MPQRError.missingTag` exception if the required tag is missing.
 */

- (BOOL) validateTipFields:(NSError* _Nullable *_Nullable) error;

/**
 Validate price fields
 
 Logic for validation is as following:
 1. If `transactionAmount` is **not** present and `isDynamic` returns true then tag `PPTag.TAG_54_TRANSACTION_AMOUNT` is missing and it throws `MPQRError.missingTag` exception
 
 2. If `transactionAmount` **is** present and `isDynamic` returns false then tag `PPTag.TAG_54_TRANSACTION_AMOUNT` is conflicting and it throws `MPQRError.conflictingTag` exception
 
 3. Else price fields are valid
 
 @note Throws:
 * `MPQRError.conflictingTag` exception if the tags are conflicting.
 * `MPQRError.missingTag` exception if the required tag is missing.
 */

- (BOOL) validatePriceField:(NSError* _Nullable *_Nullable) error;



//MARK: - Instance methods
/**
 Whether the code this data represents is dynamic or not
 */
- (BOOL) isDynamic;


/**
 Generate the push payment string with new CRC checksum.
 The existing CRC field will be replaced by the new CRC checksum.
 
 @return  Generated string with CRC.
 @note
 * The string is generated with ordered tags, it's not following the original order.
 * This method is **mutating** i.e it will mutate the CRC tag
 */
- (NSString* _Nullable) generatePushPaymentString:(NSError*_Nullable*_Nullable) error;


/**
 Get value with luhn checksum appended with the string representation of underlying value related to the tag.
 
 - Parameter tag: Tag info for which to generate value with luhn checksum
 - Returns: Value with luhn checksum appended
 - Note: This is usually used for merchant id fields
 - Throws: `MPQRError.invalidFormat` exception
 * If the value doesn't exist for the tag
 * If the format of the underlying value is not valid for generating the checksum
 */
- (NSString* _Nullable) valueWithLuhnChecksum:(TagInfo* _Nonnull) tag error:(NSError*_Nullable *_Nullable) error  NS_SWIFT_NAME(valueWithLuhnChecksum(_:));


// MARK: - Convenience Accessors

/// Payload format indicator
@property (retain, nullable) NSString* payloadFormatIndicator;

/// Point of initiation method
@property (retain, nullable) NSString*  pointOfInitiationMethod;

/// Merchant identifier Visa with tag `02`
@property (retain, nullable) NSString*  merchantIdentifierVisa02;

/// Merchant identifier Visa with tag `03`
@property (retain, nullable) NSString*  merchantIdentifierVisa03;

/// Merchant identifier MasterCard with tag `04`
@property (retain, nullable) NSString*  merchantIdentifierMastercard04;

/// Merchant identifier MasterCard with tag `05`
@property (retain, nullable) NSString*  merchantIdentifierMastercard05;


/// Merchant identifier NPCI with tag `06`
@property (retain, nullable) NSString*  merchantIdentifierNPCI06;

/// Merchant identifier NPCI with tag `07`
@property (retain, nullable) NSString*  merchantIdentifierNPCI07;

/**
 Merchant identifier (EMVCo)IFSCCode
 */
@property(retain, nullable) NSString* merchantIdentifierIFSCCODE08;
/**
 Merchant identifier (Discover)
 */
@property(retain, nullable) NSString* merchantIdentifierDISCOVER09;
/**
 Merchant identifier (Discover)
 */
@property(retain, nullable) NSString* merchantIdentifierDISCOVER10;
/**
 Merchant identifier (Amex)
 */
@property(retain, nullable) NSString* merchantIdentifierAMEX11;
/**
 Merchant identifier (Amex)
 */
@property(retain, nullable) NSString* merchantIdentifierAMEX12;
/**
 Merchant identifier (JCB)
 */
@property(retain, nullable) NSString* merchantIdentifierJCB13;
/**
 Merchant identifier (JCB)
 */
@property(retain, nullable) NSString* merchantIdentifierJCB14;
/**
 Merchant identifier (UnionPay)
 */
@property(retain, nullable) NSString* merchantIdentifierUNIONPAY15;
/**
 Merchant identifier (UnionPay)
 */
@property(retain, nullable) NSString* merchantIdentifierUNIONPAY16;

/**
 Get MAIT Data for some tag
 @param tagString Tag to get the value
 @return The value if it is available
 */
- (MAIData* _Nullable) getMAIDataForTagString:(NSString* _Nonnull) tagString error:(NSError*_Nullable*_Nullable) error;

/**
 Get MAI Data for some tag
 @param tagString Tag to be set
 @param data The value to be set
 */
- (BOOL) setMAIDataForTagString:(NSString* _Nonnull) tagString data:(MAIData* _Nonnull) data error:(NSError*_Nullable*_Nullable) error;

/// Merchant category code
@property (retain, nullable) NSString*  merchantCategoryCode;

/// Transaction currency code
@property (retain, nullable) NSString*  transactionCurrencyCode;

/// Transaction amount
@property (retain, nullable) NSString*  transactionAmount;

/// Tip or convenience indicator
@property (retain, nullable) NSString*  tipOrConvenienceIndicator;

/// Value of convenience fee fixed
@property (retain, nullable) NSString*  valueOfConvenienceFeeFixed;

/// Value of convenience fee percentage
@property (retain, nullable) NSString*  valueOfConvenienceFeePercentage;

/// Country code
@property (retain, nullable) NSString*  countryCode;

/// Merchant name
@property (retain, nullable) NSString*  merchantName;

/// Merchant city
@property (retain, nullable) NSString*  merchantCity;

/// Postal code
@property (retain, nullable) NSString*  postalCode;

/// Additional data
@property (retain, nullable) AdditionalData*  additionalData;

/// Language Data
@property (retain, nullable) LanguageData*  languageData;

/// CRC
@property (retain, nullable) NSString*  crc;

/**
 Get Unreserved Unrestricted Data for some tag
 @param tagString Tag to get the value
 @return The value if it is available
 */
- (UnrestrictedData* _Nullable) getUnreservedDataForTagString:(NSString* _Nonnull) tagString error:(NSError*_Nullable*_Nullable) error;

/**
 Set Unreserved Unrestricted Data for some tag
 @param tagString Tag to be set
 @param data The value to be set
 */
- (BOOL) setUnreservedDataForTagString:(NSString* _Nonnull) tagString data:(UnrestrictedData* _Nonnull) data error:(NSError*_Nullable*_Nullable) error;

/**
 Set MAI Data for some tag without specifying the tag, the tag will be automatically assign
 
 @note If the tags are all taken, it will throw error as data cannot be set

 @param value The value to be set
 */
- (BOOL) setDynamicMAIDTag:(MAIData* _Nonnull) value error:(NSError* _Nullable *_Nullable) error;

/**
 Set Unrestricted Data for some tag without specifying the tag, the tag will be automatically assign
 
 @note If the tags are all taken, it will throw error as data cannot be set
 
 @param value The value to be set
 */- (BOOL) setDynamicUnrestrictedTag:(UnrestrictedData* _Nonnull) value error:(NSError* _Nullable *_Nullable) error;

@end

