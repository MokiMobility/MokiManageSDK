//
//  ComplianceReport.h
//  MokiManageAPI
//
//  Created by Kory Calmes on 8/19/13.
//  Copyright (c) 2013 Moki Mobility. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ComplianceReport : NSObject

@property(nonatomic, strong) NSString *id;
@property(nonatomic, strong) NSString *device;
@property(nonatomic, strong) NSDate *timestamp;
@property(nonatomic, strong) NSNumber *riskScore;
@property(nonatomic, strong) NSString *platform;
@property(nonatomic, strong) NSString *osVersion;
@property(nonatomic, strong) NSString *appVersion;
@property(nonatomic, strong) NSString *location;
@property(nonatomic, strong) NSNumber *compliant;
@property(nonatomic, strong) NSMutableArray *complianceChecks;


+ (id)sharedInstance;
- (void)run;

@end
