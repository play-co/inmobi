/**
 * IMLTVPActionResponse.h
 * @author: InMobi
 * Copyright (c) 2012 InMobi Pte Limited. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * An action as received from the server.
 */
@interface IMAnalyticsActionResponse : NSObject 

/**
 * This enum represents the status of action based on the user's interaction.
 */
typedef enum {
    /** Indicates user has accepted the offered action. */
    IMAnalyticsActionStatusAccept = 1,
    /** Indicates user has rejected the offered action. */
    IMAnalyticsActionStatusReject = 2
    
} IMAnalyticsActionStatus;

typedef enum {
    InMobiAnalyticsPingTypeImpression = 1,
    InMobiAnalyticsPingTypeClick = 2,
    InMobiAnalyticsPingTypeGoalSuccess = 3,
    InMobiAnalyticsPingTypeGoalFailure = 4
} InMobiAnalyticsPingType;

/**
 * The status associated with this Action. Refer IMAnalyticsActionStatus for the set of values.
 */
@property(nonatomic,assign) IMAnalyticsActionStatus actionStatus;
/**
 * The type associated with this action.
 */
@property(nonatomic,copy) NSString *actionType;

/**
 * The params which constitute this action.
 */
@property(nonatomic,retain) NSDictionary *actionParams;


@end
