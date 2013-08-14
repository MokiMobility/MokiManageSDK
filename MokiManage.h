//
//  MokiManageAPI.h
//  MokiManageAPI
//
//  Created by David Bergum on 12/19/12.
//  Copyright (c) 2012 MokiMobility, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ASMControlValues.h"
#import <UIKit/UIKit.h>
#import "MasterViewController.h"
#import "DetailViewController.h"
#import "EnrollmentViewController.h"

 
// Find the apple docs documentation here: http://gentlebytes.com/appledoc-docs-comments/

/**
 MokiManage has a delegate in place to communicate with the host application after important events have taken
 place that the app should respond to.  The events are centered around registration with MokiManage and 
 settings changes through ASM.
 */

@protocol MokiManageDelegate <NSObject>


@optional

/** Called when the library has finished registering
 
 This method is called after a registration request returns to confirm or deny a successful registration based
 on the contents of the NSError param.
 
 @param error The error that occurred during the pull from the server.  Will be nil if no error occurred.
 @return
 */
- (void)finishedRegistrationWithError:(NSError *)error;

/** Called when the library has finished unregistering
 
 This method is called after a registration request returns to confirm or deny a successful
 unregistration based on the contents of the NSError param.
 
 @param error The error that occurred during the pull from the server.  Will be nil if no error occurred.
 @return
 */
- (void)finishedUnRegistrationWithError:(NSError *)error;

/** Called when the library has finished registering to a new tenant
 
 This method is called after a registration request returns to confirm or deny a successful unregistration
 and then registration into a new tenant based on the contents of the NSError param.
 
 @param error The error that occurred during the pull from the server.  Will be nil if no error occurred.
 @return
 */
- (void)finishedRegisteringToANewTenantWithError:(NSError *)error;

/** Called when the library has finished pulling settings from the server
 
 This method is called when MokiASM has finished pulling settings
 from the server.  If there is an error it will be communicated through the NSError.
 The settings dict and error object are mutually exclusive.
 
 @param settings The new settings dictionary recieved from the server
 @param error The error that occurred during the pull from the server.  Will be nil if no error occurred.
 @return
 */
- (void)finishedPullingSettings:(NSDictionary *)settings WithError:(NSError *)error;

/** Called when the library has finished pushing settings to the server
 
 This method is called when MokiASM has finished pushing settings
 to the server.  If there is an error it will be communicated through the NSError.
 The settings dict and error object are mutually exclusive.
 
 @param settings The settings dictionary that was pushed to the server.
 @param error The error that occurred during the push to the server.  Will be nil if no error occurred. 
 @return
 */
- (void)finishedPushingSettings:(NSDictionary *)settings WithError:(NSError *)error;

/** Called when the built in Settings Views and they are no longer visible
 
 This method is called when the "Done" button is pressed on the Settings Views.  You can respond to this
 by updating anything in your app that uses ASM settings if they were changed by the user.  You can also
 wait until the library calls finishedPushingSettings to update these same settings changes as well.
 
 @return
 */
- (void)finishedEditingSettings;


@end


/** 
 The MokiManage SDK is designed to help developers leverage the MokiManage Platform within their own applications
 
 ### Regstration ###
 
 Registration methods are used to manage the connection of devices to the MokiManage platform.
 
 ### ASM ###
    
 Application Settings Management (ASM) enables a application to have settings that are managed remotely from MokiManage.
 Need a schema.... etc.
 
 ### Custom Alerts ###
 
 Custom alerts allow a developer to trigger alerts at any point in their code that get surfaced in MokiManage web interface to the appropriate admins.  MokiManage already has alerts in place for things like low battery life.  An example of a place where implementing a custom alert would make sense is in the
 application did receive memory warning delegate method.
 
 ### Security ###
 
 These Security methods give the developer an easy way to check for specific security nulnerablities and respond according in the application.
 
 */


@interface MokiManage : NSObject


///---------------------------------------------------------------------------------------
/// @name Delegate
///---------------------------------------------------------------------------------------

/** The MokiManage library's delegate object
 
 The delegate receives notifications when communication with the MokiMDM server has completed.
 
 For information about the methods you can implement for your delegate object, see protocol MokiManageDelegate.
 */

@property (weak, nonatomic) id<MokiManageDelegate> delegate;

