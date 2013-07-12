/**
 * IMAnalyticsInterstitial.h
 * @author: InMobi
 * Copyright (c) 2012 InMobi Pte Limited. All rights reserved.
 * 
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IMAnalyticsDemogInfo.h"
#import "IMAnalyticsActionResponse.h"

@protocol IMAnalyticsInterstitialDelegate;

/**
 * This is a full-screen action shown to the user.
 */
@interface IMAnalyticsInterstitial : NSObject

/**
 * Defines the available interstitial states.
 */
typedef enum {
    /**
     * The default state of an interstitial.
     * If an interstitial actionrequest fails, or if the user dismisses the interstitial,
     * the state will be changed back to init.
     */
	IMAnalyticsInterstitialStateInit,
    /**
     * Indicates that an interstitial actionrequest is in progress.
     */
    IMAnalyticsInterstitialStateLoading,
    /**
     * Indicates that an interstitial actionis ready to be displayed.
     * An interstitial actioncan be displayed only if the state is ready.     
     * You can call presentFromRootViewController: to display this ad.
     */
    IMAnalyticsInterstitialStateReady,
    /**
     * Indicates that an interstitial actionis displayed on the user's screen.
     */
    IMAnalyticsInterstitialStateActive,
    /**
     * Indicates that the user has accepted the action, 
     * and the interstitial screen has been dismissed.
     * You must call actionFailed: or actionCompleted: to make this interstitial
     * change state to init.
     */
    IMAnalyticsInterstitialStateAwaitingAction
    
} IMAnalyticsInterstitialState;

/**
 * @param appId. The slot id for serving interstitial ads. Must not be NULL.
 * @param slotId The publisher id, as obtained from inmobi.com .Must not be NULL.
 */
- (id) initWithAppId:(NSString *)appId slotId:(long long)slotId;
/**
 * Makes an action request.
 * This is best to do several seconds before the interstitial is needed to
 * preloactionits content.
 * @note - Show the action by calling the presentFromRootViewController: method.
 */

- (void)loadAction;

#pragma mark Post-Request

/**
 * Use this method to register a specific ping.
 * See InMobiAnalyticsPingType declared in IMAnalyticsPActionResponse.h for the list of available values.
 */
- (void)registerPing:(InMobiAnalyticsPingType)pingType;
/**
 * Presents the interstitial action that takes over the entire screen until the
 * user dismisses it.
 * This has no effect unless interstitialState returns kIMInterstitialAdStateReady and/or the delegate's interstitialDidReceiveAd:
 * has been received.
 * @note - After the interstitial has been removed, the delegate's
 * interstitialDidDismissScreen: will be called.
 */

- (void)presentAction:(BOOL)_animated;

/**
 * @param action The action which was successfully completed by the user.
 */

/**
 * Optional delegate object that receives state change notifications from this interstitial object.
 Typically this is a UIViewController instance.
 Set the delegate property of this object to nil in the dealloc method of your UIViewController.
 - (void)dealloc {
 imAdInterstitial.delegate = nil;
 [imAdInterstitial release]; imAdInterstitial = nil;
 [super dealloc];
 }
 */
@property ( nonatomic, assign) id<IMAnalyticsInterstitialDelegate> delegate;

/**
 * Returns the state of the interstitial ad. The delegate's
 * interstitialDidFinishRequest: will be called when this switches from the IMAnalyticsInterstitialStateInit state  
 * to the IMAnalyticsInterstitialStateReady state.
 */
@property (nonatomic,assign,readonly) IMAnalyticsInterstitialState state;

/**
 * You can obtain your App ID in the Publisher section by logging in to www.inmobi.com.
 * @description must be not-null.
 */
@property ( nonatomic, copy) NSString *imAppId;

/**
 * You can obtain your App ID in the Publisher section by logging in to www.inmobi.com.
 * @description must be not-null.
 */
@property ( nonatomic, assign) long long slotId;

/**
 * For future purpose.
 */
