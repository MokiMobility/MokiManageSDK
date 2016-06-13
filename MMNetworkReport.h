//
//  MMNetworkReport.h
//  MokiTest
//
//  Created by Kevin Ray on 11/5/13.
//  Copyright (c) 2013 MokiMobility. All rights reserved.
//

//  Example implimentation:
//
//  MMNetworkReport* networkReport = [MMNetworkReport new];
//  [networkReport addURL:@"ibm.com" checkForString:@"A smarter planet" error:error];
//
//
//  [networkReport runBasicWithCompletionBlock:^(BOOL succeeded){
//      //get all report data in NSDictionary format
//      NSDictionary* dictionaryReport = [networkReport encode];
//    
//      //get individual checks and data
//      NSArray* portList = [networkReport networkChecksForCheckType:MMNetworkCheckTypePortScans];
//      MMNetworkCheck* networkCheck = [portList objectAtIndex:0];
//      NSString* result = networkCheck.result;
//  }];


#import <Foundation/Foundation.h>

typedef enum {
    MMNetworkCheckTypePingDefaultGateway = 0,
    MMNetworkCheckTypePingOutside,
    MMNetworkCheckTypePingMoki,
    MMNetworkCheckTypeDNS,
    MMNetworkCheckTypeURLResponse,
    MMNetworkCheckTypePortScans,
    MMNetworkCheckTypeValidIP
} MMNetworkCheckType;

@interface MMNetworkReport : NSObject <NSStreamDelegate>

@property (strong) MMNetworkReport *myself;

/** The type of report
 
 This value will either be "basic" or "advanced".  Basic runs all the tests once.  Advanced includes duration tests.
 */
@property(nonatomic, strong) NSString *type;

/** The unique identifier of the device
 
 This value will relfect the unique identifier the current device is referenced as within our system.  This will be the UDID of the device if under management or the vendor identifier if not enrolled or if enrolled without MDM.
 */
@property(nonatomic, strong) NSString *device;

/** The platform the report was run on
 
 This value will always return "IOS"
 */
@property(nonatomic, strong) NSString *platform;

/** The time this report was run
 
 This timestamp will update each time a report is run.
 */
@property(nonatomic, strong) NSDate *timestamp;

/** The version of the host application
 
 This value is pulled from the host applications CFBundle.
 */
@property(nonatomic, strong) NSString *appVersion;

/** The version of MokiManage API
 
 */
@property(nonatomic, strong) NSString *sdkVersion;

/** The version of iOS the device is on
 
 */
@property(nonatomic, strong) NSString *osVersion;

/** The location of the device
 
 Location services pinpoint the location of the device when running every report.
 */
@property(nonatomic, strong) NSString *location;

/** The network the device is connected to
 
 networkType will either be "cellular" or "wifi"
 */
@property(nonatomic, strong) NSString *networkType;

/** The IP Address of the device
 
 */
@property(nonatomic, strong) NSString *ipAddress;

/** An array of MMNetworkReport objects
 
 The report is comprised of multiple checks which are contained in this array in no particular order.
 */
@property(nonatomic, strong) NSMutableArray *networkChecks;

/** An array of additional URLs to check
 
 Add URLs to this list to have them automatically run
 */
@property(nonatomic, strong) NSMutableArray *appDefinedURLs;

/** A method to manually trigger an advanced report with a callback
 
 Calling run will run a network report and report the results to the server tied to the enrolled user and then triggers the callback block to allow the developer to implement additional logic based on the results.
 The report will be saved locally and sent to the MokiManage server
 */
- (void)runWithCompletionBlock:(void (^)(BOOL succeeded))block;

/** Adds URL to list of URLs to check and report on
 
 This method takes a URL and a string to check in the response body.
 
 @param url URL as a string which will be added to the network check and report.  Include "http://" or "https://" in the URL
 @param checkString String to check in the response body from the specified URL.  Can be nil.
 */
-(void) addURL:(NSString*)url checkForString:(NSString*)checkString error:(NSError**)error;


/** Get network checks of a certain type
 
 This method takes a NetworkCheckType and returns a list of MMNetworkChecks associtated with the type requested.  Pings will only have one returned in the list where URL responses and port scans will have multiple.
 
 @param checkType enum NetworkCheckType used to identify what MMNetworkChecks to return
 */
-(NSArray*) networkChecksForCheckType:(MMNetworkCheckType)checkType;


/** Downloads history from server
 
 This can be called if the app was deleted and lost the localy saved history. Downloading the history replaces the currently saved history on the device with the history retrieved from the server.
 
 */
+(void) downloadAndReplaceReportHistory:(void (^)(BOOL succeeded))block;

@end