///---------------------------------------------------------------------------------------
/// @name Shared Manager
///---------------------------------------------------------------------------------------

/** Returns The MokiManage shared instance
 
 The shared manage is a singleton that allows you to initialize the manager in the app delegate and then use it throughout the applciation.
 
 @warning Calling methods on the shared manager before initializing it will result in unexpected errors.
 
 @return MokiManage shared instance
 */
+ (MokiManage *)sharedManager;
- (void)destroy;

/** Initializes the mokimanage instance
 
 Initializes the mokimanage instance.
 
 @param key The unique identifier of your app within the MokiManage platform
 @param options The options passed to the app on launch
 @param enableASM A boolean specifying whether or not ASM should be used
 @param enableAEM A boolean specifying whether or not AEM should be used
 @param fileName The name os the ASM settings schema file, defaults to SettingsSchema.json if not specified
 @param error An NSError object where errors will be reported
 
 @return Returns The MokiManage shared instance
 */
- (id)initializeWithApiKey:(NSString *)key launchingOptions:(NSDictionary *)options enableASM:(BOOL)enableASM enableAEM:(BOOL)enableAEM asmSettingsFileName:(NSString *)fileName error:(NSError **)error;

/** Returns your Moki Manage API Key
 
 The unique identifier of your app within the MokiManage platform.
 
 @return MokiManage API Key
 */
- (NSString *)apiKey;

/** Processes push notifications for MokiASM
 
 This method must be called from the application delegate whenever a push notification is received from
 application:didReceiveRemoteNotification:.  MokiASM will process any notifications intended for it.
 
 @param userInfo The userInfo dictionary provided in application:didReceiveRemoteNotification:
 */
- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo;

/** Handle background
 
 This method must be called from the application delegate whenever an app enters a background state.
 
 */
- (void)handleBackground;

/** Returns a boolean to indicate is a connection is available
 
 Checks if a conection to MokiManage is available to the MokiManage server using Reachability.
 
 */
- (BOOL)isReachable;

/** Sets the devices apns token for the library
 
 This lets the MokiManage server know how to push tothe device.
 
 @param token The apsn token assigned by Apple and the os to the app
 */
- (void)setApnsToken:(NSData *)token;


///---------------------------------------------------------------------------------------
/// @name Registration
///---------------------------------------------------------------------------------------

/** Registers this device with moki manage
 
 Registers this device with moki manage into the tenant associated with the given short code.
 
 @param shortCode Device registration shortcode obtained from the MokiManage Dashboard
 */
- (void)registerDevice:(NSString *)shortCode;

/** Registers this device with moki manage
 
 Registers this device with moki manage taking the users short code as params.
 
 @param shortCode Device registration shortcode obtained from the MokiManage Dashboard
 @param nickname A nickname for the device that will be visible in the MokiManage Dashboard
 */
- (void)registerDevice:(NSString *)shortCode withNickname:(NSString *)nickname;

/** Registers this device with moki manage
 
 Registers this device with moki manage with the tenant associated with the given tenant id.
 
 @param tenantId The tenantId for a tenant in the MokiManage Dashboard
 */
- (void)silentlyRegisterDevice:(NSString *)tenantId;

/** Unregisters this device with MokiManage
 
 Removes the device from MokiManage so that it is no longer tracked in the dashboard.
 
 */
- (void)unregisterDevice;

/** Re-registers this device in MokiManage Dashboard with a new tenant
 
 Registers this device with moki manage under a new tenant by unregistering and re registering
 into the tenant associated with the given short code.
 
 @param shortCode Device registration shortcode obtained from the MokiManage Dashboard
 */
- (void)registerDeviceToANewTenant:(NSString *)shortCode;

/** Returns the short code used during registration
 
 If a short code was used during registration, it is available to be accessed in the application.
 
 
 @return The short code used during registration, if none was used, nil will be returned
 */
- (NSString *)shortCode;

/** Returns the company name associated with the tenant
 
 If the device is registered, company name is the name of the tenant where the device is registered.
 
 
 @return The name of the company associated with the registered tenant.  If not registered, nil is returned
 */
- (NSString *)companyName;


/** Returns the device's registration status
 
 Enables the application to quickly identify whether or not the device has been registered with the MokiManage Dashboard.
 
 @return The device's registration status
 */
- (BOOL)isRegistered;



