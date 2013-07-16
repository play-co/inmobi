#import "InMobi.h"
#import "InMobiAnalytics.h"
#import "InMobiPlugin.h"
#import "JSONKit.h"

@implementation InMobiPlugin

// The plugin must call super dealloc.
- (void) dealloc {
	[InMobiAnalytics endSession];
	[super dealloc];
}

// The plugin must call super init.
- (id) init {
	self = [super init];
	if (!self) {
		return nil;
	}

	return self;
}

- (void) initializeWithManifest:(NSDictionary *)manifest appDelegate:(TeaLeafAppDelegate *)appDelegate {
	@try {
		NSDictionary *ios = [manifest valueForKey:@"ios"];
		NSString *trackingId = [ios valueForKey:@"inMobiKey"];
		[InMobi initialize:trackingId];

		[InMobiAnalytics startSession];

		NSLog(@"{inMobi} Initialized with manifest inMobiKey: '%@'", trackingId);
	}
	@catch (NSException *exception) {
		NSLog(@"{inMobi} Failure to get ios:inMobiKey key from manifest file: %@", exception);
	}
}

- (void) applicationWillTerminate:(UIApplication *)app {
	[InMobiAnalytics endSession];
}

- (void) track:(NSDictionary *)jsonObject {
	@try {
		NSString *eventName = [jsonObject valueForKey:@"eventName"];
		NSDictionary *evtParams = [jsonObject objectForKey:@"params"];
		NSString *jsonString = [evtParams JSONString];
		[InMobiAnalytics trackCustomEvent:eventName params:evtParams];
		NSLOG(@"{inMobi} Delivered event '%@' : action=JSON label=%@", eventName, jsonString);
	}
	@catch (NSException *exception) {
		NSLOG(@"{inMobi} Exception while processing event: ", exception);
	}
}

@end
