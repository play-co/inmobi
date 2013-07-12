/**
 * IMAnalyticsBanner.h
 * @author: InMobi
 * Copyright (c) 2012 InMobi Pte Limited. All rights reserved.
 * 
 */

#import "IMAnalyticsInterstitial.h"
#import "IMAnalyticsActionResponse.h"
@protocol IMAnalyticsBannerDelegate;
/**
 This class is used to show a banner action to the user.
 */
@interface IMAnalyticsBannerView : UIView

/**
 * @param appId. The slot id for serving interstitial ads. Must not be NULL.
 * @param slotId The publisher id, as obtained from inmobi.com .Must not be NULL.
 */
- (id) initWithFrame:(CGRect)frame appId:(NSString *)appId slotId:(long long)slotId;

/**
 * Makes an action request.
 * This is best to do several seconds before the interstitial is needed to
 * preload its content.
 * @note - Show the action by calling the presentFromRootViewController: method.
 */

- (void)loadAction;
 
#pragma mark Post-Request
/**
 * @param action The action which was successfully completed by the user.
 */

/**
 * Optional delegate object that receives state change notifications from this banner object.
 Typically this is a UIViewController instance.
 Set the delegate property of this object to nil in the dealloc method of your UIViewController.
 - (void)dealloc {
 imAdBanner.delegate = nil;
 [imAdBanner release]; imAdBanner = nil;
 [super dealloc];
 }
 */
@property (nonatomic, assign) id<IMAnalyticsBannerDelegate> delegate;

/**
 * Starts or stops the auto refresh of actions.
 * The refresh interval is measured between the completion(success or failure)
 * of the previous action request and start of the next action request. By default,
 * the refresh interval is set to 60 seconds. Setting a new valid refresh
 * interval value will start the auto refresh of action if it is not already
 * started. Use REFRESH_INTERVAL_OFF(defined under IMAdView.h) as the parameter to switch off auto
 * refresh. When auto refresh is turned off, use the loadAction method to
 * manually load new actions. The SDK will not refresh action if the screen is in the
 * background or if the phone is locked.
 */
@property (nonatomic, assign) int refreshInterval;
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

#pragma mark --Deprecated methods

- (id) initWithFrame:(CGRect)frame appId:(NSString *)appId slotId:(long long)slotId rootViewController:(UIViewController *)rootViewController;

@property (nonatomic, retain) UIViewController *rootViewController;
@property (nonatomic,assign) BOOL displayAdTestMode;

@end


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////            Banner View Lifecycle methods   ////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
@class IMAnalyticsBannerView;
@protocol IMAnalyticsBannerDelegate <NSObject>
@optional
/**
 * @param bannerView The BannerView instance which was responsible for calling this method.
 */
- (void)bannerViewDidFinishAction:(IMAnalyticsBannerView *)bannerView;

/**
 * @param bannerView The BannerView instance which was responsible for calling this method.
 * @param error Tne NSError for which the action failed to load.
 */
- (void)bannerView:(IMAnalyticsBannerView *)bannerView didFailActionWithError:(NSError *)error;
/**
 * Callback sent just before when the adView is presenting a full screen view
 * to the user. Use this opportunity to stop animations and save the state of
 * your application in case the user leaves while the full screen view is on
 * screen (e.g. to visit the App Store from a link on the full screen view).
 * @param bannerView The BannerView instance that presents the screen.
 */
- (void)bannerViewWillPresentScreen:(IMAnalyticsBannerView *)bannerView;
/**
 * Callback sent just before dismissing the full screen view.
 * @param bannerView The BannerView instance that dismisses the screen.
 */
- (void)bannerViewWillDismissScreen:(IMAnalyticsBannerView *)bannerView;
/**
 * Callback sent just after dismissing the full screen view.
 * Use this opportunity to restart anything you may have stopped as part of
 * adViewWillPresentScreen: callback.
 * @param bannerView The BannerView instance that dismissed the screen.
 */
- (void)bannerViewDidDismissScreen:(IMAnalyticsBannerView *)bannerView;
/**
 * Callback sent just before the application goes into the background because
 * the user clicked on a link in the ad that will launch another application
 * (such as the App Store). The normal UIApplicationDelegate methods like
 * applicationDidEnterBackground: will immediately be called after this.
 * @param bannerView The BannerView instance that is launching another application.
 */
- (void)bannerViewWillLeaveApplication:(IMAnalyticsBannerView *)bannerView;


@end