#pragma mark - ASM

///---------------------------------------------------------------------------------------
/// @name ASM
///---------------------------------------------------------------------------------------


/** Returns a dictionary of asm settings based on your MokiASM file structure
 
  Once the library reads in the schema, a key/value dictionary is created with the settings values.  
  This dictionary is exchanged with the server for updates and is the return value for this method.
 
 @return Key/value dictionary of settings
 */
- (NSDictionary *)settings;

/** Returns a dictionary of asm settings based on your MokiASM json file structure
 
 The schema in its entirety is a NSDictionary representation of the settings schema json used to initialize the library.
 
 @return The dictionary of asm settings schema
 */
- (NSDictionary *)schema;

/** Saves a dictionary of asm settings
 
 The settings can be retrieved, modified, then passed to this save method to update the settings Saves a dictionary of asm settings.
 
 @param settings a dictionary of asm settings
 */
- (void)saveSettings:(NSDictionary *)settings;

/** Pulls settings from the MokiManage Dashboard
 
 Pulls the current setting's values as they exist on the server to the device.  This happens autmatically throught the
 workflow of the library, but if you ever want to trigger it manually, you can do so.
 */
- (void)pullSettings;

/** Pushes settings to the MokiManage Dashboard
 
 Pushes the current setting's values that are stored on the device to the server.  This happens autmatically throught the
 workflow of the library, but if you ever want to trigger it manually, you can do so.
 */
- (void)pushSettings;


/** Returns the Settings View Controller
 
 The displaySettingsView: will get and display the settings view, in the scenario that you would 
 like to manage its display manually, you can get the this way.
 
 @return The Settings View Controller
 
 */
- (UISplitViewController *)getSettingsViewController;


/** Displays the settings views in a split pane controller
 
 Split View Controllers must exist as the window root so the delate root view is swapped out for the split view controller with
 the settings views.  When the done button is pressed the app delegate is replaced as the window root and the finishedEditingSettings
 delegate method is called.
 
 @param UIApplicationDelegate The main App Delegate of your application
 
 */
-(void)displaySettingsView:(id<UIApplicationDelegate> )delegate;

/** Returns an array associated with the given key in the ASM settings values hash
 
 Returns the array value for the key param in the values hash.
 
 @param key The key for the setting as defined in the settings schema
 */
- (NSArray *)arrayForKey:(NSString *)key;

/** Returns a boolean associated with the given key in the ASM settings values hash
 
 Returns the boolean value for the key param in the values hash.
 
 @param key The key for the setting as defined in the settings schema
 */
- (BOOL)boolForKey:(NSString *)key;

/** Returns data associated with the given key in the ASM settings values hash
 
 Returns the data value for the key param in the values hash.
 
 @param key The key for the setting as defined in the settings schema
 */
- (NSData *)dataForKey:(NSString *)key;

/** Returns a dictionary associated with the given key in the ASM settings values hash
 
 Returns the dictionary value for the key param in the values hash.
 
 @param key The key for the setting as defined in the settings schema
 */
- (NSDictionary *)dictionaryForKey:(NSString *)key;

/** Returns a float associated with the given key in the ASM settings values hash
 
 Returns the float value for the key param in the values hash.
 
 @param key The key for the setting as defined in the settings schema
 */
- (float)floatForKey:(NSString *)key;

/** Returns an integer associated with the given key in the ASM settings values hash
 
 Returns the integer value for the key param in the values hash.
 
 @param key The key for the setting as defined in the settings schema
 */
- (int)integerForKey:(NSString *)key;

/** Returns an object associated with the given key in the ASM settings values hash
 
 Returns the object for the key param in the values hash.
 
 @param key The key for the setting as defined in the settings schema
 */
- (id)objectForKey:(NSString *)key;

/** Returns a string associated with the given key in the ASM settings values hash
 
 Returns the string value for the key param in the values hash.
 
 @param key The key for the setting as defined in the settings schema
 */
- (NSString *)stringForKey:(NSString *)key;

/** Returns a double associated with the given key in the ASM settings values hash
 
 Returns the double value for the key param in the values hash.
 
 @param key The key for the setting as defined in the settings schema
 */
- (double)doubleForKey:(NSString *)key;

/** Returns a URL associated with the given key in the ASM settings values hash
 
 Returns the URL value for the key param in the values hash.
 
 @param key The key for the setting as defined in the settings schema
 */
