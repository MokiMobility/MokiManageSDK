//
//  MMAction.h
//  MokiManageAPI
//
//  Created by Kory Calmes on 2/7/14.
//  Copyright (c) 2014 Moki Mobility. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const MMActionTypeCore;
extern NSString *const MMActionTypeAem;
extern NSString *const MMActionTypeAsm;
extern NSString *const MMActionTypeCompliance;
extern NSString *const MMActionTypeNetwork;
extern NSString *const MMActionTypeFollowMe;
extern NSString *const MMActionTypeSecurity;
extern NSString *const MMActionTypeDevice;
extern NSString *const MMActionTypeCustom;

extern NSString *const MMActionStatusUnknown;
extern NSString *const MMActionStatusReceived;
extern NSString *const MMActionStatusFailed;
extern NSString *const MMActionStatusSucceeded;

typedef enum {
    MMActionSourceApns,
    MMActionSourceHeartbeat
} MMActionSource;

@interface MMAction : NSObject

@property(readonly, nonatomic) NSDictionary *payload;
@property(readonly, nonatomic) NSString *type;
@property(nonatomic) NSString *status;
@property(nonatomic) NSString *errorMessage;
@property(nonatomic) NSString *actionId;
@property(nonatomic) NSString *action;
@property MMActionSource source;

- (id)initWithPayload:(NSDictionary *)payload source:(MMActionSource)source;
- (BOOL)isType:(NSString *)type;
- (BOOL)isStatus:(NSString *)status;
- (BOOL)isAction:(NSString *)action;

+ (NSDictionary *)convertToNewMessageFormat:(NSDictionary *)oldMessage;

@end
