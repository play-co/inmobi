#import <Foundation/Foundation.h>

// The type of available virtual goods, as acquired, consumed or exchanged by the user.
typedef enum {
    // Consumable type of virtual goods.
    IMVirtualGoodsConsumable = 1,
    
    // Durable type of virtual goods.
    IMVirtualGoodsDurable = 2,
    
    // Personalizable type of virtual goods.
    IMVirtualGoodsPersonalization = 3,
    
    // Other type of virtual goods.
    IMVirtualGoodsOther = 4,
} IMVirtualGoods;

// This class collects analytics for a publisher's app.Publishers can record various aspects of the usage of
// their app, like section/level statistics and virtual goods as acquired,consumed or exchanged by the user
// for section/level progression.
@interface InMobiAnalytics : NSObject

/**
 * Call this method in your AppDelegate's applicationDidBecomeActive: method.
 * This method is idempotent endSession has been called.
 * @note All other methods should be called only after a session has been initialized, otherwise they don't have any effect
 * @param additionalParams Optional NSDictionary. This dictionary can have value type as (NSNumber,NSString) only.
 */
+(void) startSessionWithParams:(NSDictionary *)additionalParams;

+(void) startSession;

/**
 * Call this method in your AppDelegate's applicationWillResignActive: method.
 * This method will fail silently if an active session does not exist.
 * First create an active session by calling startSession: method .
 * @param additionalParams Optional NSDictionary. This dictionary can have value type as (NSNumber,NSString) only.
 */
+(void) endSessionWithParams:(NSDictionary *)additionalParams;

+(void) endSession;

/**
 * Call this method when the user has started or re-started a section.
 * @param sectionId An integer to represent the beginning section.
 * @param sectionName A name string for the beginning section.
 * @param additionalParams Optional NSDictionary object. This dictionary can have value type as (NSNumber,NSString) only.
 * @note First create an active session by calling startSession: method .
 */
+(void) beginSection:(int)sectionId sectionName:(NSString *)sectionName params:(NSDictionary *)additionalParams;

+(void) beginSection:(int)sectionId sectionName:(NSString *)sectionName;

/**
 * Call this method when the user has completed,failed or finished a section.
 * @param sectionId An integer for the ending session.
 * @param sectionName A name string for the ending session.
 * @param additionalParams Optional NSDictionary object. This dictionary can have value type as (NSNumber,NSString) only.
 * @note First create an active session by calling startSession: method .
 */
+(void) endSection:(int)sectionId sectionName:(NSString *)sectionName params:(NSDictionary *)additionalParams;

+(void) endSection:(int)sectionId sectionName:(NSString *)sectionName;

/**
 * Call this method if the user has purchased, or acquired an item during a section. This can happen in multiple scenarios,for
 * example: if user earned certain helper items during a section.
 * @param itemName The acquired item's name.
 * @param itemType The type of virtual goods as acquired by the user. For a list of values, see IMVirtualGoods.
 * @param itemCount The total no. of the specific virtual goods as acquired by the user.
 * @param currencyAmount The amount paid by the user to acquire the item.
 * @param currencyType The type of currency paid by the user, eg. USD,EUR etc. Pass nil if not applicable.
 * @param sectionId The current section the user is under.
 * @param additionalParams Optional NSDictionary object. This dictionary can have value type as (NSNumber,NSString) only.
 * @note First create an active session by calling startSession: method .
 */
+(void) acquireItem:(NSString *)itemName type:(IMVirtualGoods)itemType itemCount:(int)itemCount amount:(float)amount currencyType:(NSString *)currencyType sectionId:(int)sectionId params:(NSDictionary *)additionalParams;

/**
 * Call this method when the user has consumed an item during a section.This can happen in multiple scenarios, for exmaple:
 * If the user has consumed an item to earn reward points, or skip an unfinished section.
 * @param itemName The consumed item's name.
 * @param itemType The type of virtual goods as consumed by the user. For a list of values, see IMVirtualGoods.
 * @param itemCount The total no. of the specific virtual goods as consumed by the user.
 * @param sectionId The current section the user is under.
 * @param additionalParams Optional NSDictionary object. This dictionary can have value type as (NSNumber,NSString) only.
 * @note First create an active session by calling startSession: method .
 */
+ (void) consumeItem:(NSString *)itemName type:(IMVirtualGoods)itemType itemCount:(int)itemCount sectionId:(int)sectionId params:(NSDictionary *)additionalParams;

/**
 * Call this method if user wants to acquire a certain virtual good, in exchange of other.
 * @param consumeItemName The name of item user wants to exchange.
 * @param consumeItemType The type of virtual goods as exchanged by the user. For a list of values, see IMVirtualGoods.
 * @param consumeItemCount The total no. of the specific virtual goods as exchanged by the user.
 * @param acquireItemName The name of item acquired by the user.
 * @param acquireitemType The type of virtual goods as acquire by the user. For a list of values, see IMVirtualGoods.
 * @param acquireItemCount The total no. of the specific virtual goods as acquired by the user.
 * @param sectionId The current section the user is under.
 * @param additionalParams Optional NSDictionary object. This dictionary can have value type as (NSNumber,NSString) only.
 * @note First create an active session by calling startSession: method .
 */
+(void) exchangeItem:(NSString *)consumeItemName consumeItemType:(IMVirtualGoods)consumeItemType consumeItemCount:(int)consumeItemCount acquireItemName:(NSString *)acquireItemName acquireitemType:(IMVirtualGoods)acquireitemType acquireItemCount:(int)acquireItemCount sectionId:(int)sectionId params:(NSDictionary *)additionalParams;

/**
 * Call this method if you want to track custom events as happening during a section.
 * @param eventName The custom event name.
 * @param additionalParams Optional NSDictionary to be provided by you.
 * @note First create an active session by calling startSession: method .
 */
+(void) trackCustomEvent:(NSString *)eventName params:(NSDictionary *)additionalParams;

+(void) trackCustomEvent:(NSString *)eventName;

/**
 * Reports the Application Custom Goals to InMobi Ad Tracker.
 * This is a non blocking API (returns immediately), and performs the
 * reporting job in the background.
 * When a goal is reported, it is made sure that it reaches InMobi Ad Tracker
 * server whenever the device is connected to internet. You can report
 * different goals without worrying about the internet connection.
 * @param goalName Your custom goal name.
 */
+(void) reportCustomGoal:(NSString *)goalName;

@end