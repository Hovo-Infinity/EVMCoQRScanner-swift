//
//  AdditionalData.h
//  ErrorObjCinSwift
//
//  Created by MasterCard on 14/9/17.
//  Copyright © 2017 MasterCard. All rights reserved.
//

#import "AbstractData.h"

@class UnrestrictedData;
@interface AdditionalData : AbstractData


/// Bill number
@property (retain,nullable) NSString* billNumber;

/// Mobile number
@property (retain,nullable) NSString* mobileNumber;

/// Store id
@property (retain,nullable) NSString* storeId;

/// Loyalty number
@property (retain,nullable) NSString* loyaltyNumber;

/// Reference id
@property (retain,nullable) NSString* referenceId;

/// Consumer id
@property (retain,nullable) NSString* consumerId;

/// Terminal id
@property (retain,nullable) NSString* terminalId;

/// Purpose
@property (retain,nullable) NSString* purpose;

/// Purpose
@property (retain,nullable) NSString* additionalConsumerDataRequest;

/**
 * Store value at any empty tag in dynamically allocatable range
 *
 * @param value the value to assign
 * @return updated AdditionalData
 * @note Throws UnknownTagException when the tag number is invalid,
 * LimitException when all tags in range are already filled
 */
- (BOOL) setDynamicTag:(UnrestrictedData* _Nonnull) value error:(NSError* _Nullable *_Nullable) error;
@end

