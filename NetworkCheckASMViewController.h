//
//  NetworkCheckASMViewController.h
//  MokiTest
//
//  Created by Kevin Ray on 12/13/13.
//  Copyright (c) 2013 Kory Calmes. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NetworkCheckASMViewController : UITableViewController

@property (weak, nonatomic) IBOutlet UIImageView *imagePingsResult;
@property (weak, nonatomic) IBOutlet UIImageView *imageDNSResult;
@property (weak, nonatomic) IBOutlet UIImageView *imageValidIPResult;
@property (weak, nonatomic) IBOutlet UIImageView *imagePortScanResult;
@property (weak, nonatomic) IBOutlet UIImageView *imageURLResult;

- (IBAction)showDetails:(id)sender;
@end
