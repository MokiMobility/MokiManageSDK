//
//  ComplianceReport.h
//  MokiManageAPI
//
//  Created by Kory Calmes on 8/19/13.
//  Copyright (c) 2013 Moki Mobility. All rights reserved.
//

#import <Foundation/Foundation.h>

#define REPORT_COMPLETE_NOTIFICATION @"ReportCompleteNotification"

@interface ComplianceReport : NSObject

@property(nonatomic, strong) NSString *id;

/** The unique identifier of the device
 
 This value will relfect the unique identifier the current device is referenced as within our system.  This will be the UDID of the device if under management or the vendor identifier if not enrolled or if enrolled without MDM.
 */
@property(nonatomic, strong) NSString *device;

/** The last time a report was run
 
 This timestamp will update each time a report is run.
 */
@property(nonatomic, strong) NSDate *timestamp;

/** The overall risk score of the report
 
 The risk score is a sumation of each score on each ComplianceCheck found in the complianceChecks array.
 */
@property(nonatomic, strong) NSNumber *riskScore;

/** The platform the report was run on
 
 This value will always return "IOS"
 */
@property(nonatomic, strong) NSString *platform;

/** The operating system version of the current device
 
 This value reflects the current operating system by quering the UIDevice singleton [UIDevice currentDevice].
 */
@property(nonatomic, strong) NSString *osVersion;

/** The version of the host application
 
 This value is pulled from the host applications CFBundle.
 */
@property(nonatomic, strong) NSString *appVersion;

/** The location of the device
 
 Location services pinpoint the location of the device when running every report.
 */
@property(nonatomic, strong) NSString *location;

/** A boolean defining overall compliance
 
 An NSNumber containing a boolean that represents whether or not the current report is compliant.  If any of the complianceChecks failed the compliance test this value will be false, otherwise, it will be true, verifying overall compliance.
 */
@property(nonatomic, strong) NSNumber *compliant;

/** An array of ComplianceCheck objects
 
 The report is comprised of multiple checks which are contained in this array in no particular order.
 */
@property(nonatomic, strong) NSMutableArray *complianceChecks;

/** A singleton for the most recent ComplianceReport
 
 Each automatic report is run on this singleton so it will contain the most recent report at any given time.  By calling run on this singleton manually, the same will hold true.
 */
+ (id)sharedInstance;

/** A method to manually trigger a report
 
 Calling run will run a compliance report and report the results to the server tied to the enrolled user.
 */
- (void)run;

/** A method to manually trigger a report with a callback
 
 Calling run will run a compliance report and report the results to the server tied to the enrolled user and then triggers the callback block to allow the developer to implement additional logic based on the results.
 */
- (void)runWithCompletionBlock:(void (^)(BOOL succeeded))block;
- (NSDictionary *)encode;

@end
