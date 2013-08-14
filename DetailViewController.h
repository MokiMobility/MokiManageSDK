//
//  DetailViewController.h
//  MokiManage SDK
//
//  Created by Kory Calmes on 12/19/12.
//  Copyright (c) 2012 MokiMobility, Inc. All rights reserved.
//
//  This header is included in the project for the settings views only.
//  There is no need to call any of these methods directly.
//

#import <UIKit/UIKit.h>

@interface DetailViewController : UITableViewController <UISplitViewControllerDelegate>

@property (strong, nonatomic) id detailItem;

@property (strong, nonatomic) NSArray * preferences;
@property (strong, nonatomic) NSDictionary * currentComboBoxSettings;

@property (strong, nonatomic) IBOutlet UITableView *tableView;
@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

- (IBAction)done:(id)sender;

@end