@property (nonatomic,retain) IMAnalyticsDemogInfo *demogInfo;
/**
 * Call this method to remove a specific NSNotification.
 * @param observer The NSObject which should be removed from the Notification center.Must not be NULL.
 * @param action The NSNotification name to be removed.Must not be NULL.
 * @param selector The SEL on which NSNotification callback will be delivered.Must not be NULL.
 * @exception NSInvalidArgumentException If a NULL value is passed.
 */
- (void)addObserver:(NSObject *)observer forActionName:(NSString *)action
       withSelector:(SEL)selector;
/**
 * Call this method to remove a specific NSNotification.
 * Calling this method twice to remove the same action fails silently.
 * @param observer The NSObject which should be removed from the Notification center.Must not be NULL.
 * @param action The NSNotification name to be removed.Must not be NULL.
 * @exception NSInvalidArgumentException If a NULL value is passed.
 */
- (void)removeObserver:(NSObject *)observer forAction:(NSString *)action;
/**
 * Call this method to remove the observer from receiving all NSNotifications.
 * Calling this method twice to remove the same action fails silently.
 * @param observer The NSObject which should be removed from the Notification center. Must not be NULL.
 * @exception NSInvalidArgumentException If a NULL value is passed.
 */
- (void)removeObserver:(NSObject *)observer;

#pragma mark --Deprecated methods

- (id) initWithAppId:(NSString *)appId slotId:(long long)slotId
  rootViewController:(UIViewController *)rootViewController;

@property (nonatomic, retain) UIViewController *rootViewController;
@property (nonatomic,assign) BOOL displayAdTestMode;

@end

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////            Interstitial View Lifecycle methods   ////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

@protocol IMAnalyticsInterstitialDelegate <NSObject>

#pragma mark interstitial Request Lifecycle delegate callbacks
@optional
/**
 * Sent when an interstitial action request succeeded. 
 * @param interstitial - The interstitial action that was loaded.
 */

- (void)interstitialDidFinishActionRequest:(IMAnalyticsInterstitial *)interstitial;
/**
 * @param interstitial - The interstitial action that was loaded.
 * @param jsonString The JSON NSString as received in the action response.
 */
- (void)interstitialDidFinishCustomActionRequest:(IMAnalyticsInterstitial *)interstitial
        withData:(NSString *)data;
/**
 * Sent when an interstitial action request completed without an interstitial to show.
 * @param interstitial - The interstitial action that failed to load.
 * @param error - The error that occurred during loading.
 */

- (void)interstitial:(IMAnalyticsInterstitial *)interstitial
didFailToReceiveActionWithError:(NSError *)error;

#pragma mark Display-Time Lifecycle delegate callbacks

/**
 * Sent just before presenting an interstitial. After this method finishes, the
 * interstitial will animate on to the screen. Use this opportunity to stop
 * animations and save the state of your application.
 * @param interstitial - The interstitial action that will be presented to the user.
 */

- (void)interstitialWillPresentAction:(IMAnalyticsInterstitial *)interstitial;

/**
 * Sent when an interstitial action fails to present a full screen to the user.
 * This will generally occur if an interstitial is not in the kIMInterstitialAdStateReady state.
 * See IMAdInterstitial.h for a list of states.
 * @param interstitial - The interstitial action that failed to present screen.
 * @param error - The error that occurred during loading.
 * @note - An interstitial actioncan be shown only once.
 * After dismissal, you must call loadRequest: again and wait for this actionrequest to succeed.
 */
- (void)interstitial:(IMAnalyticsInterstitial *)interstitial didFailToPresentActionWithError:(NSError *)error;

/**
 * Sent before the interstitial is to be animated off the screen.
 * @param interstitial - The interstitial that will be dismissed from the screen.
 */
- (void)interstitialWillDismissAction:(IMAnalyticsInterstitial *)interstitial;

/**
 * Sent just after dismissing an interstitial and it has animated off the
 * screen.
 * @param interstitial - The interstitial that was dismissed from the screen.
 */
- (void)interstitialDidDismissAction:(IMAnalyticsInterstitial *)interstitial;
/**
 * Sent just before leaving the context of the existing application.
 * The UIApplication delegate methods will be called after this method.
 * @param interstitial - The interstitial that was dismissed from the screen.
 */
- (void)interstitialWillLeaveApplication:(IMAnalyticsInterstitial *)interstitial;
@end

