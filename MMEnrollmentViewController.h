//
//  EnrollmentViewController.h
//  MokiManage SDK
//
//  Created by Kory Calmes on 1/17/13.
//  Copyright (c) 2013 MokiMobility, Inc. All rights reserved.
//
//  This header is included in the project for the settings views only.
//  There is no need to call any of these methods directly.
//

#import <UIKit/UIKit.h>

@interface MMEnrollmentViewController : UITableViewController

@property BOOL submitButtonActionEnroll;

@property (weak, nonatomic) IBOutlet UITableViewCell *enrolledWithCell;
@property (weak, nonatomic) IBOutlet UITextField *enrollmentCodeInputField;
@property (weak, nonatomic) IBOutlet UILabel *statusLabel;
@property (weak, nonatomic) IBOutlet UILabel *partnerLabel;
@property (weak, nonatomic) IBOutlet UILabel *supportLabel;
@property (weak, nonatomic) IBOutlet UILabel *versionLabel;
@property (weak, nonatomic) IBOutlet UILabel *enrollButtonLabel;
@property (unsafe_unretained, nonatomic) IBOutlet UITableViewCell *submitCell;
@property (weak, nonatomic) IBOutlet UITableViewCell *supportNumberCell;

@end
