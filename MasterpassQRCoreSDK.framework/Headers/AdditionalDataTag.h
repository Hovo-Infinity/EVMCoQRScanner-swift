//
//  AdditionalDataTag.h
//  MasterpassQRCoreSDKV2
//
//  Created by MasterCard on 12/9/17.
//  Copyright © 2017 MasterCard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Tag.h"

/**
 Tags collection for additional data
 */
@interface AdditionalDataTag : NSObject<Tag>

// MARK: - Tags
/**
 Invoice number or bill number
 */
@property(class,nonnull,readonly) TagInfo* TAG_01_BILL_NUMBER;//=TagInfo("01", "^.{1,26}$", false, name: "TAG_01_BILL_NUMBER")
/**
 Mobile number: To be used for top-up or bill payment
 */
@property(class,nonnull,readonly) TagInfo* TAG_02_MOBILE_NUMBER;//=TagInfo("02", "^.{1,26}$", false, name: "TAG_02_MOBILE_NUMBER")
/**
 A distinctive number associated to a Store
 */
@property(class,nonnull,readonly) TagInfo* TAG_03_STORE_ID;//=TagInfo("03", "^.{1,26}$", false, name: "TAG_03_STORE_ID")
/**
 Typically a loyalty card number as provided by store or airline
 */
@property(class,nonnull,readonly) TagInfo* TAG_04_LOYALTY_NUMBER;//=TagInfo("04", "^.{1,26}$", false, name: "TAG_04_LOYALTY_NUMBER")
/**
 Any value as defined by merchant or acquirer in order to identify the transaction
 */
@property(class,nonnull,readonly) TagInfo* TAG_05_REFERENCE_ID;//=TagInfo("05", "^.{1,26}$", false, name: "TAG_05_REFERENCE_ID")
/**
 Typically a subscriber ID for subscription services or student enrollment number etc.
 */
@property(class,nonnull,readonly) TagInfo* TAG_06_CONSUMER_ID;//=TagInfo("06", "^.{1,26}$", false, name: "TAG_06_CONSUMER_ID")
/**
 A distinctive number associated to a Terminal in the store
 */
@property(class,nonnull,readonly) TagInfo* TAG_07_TERMINAL_ID;//=TagInfo("07", "^.{1,26}$", false, name: "TAG_07_TERMINAL_ID")
/**
 Purpose of top-up for Mobile Top-Up use case- Airtime, Data, International Package
 */
@property(class,nonnull,readonly) TagInfo* TAG_08_PURPOSE;//=TagInfo("08", "^.{1,26}$", false, name: "TAG_08_PURPOSE")
/**
 Reserved for definition by Network 1 (Visa)
 */
@property(class,nonnull,readonly) TagInfo* TAG_09_ADDITIONAL_CONSUMER_DATA_REQUEST;//=TagInfo("09", "^.{1,26}$", false, name: "TAG_09")
/**
 Reserved for definition by Network 1 (Visa)
 */
@property(class,nonnull,readonly) TagInfo* TAG_10;//=TagInfo("10", "^.{1,26}$", false, name: "TAG_10")
/**
 Reserved for definition by Network 2 (Mastercard)
 */
@property(class,nonnull,readonly) TagInfo* TAG_11;//=TagInfo("11", "^.{1,26}$", false, name: "TAG_11")
/**
 Reserved for definition by Network 2 (Mastercard)
 */
@property(class,nonnull,readonly) TagInfo* TAG_12;//=TagInfo("12", "^.{1,26}$", false, name: "TAG_12")
/**
 Reserved for definition by Network 3 (NPCI)
 */
@property(class,nonnull,readonly) TagInfo* TAG_13;//=TagInfo("13", "^.{1,26}$", false, name: "TAG_13")
/**
 Reserved for definition by Network 3 (NPCI)
 */
@property(class,nonnull,readonly) TagInfo* TAG_14;//=TagInfo("14", "^.{1,26}$", false, name: "TAG_14")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_15;//=TagInfo("15", "^.{1,26}$", false, name: "TAG_15")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_16;//=TagInfo("16", "^.{1,26}$", false, name: "TAG_16")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_17;//=TagInfo("17", "^.{1,26}$", false, name: "TAG_17")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_18;//=TagInfo("18", "^.{1,26}$", false, name: "TAG_18")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_19;//=TagInfo("19", "^.{1,26}$", false, name: "TAG_19")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_20;//=TagInfo("20", "^.{1,26}$", false, name: "TAG_20")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_21;//=TagInfo("21", "^.{1,26}$", false, name: "TAG_21")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_22;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_23;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_24;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_25;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_26;//=TagInfo("21", "^.{1,26}$", false, name: "TAG_21")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_27;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_28;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_29;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_30;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_31;//=TagInfo("21", "^.{1,26}$", false, name: "TAG_21")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_32;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_33;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_34;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_35;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_36;//=TagInfo("21", "^.{1,26}$", false, name: "TAG_21")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_37;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_38;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_39;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_40;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_41;//=TagInfo("21", "^.{1,26}$", false, name: "TAG_21")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_42;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_43;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_44;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_45;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_46;//=TagInfo("21", "^.{1,26}$", false, name: "TAG_21")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_47;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_48;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")
/**
 Reserved for future use
 */
@property(class,nonnull,readonly) TagInfo* TAG_49;//=TagInfo("22", "^.{1,26}$", false, name: "TAG_22")

/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_50_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_50_UNRESTRICTED_DATA);//=TagInfo("62", "^.{1,99}$", false, name: "TAG_62_ADDITIONAL_DATA_FIELD")
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_51_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_51_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_52_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_52_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_53_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_53_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_54_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_54_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_55_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_55_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_56_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_56_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_57_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_57_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_58_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_58_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_59_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_59_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_60_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_60_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_61_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_61_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_62_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_62_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_63_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_63_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_64_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_64_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_65_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_65_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_66_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_66_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_67_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_67_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_68_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_68_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_69_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_69_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_70_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_70_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_71_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_71_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_72_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_72_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_73_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_73_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_74_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_74_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_75_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_75_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_76_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_76_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_77_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_77_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_78_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_78_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_79_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_79_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_80_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_80_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_81_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_81_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_82_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_82_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_83_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_83_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_84_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_84_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_85_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_85_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_86_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_86_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_87_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_87_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_88_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_88_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_89_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_89_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_90_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_90_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_91_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_91_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_92_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_92_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_93_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_93_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_94_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_94_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_95_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_95_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_96_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_96_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_97_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_97_UNRESTRICTED_DATA);
/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_98_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_98_UNRESTRICTED_DATA);

/**
 Unrestricted Data: Payment System Specific with Global Unique Identifier for Application Identifier AID
 */
@property(class,nonnull,readonly) TagInfo* TAG_99_UNRESTRICTED_DATA NS_SWIFT_NAME(TAG_99_UNRESTRICTED_DATA);

/**
 All tag that belong to this class
 */
@property (readonly, class, nonnull) NSArray<TagInfo*>* allTags;

/**
 Unrestricteddata tag that belong to this class, tag 50 to 99
 */
@property (readonly, class, nonnull) NSArray<TagInfo*>* unrestrictedDataTags;

/**
 Get valid tag info given specific tag in string
 @param name tag name in string
 @return TagInfo if the tag is valid and belong to this class
 */
+ (TagInfo* _Nullable) tagFor:(NSString* _Nonnull) name;

@end
