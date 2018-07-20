//
//  EURScanViewController.h
//  EURMerchantQrCodeReader
//
//  Copyright © 2018 Euromeric. All rights reserved.
//

#import <UIKit/UIKit.h>

@class EURScanViewController;
@class EURMerchantQrCodeObject;


/** The delegate of an EURScanViewController implements this protocol to receive callbacks when a QR Code is read or when an error occurs. */
@protocol EURScanViewControllerDelegate

@required

/**
 @brief Called when a Scan View Controller successfully read and parsed a merchant QR Code.
 
 The presenting view controller should dismiss the Scan View Controller when receiving this callback. The Scan View Controller is not reusable.
 
 @param scanViewController The Scan View Controller that read the merchant QR Code.
 @param merchantQrCodeObject The object containing all the information from the read QR Code.
 @param validCRC Indicates if the checksum (CRC) of the QR Code was valid. If the checksum is invalid, absent or not the last field of the QR Code (as specified in EMV Documentation), the value will be NO.
 */
- (void)scanViewController:(nonnull EURScanViewController *)scanViewController successfullyScanned:(nonnull EURMerchantQrCodeObject*)merchantQrCodeObject withValidCRC:(BOOL)validCRC;

/**
 @brief Called when a Scan View Controller encountered an error.
 
 The presenting view controller should dismiss the Scan View Controller when receiving this callback. The Scan View Controller is not reusable.
 
 @param scanViewController The Scan View Controller that encountered the error.
 @param error The error encountered. Used error codes can be found in EURErrors.h.
 */
- (void)scanViewController:(nonnull EURScanViewController *)scanViewController finishedWithError:(nonnull NSError*)error;

@end

/**
 @brief The view controller used to read and parse information contained in a EMV Compliant Merchant QR Code.
 
 The view controller can be presented modally or on a navigation stack. It must be instanciated by code (Storyboards not supported at the moment).
 
 If the view controller is to be presented modally, it is recommended to embed it in a UINavigationController. You should also provide a mean of return (cancel button) so that the user is not trapped in the modal view controller.
 */
@interface EURScanViewController : UIViewController

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 @brief Initialization of EURScanViewController MUST be done with this initializer.
 
 @param delegate An object that conforms to the EURScanViewControllerDelegate protocol. The delegate will receive callbacks when the Scan View Controller reads a QR Code or when it encounter an error. The delegate is not strongly retained by the Scan View Controller.
 
 @return An initialized EURScanViewController.
 */
- (nonnull instancetype)initWithDelegate:(id<EURScanViewControllerDelegate>)delegate;

@end
