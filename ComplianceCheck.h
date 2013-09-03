//
//  ComplianceCheck.h
//  MokiManageAPI
//
//  Created by Kory Calmes on 8/19/13.
//  Copyright (c) 2013 Moki Mobility. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ComplianceCheck : NSObject

@property(nonatomic, strong) NSNumber *compliant;
@property(nonatomic, strong) NSString *key;
@property(nonatomic, strong) NSArray *variables;
@property(nonatomic, strong) NSString *status;
@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *message;
@property(nonatomic, strong) NSString *moreInfo;
@property(nonatomic, strong) NSNumber *score;
@property(nonatomic, strong) NSArray *complianceTypes;
@property(nonatomic, strong) NSArray *vulnerabilityTypes;

- (NSDictionary *)encode;
+ (ComplianceCheck *)decode:(NSDictionary *)dictionary;

@end
