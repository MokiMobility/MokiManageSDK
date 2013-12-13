//
//  MMNetworkCheck.h
//  MokiTest
//
//  Created by Kevin Ray on 11/6/13.
//  Copyright (c) 2013 Kory Calmes. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MMNetworkCheck : NSObject
/** The unique key for this specific check
 
 A unique key is given to each check so it can be identified across platforms.
 */
@property(nonatomic, strong) NSString *key;

/** The result of the check
 
 This result can be pass, fail, or warn based on the threshholds defined by the enrolled tenant.  If unenrolled, default threshholds will be used.
 */
@property(nonatomic, strong) NSString *result;

/** The user friendly title of the check
 
 The user friendly title of the check used in our front end graphical interface that describes what the check represents.
 */
@property(nonatomic, strong) NSString *title;

/** Response time of the check
 
 How long ping took to respond back in seconds.
 */
@property(nonatomic, strong) NSNumber* responseTime;

/** URL that was hit for the check
 
 */
@property(nonatomic, strong) NSString *url;

/** Max latency of the check
 
 Longest time a ping took to hit url in seconds.  Used only on advanced checks.
 */
@property(nonatomic, strong) NSNumber *maxLatency;

/** Average latency of the check
 
 Average time a ping took to hit url in seconds.  Used only on advanced checks.
 */
@property(nonatomic, strong) NSNumber *avgLatency;

/** Missing packets from check
 
 How many pings never responded back.  Used only on advanced checks.
 */
@property(nonatomic, strong) NSNumber *missingPackets;

/** Response code of the check
 
 Response code returned in the response
 */
@property(nonatomic, strong) NSNumber* responseCode;

/** Request method
 
 Will be "GET" or "POST"
 */
@property(nonatomic, strong) NSString *method;

/** Port checked
 
 When scanning ports this will be the port checked for the given url
 */
@property(nonatomic, strong) NSNumber *port;

/** IP Address
 
 IP Address of the wifi network for the device
 */
@property(nonatomic, strong) NSString *ipAddress;


- (NSDictionary *)encode;
+ (MMNetworkCheck *)decode:(NSDictionary *)dictionary;

@end

