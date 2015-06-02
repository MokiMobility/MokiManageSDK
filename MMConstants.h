//
//  Constants.h
//  MokiAEM
//
//  Created by Kory Calmes on 9/27/13.
//
//

#define kWifiMAC @"WiFiMAC"//mac address
#define kBatteryLevel @"BatteryLevel"// charge %
#define kBatteryStatus @"BatteryStatus" // 
#define kMemory @"Memory"// 
#define kWifiIPAddress @"WiFiIPAddress"
#define kCellIPAddress @"CellIPAddress"
#define kUpTimeStatus @"DeviceUptime"// time since boot in seconds
#define kProcessorLoad @"ProcessorLoad"//The getloadavg() function returns the number of processes in the system run queue averaged over various periods of time. http://developer.apple.com/library/ios/#documentation/System/Conceptual/ManPages_iPhoneOS/man3/getloadavg.3.html
#define kKnowProcesses @"KnownProcesses"
#define kCellSignalStrength @"CellSignalStrength"
#define kJailBroken @"JailBroken"
#define kSSID @"SSID"
#define kSDKVersion @"SDKVersion"
#define kLocation @"Location"
#define kLocationServiceStatus @"LocationServiceStatus"
#define kApnsEnabled @"APNSEnabled"
#define kAppUpTime @"AppUptime"
#define kAppVersion @"AppVersion"
#define kOsVersion @"OSVersion"
#define kStorage @"Storage"
#define kUDID @"UDID"
#define kModel @"Model"
#define kTitle @"Title"
#define kPlatform @"Platform"
#define kCellularTechnology @"CellularTechnology"
#define kVendorID @"VendorID"
#define kTimeStamp @"TimeStamp"
#define kReachabilityStatus @"reachabilityStatus"
#define kDeviceStatus @"deviceStatus"

#define URL_PROD_BASE @"https://mokimanage.appspot.com"
#define URL_STAGE_BASE @"https://mokimdm.appspot.com"

#define DEFAULTS_KEY_BASE_URL @"com.mokimobility.defaults.baseUrl"
#define DEFAULTS_KEY_BASE_URL_OLD @"baseurl"
#define BASE_URL ([[NSUserDefaults standardUserDefaults] stringForKey:DEFAULTS_KEY_BASE_URL] ? [[NSUserDefaults standardUserDefaults] stringForKey:DEFAULTS_KEY_BASE_URL] : [[NSUserDefaults standardUserDefaults] stringForKey:DEFAULTS_KEY_BASE_URL_OLD] )

//Notification Constants
extern NSString *const MMApplicationDidRegisterNotification;
extern NSString *const MMApplicationDidUnRegisterNotification;
extern NSString *const MMApplicationDidRegisterToNewTenantNotification;
extern NSString *const MMApplicationDidFailToRegisterNotification;
extern NSString *const MMApplicationDidFailToUnRegisterNotification;
extern NSString *const MMApplicationDidFailToRegisterToNewTenantNotification;

extern NSString *const MMApplicationDidPullSettingsNotification;
extern NSString *const MMApplicationDidPushSettingsNotification;
extern NSString *const MMApplicationDidFailToPullSettingsNotification;
extern NSString *const MMApplicationDidFailToPushSettingsNotification;

extern NSString *const MMApplicationDidUpdateTagsNotification;

extern NSString *const MMApplicationDidChangeSettingsNotification;

extern NSString *const MMApplicationDidRecieveCustomActionNotification;
extern NSString *const MMApplicationDidReceiveActionNotification;
extern NSString *const MMApplicationDidRecieveDisableApplicationNotification;

extern NSString *const MMHeartbeatDidRunNotification;

extern NSString *const MMNotificationErrorKey;
extern NSString *const MMNotificationChangedValueKeysKey;

//Exception Constants
extern NSString *const MMInvalidHeartbeatActionException;
extern NSString *const MMFollowMeSessionAlreadyActiveException;


