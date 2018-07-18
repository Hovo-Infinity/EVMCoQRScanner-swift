//
//  LanguageData.h
//  MasterpassQRCoreSDKV2
//
//  Created by MasterCard on 21/9/17.
//  Copyright © 2017 MasterCard. All rights reserved.
//

#import "AbstractData.h"

/// Class to store the language data
@interface LanguageData : AbstractData

/// Language Preference
@property (retain,nullable) NSString* languagePreference;

/// Alternate Language Merchant Name
@property (retain,nullable) NSString* alternateMerchantName;

/// Alternate Language Merchant City
@property (retain,nullable) NSString* alternateMerchantCity;

@end
