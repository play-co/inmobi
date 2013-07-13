//
//  InMobi.h
//  InMobi Commons.
//
//  Copyright (c) 2013 InMobi Technology Services Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Console logging levels.
 */
typedef enum {
    /**
     * IMLogLevelTypeNone
     *   No logs. (default)
     */
    IMLogLevelTypeNone    = 0,
    /**
     * IMLogLevelTypeDebug
     *   Log level for normal debugging.
     */
    IMLogLevelTypeDebug   = 1,
    /**
     * IMLogLevelTypeVerbose
     *   Log level for verbose (full) debugging.
     */
    IMLogLevelTypeVerbose = 2,
    
} IMLogLevelType;

/**
 * InMobi Device id collection mask.
 */
typedef enum {
    /**
     * IMDeviceIncludeDefaultIds
     *   Use default ids for sdk device id collection. (default)
     */
    IMDeviceIdMaskIncludeDefaultIds = 0,
    /**
     * IMDeviceExcludeODIN1
     *   Exclude odin1 identifier from sdk device id collection.
     */
    IMDeviceIdMaskExcludeODIN1 = 1<<0,
    /**
     * IMDeviceIdMaskExcludeAdvertisingId
     *   Exclude advertiser identifier from sdk device id collection. (iOS 6+)
     */
    IMDeviceIdMaskExcludeAdvertisingId = 1<<1,
    /**
     * IMDeviceIdMaskExcludeVendorId
     *   Exclude vendor identifier from sdk device id collection. (iOS 6+)
     */
    IMDeviceIdMaskExcludeVendorId = 1<<2,
    /**
     * IMDeviceIdMaskExcludeUDID
     * @deprecated
     * @note: This flag is deprecated as sdk does not collect UDID any more.
     *   Exclude udid identifier from sdk device id collection.
     */
    IMDeviceIdMaskExcludeUDID = 1<<3,
    /**
     * IMDeviceIdMaskExcludeFacebookAttributionId
     *   Exclude facebook's attribution id from sdk device id collection.
     */
    IMDeviceIdMaskExcludeFacebookAttributionId = 1<<4,
    
} IMDeviceIdMask;

/**
 * InMobi commons that provides common services to all InMobi SDKs.
 */
@interface InMobi : NSObject {
    
}

+ (void)initialize:(NSString *)publisherId;
/**
 * Set the console logging level for debugging purpose.
 * @param logLevel - Log Level to be set.
 */
+ (void)setLogLevel:(IMLogLevelType)logLevel;

/**
 * This sets the Device Id Mask so as to restrict the Device Tracking not
 * to be based on certain Device Ids.
 * @param deviceIdMask - Device Id Mask to be set.
 */
+ (void)setDeviceIdMask:(IMDeviceIdMask)deviceIdMask;

/**
 * @return the sdk release version.
 */
+ (NSString *)getVersion;

@end
