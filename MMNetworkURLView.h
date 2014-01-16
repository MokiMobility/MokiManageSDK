//
//  MMNetworkURLView.h
//  MokiTest
//
//  Created by Kevin Ray on 12/4/13.
//  Copyright (c) 2013 Kory Calmes. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MMNetworkURLView : UIView

@property (weak, nonatomic) IBOutlet UILabel *labelURLValue;
@property (weak, nonatomic) IBOutlet UILabel *labelResponseTimeValue;
@property (weak, nonatomic) IBOutlet UILabel *labelResponseCodeValue;
@property (weak, nonatomic) IBOutlet UILabel *labelResultValue;

@end
