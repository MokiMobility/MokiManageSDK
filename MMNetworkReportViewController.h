//
//  MMNetworkReportViewController.h
//  MokiTest
//
//  Created by Kevin Ray on 12/4/13.
//  Copyright (c) 2013 Kory Calmes. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface MMNetworkReportViewController : UIViewController

@property (weak, nonatomic) IBOutlet UIScrollView *scrollViewForChecks;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;

@property (weak, nonatomic) IBOutlet UIButton *btnRunNetworkCheck;

@property (weak, nonatomic) IBOutlet UILabel *labelLastCheckValue;
@property (weak, nonatomic) IBOutlet UILabel *labelNetworkTypeValue;
@property (weak, nonatomic) IBOutlet UILabel *labelSignalStrengthValue;
@property (weak, nonatomic) IBOutlet UILabel *labelCheckTypeValue;
@property (weak, nonatomic) IBOutlet UILabel *labelOSVersionValue;

@property (weak, nonatomic) IBOutlet UIView *viewPingsCheck;
@property (weak, nonatomic) IBOutlet UIView *viewDNSCheck;
@property (weak, nonatomic) IBOutlet UIView *viewValidIPCheck;
@property (weak, nonatomic) IBOutlet UIView *viewPortScanCheck;
@property (weak, nonatomic) IBOutlet UIView *viewPingsBasicCheck;
@property (weak, nonatomic) IBOutlet UIView *viewURLCheck;

@property (weak, nonatomic) IBOutlet UIButton *btnPingsHeader;
@property (weak, nonatomic) IBOutlet UIButton *btnDNSHeader;
@property (weak, nonatomic) IBOutlet UIButton *btnValidIPHeader;
@property (weak, nonatomic) IBOutlet UIButton *btnPortScanHeader;
@property (weak, nonatomic) IBOutlet UIButton *btnURLHeader;


@property (weak, nonatomic) IBOutlet UILabel *labelPingsAdvMokiMaxLatencyValue;
@property (weak, nonatomic) IBOutlet UILabel *labelPingsAdvMokiAvgLatencyValue;
@property (weak, nonatomic) IBOutlet UILabel *labelPingsAdvMokiMissingPacketsValue;
@property (weak, nonatomic) IBOutlet UILabel *labelPingsAdvMokiResultValue;

@property (weak, nonatomic) IBOutlet UILabel *labelPingsAdvOutsideMaxLatencyValue;
@property (weak, nonatomic) IBOutlet UILabel *labelPingsAdvOutsideAvgLatencyValue;
@property (weak, nonatomic) IBOutlet UILabel *labelPingsAdvOutsideMissingPacketsValue;
@property (weak, nonatomic) IBOutlet UILabel *labelPingsAdvOutsideResultValue;

@property (weak, nonatomic) IBOutlet UILabel *labelPingsAdvDefaultMaxLatencyValue;
@property (weak, nonatomic) IBOutlet UILabel *labelPingsAdvDefaultAvgLatencyValue;
@property (weak, nonatomic) IBOutlet UILabel *labelPingsAdvDefaultMissingPacketsValue;
@property (weak, nonatomic) IBOutlet UILabel *labelPingsAdvDefaultResultValue;



@property (weak, nonatomic) IBOutlet UILabel *labelPingsBasicMokiResponseTimeValue;
@property (weak, nonatomic) IBOutlet UILabel *labelPingsBasicMokiResultValue;

@property (weak, nonatomic) IBOutlet UILabel *labelPingsBasicOutsideResponseTimeValue;
@property (weak, nonatomic) IBOutlet UILabel *labelPingsBasicOutsideResultValue;

@property (weak, nonatomic) IBOutlet UILabel *labelPingsBasicDefaultResponseTimeValue;
@property (weak, nonatomic) IBOutlet UILabel *labelPingsBasicDefaultResultValue;



@property (weak, nonatomic) IBOutlet UILabel *labelDNSResponseTimeValue;
@property (weak, nonatomic) IBOutlet UILabel *labelDNSResultValue;

@property (weak, nonatomic) IBOutlet UILabel *labelValidIPAddressValue;
@property (weak, nonatomic) IBOutlet UILabel *labelValidResultValue;

@property (weak, nonatomic) IBOutlet UILabel *labelPortScan443Value;
@property (weak, nonatomic) IBOutlet UILabel *labelPortScan80Value;
@property (weak, nonatomic) IBOutlet UILabel *labelPortScan53Value;
@property (weak, nonatomic) IBOutlet UILabel *labelPortScan2195Value;
@property (weak, nonatomic) IBOutlet UILabel *labelPortScan2196Value;
@property (weak, nonatomic) IBOutlet UILabel *labelPortScan5223Value;


@property (weak, nonatomic) IBOutlet UIImageView *imageViewPingsSuccess;
@property (weak, nonatomic) IBOutlet UIImageView *imageViewDNSSuccess;
@property (weak, nonatomic) IBOutlet UIImageView *imageViewValidIPSuccess;
@property (weak, nonatomic) IBOutlet UIImageView *imageViewPortScanSuccess;
@property (weak, nonatomic) IBOutlet UIImageView *imageViewURLSuccess;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintContainerInScrollView;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintPingsAdvViewHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintPingsBasicViewHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintURLViewHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintDNSViewHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintValidIPViewHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintPortViewHeight;

- (IBAction)donePressed:(id)sender;
- (IBAction)runAdvancedNetworkCheck:(id)sender;
- (IBAction)pingsHeaderTouched:(id)sender;
- (IBAction)dnsHeaderTouched:(id)sender;
- (IBAction)validIPHeaderTouched:(id)sender;
- (IBAction)portScanHeaderTouched:(id)sender;
- (IBAction)urlHeaderTouched:(id)sender;
@end
