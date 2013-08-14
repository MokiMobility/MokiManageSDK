//
//  MasterViewController.h
//  MokiManage SDK
//
//  Created by Kory Calmes on 12/19/12.
//  Copyright (c) 2012 MokiMobility, Inc. All rights reserved.
//
//  This header is included in the project for the settings views only.
//  There is no need to call any of these methods directly.
//

#import <UIKit/UIKit.h>

@protocol SettingsViewsDelegate <NSObject>

@required
- (void)finishedEditingSettings;
@end


@class DetailViewController;
@class EnrollmentViewController;

@interface MasterViewController : UITableViewController

@property (strong, nonatomic) id rootAppController;
@property (strong, nonatomic) EnrollmentViewController *enrollmentViewController;
@property (strong, nonatomic) DetailViewController *detailViewController;
@property (strong, nonatomic) DetailViewController *originalDetailViewController;
@property (nonatomic, weak) id<SettingsViewsDelegate> delegate;

- (void)finishedEditing;

@end