- (NSURL *)URLForKey:(NSString *)key;

/** Returns a schema associated with the given key in the ASM settings
 
 Returns the schema of associated with the given key.
 
 @param key The key for the setting as defined in the settings schema
 */
- (NSDictionary *)schemaForKey:(NSString *)key;

#pragma mark - Custom Alerts
///---------------------------------------------------------------------------------------
/// @name Custom Alerts
///---------------------------------------------------------------------------------------

/** Sends an alert to the server to be displayed on the web interface
 
 Sends the alert with a specific alert id that maps to the alert created on the web interface.
 
 @param alertId The id of the alert found in the web interface
 */
- (void)sendAlert:(NSString *)alertId;
/** Sends an alert to the server to be displayed on the web interface
 
 Sends the alert with a specific alert id that maps to the alert created on the web interface with the given message.
 
 @param alertId The id of the alert found in the web interface
 @param message A custom message to display for the alert
 */
- (void)sendAlert:(NSString *)alertId withMessage:(NSString *)message;

/** Clears a specific alert on the web interface
 
 When a alertable state is no longer alertable call clear on the alert and it will be cleared so attention isn't drawn to resolved issues.
 
 @param alertId The id of the alert found in the web interface
 */
- (void)clearAlert:(NSString *)alertId;

#pragma mark - Device Information
///---------------------------------------------------------------------------------------
/// @name Device Information
///---------------------------------------------------------------------------------------

/** Adds an array of tags to the device object in the Moki Dashboard
 
 Send the array of tags to be added to the device so the device will be included in tag based searching and scheduled actions.
 */
- (void)addTags:(NSArray *)tags;

/** Returns a dictionary of the meta data for the device
 
 Returns the meta data that can then be used by the developer to identify the device is additional ways specific to your organization.
 The information can be updated and resaving to the device by calling setMetaData.
 */
- (NSDictionary *)metaData;

/** Sets meta data for the device on the device object
 
 Sets meta data that can then be used by the developer to identify the device is additional ways specific to your organization.
 */
- (void)setMetaData:(NSDictionary *)metaData;

/** Returns a support identifier
 
 Returns the identifier that support personell can use to look up the device in the Moki Manage Dashboard.  The developer should
 enroll a device into a tenant silently if not already enrolled and then should surface the identifier to the user for use in the support process.
 */
- (NSString *)identifierForSupport;

#pragma mark - Security
///---------------------------------------------------------------------------------------
/// @name Security
///---------------------------------------------------------------------------------------

/** Returns a boolean indicating the current sate of the jail broken status for the device
 
 Uses 2 different techniniques to determine if the device is jail broken and returns the value to the applcation.
 */
- (BOOL)isJailBroken;

/** Determines if the current device is under device management
 
 This method takes a block as a param where the results of the method are passed for processing.
 
 @param block A block callback where the application can make a determination on how it should respond to the check based on the value of result
 */
- (void)isManaged:(void (^)(BOOL result))block;

/** Determines if the current device is secure
 
 This method takes a block as a param where the results of the method are passed for processing.
 
 @param block A block callback where the application can make a determination on how it should respond to the check based on the value of result
 */
- (void)isSecure:(void (^)(BOOL result))block;

/** Determines if the current device has a password policy enabled
 
 This method takes a block as a param where the results of the method are passed for processing.
 
 @param block A block callback where the application can make a determination on how it should respond to the check based on the value of result
 */
- (void)enabledPasswordPolicy:(void (^)(BOOL result))block;

/** Determines if the current device has disk level encryption
 
 This method takes a block as a param where the results of the method are passed for processing.
 
 @param block A block callback where the application can make a determination on how it should respond to the check based on the value of result
 */
- (void)enabledDiskEncryption:(void (^)(BOOL result))block;

/** Returns a list of apps on the device
 
 This method takes a block as a param where the results of the method are passed for processing.
 
 @param block A block callback where the application can make a determination on how it should respond to the check based on the value of result
 */
- (void)installedApps:(void (^)(NSArray *result))block;

/** Returns a list of peripherals conneceted to the device
 
 This method uses the EAAccessoryManager class to retrieve a list of accessories registered with apple
 */
- (NSArray *)connectedPeripherals;

 

@end
