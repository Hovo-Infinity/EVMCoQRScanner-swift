//
//  EURErrors.h
//  EURMerchantQrCodeReader
//
//  Copyright © 2018 Euromeric. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const EURErrorDomain;

//* A List of errors that can be encountered when trying to read QR Codes using the EURScanViewController. */
NS_ERROR_ENUM(EURErrorDomain) {
    
    //* Indicates that the read QR Code is not an EMV Compliant Merchant QR Code. */
    EURErrorInvalidQRCode = 100,
    
    //* Indicates that the camera could not be initialized to read QR Codes. This can possibly be because the app was refused camera access by the user. */
    EURErrorCameraCode = 101,
};

