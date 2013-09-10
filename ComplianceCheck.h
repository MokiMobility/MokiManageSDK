//
//  ComplianceCheck.h
//  MokiManageAPI
//
//  Created by Kory Calmes on 8/19/13.
//  Copyright (c) 2013 Moki Mobility. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ComplianceCheck : NSObject

/** A boolean defining if the current check is in compliance
 
 An NSNumber containing a boolean that represents whether or not the current check passed on the device and is therfore compliant.
 */
@property(nonatomic, strong) NSNumber *compliant;

/** The unique key for this specific check
 
 A unique key is given to each check so it can be identified across platforms.
 */
@property(nonatomic, strong) NSString *key;

/** The status of the check
 
 This status can be pass, fail, or warn based on the threshholds defined by the enrolled tenant.  If unenrolled, default threshholds will be used.
 */
@property(nonatomic, strong) NSString *status;

/** The user friendly title of the check
 
 The user friendly title of the check used in our front end graphical interface that describes what the check represents.
 */
@property(nonatomic, strong) NSString *title;

/** A message reflecting the results of the check
 
 The message show to the user about the results of the check.  This will explain issues if any exist as well as validate that the given check is not a problem on their device.
 */
@property(nonatomic, strong) NSString *message;

/** A message defining a remedy to a failed check
 
 A message reflecting action items to resolve problems discovered by the check.  This value will be empty if the status of the check is pass and compliant is true accordingly.
 */
@property(nonatomic, strong) NSString *moreInfo;

/** The score value for the check
 
 This score value also reflects the status of the check.  If a check is compliant it will also have a score of 0.0.  Lower is better in compliance checks.  The higher the value of the score, the more at risk the device is.
 */
@property(nonatomic, strong) NSNumber *score;


@property(nonatomic, strong) NSArray *variables;
@property(nonatomic, strong) NSArray *complianceTypes;
@property(nonatomic, strong) NSArray *vulnerabilityTypes;


- (NSDictionary *)encode;
+ (ComplianceCheck *)decode:(NSDictionary *)dictionary;

@end
