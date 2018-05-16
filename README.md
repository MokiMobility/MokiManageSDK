# MokiManageSDK

## 1.2.12

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.12)
 * bug fixes to update jailbreak detection

## 1.2.11

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.11)
 * bug fixes for network reports, performance sessions, and enrollment

## 1.2.10

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.10)
 * bug fixed that causes crashes when app is running on iOS 9
 
## 1.2.9

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.9)
 * bug fixed that allows followme to work

## 1.2.8

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.8)
 * bug fixed
 * optimizations to logs that build up
 * updated to AFNetworking 2+

## 1.2.7

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.7)
 * bug fixed that allows clients to access custom action command in the userInfo
 * addressed ios 8 change in location services
 
## 1.2.6

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.6)
 * addressed ios 8 change in registering for push notifications
 * addressed ios 8 change in view hierarchy that affected settings views
 * bug fixes to screenshot that includes all views in the window, not just the view of the root view controller
 * improved settings conflict resolution

## 1.2.5

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.5)
 * various bug fixes related to actions not responding
 * various bug fixes related to logs snapshot being taken on a consistent 5 minute interval

## 1.2.4

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.4)
 * various bug fixes related to conflicts for simulator builds
 * various bug fixes related to conflicts with AFNetworking 2+
 

## 1.2.3

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.3)
 * made compatible for 64 bit builds

## 1.2.2

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.2)
 * fixed issue where network check did not appear in the settings views
 

## 1.2.1

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.1)
 * fixed network bug that caused crashing in some scenarios
 * fixed compatibility with cocoapod spec

## 1.2.0

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.2.0)
 * added Follow Me
 * added Network Check
 * added Network Endpoint Monitoring
 * added Custom Actions

### Android
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/android/com/mokimobility/MokiManageSDK/1.2.0)
 * added Follow Me
 * added Network Check
 * added Custom Actions


## 1.1.3

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.1.3)
 * fixed bugs around compliance detection and reporting


## 1.1.2

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.1.2)
 * fixed a bug that cause the devices to heartbeat too frequently


## 1.1.1

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.1.1)

*NOTE* please update your `Podfile` declarations to match the examples in the [README](https://github.com/MokiMobility/MokiManageSDK/tree/1.1.1). It shows how to use the `tag` option to ensure you get the correct version. If you are having difficulties obtaining the latest version due to CocoaPods cacheing then remove the cache directoy `${HOME}/Library/Caches/CocoaPods` and run a `pod update` to repopulate it
 * fixed a bug that prevented compliance reports from persisting through closing the app
 * fixed bug that caused the app to stop sending compliance reports on weak networks
 * fixed bug that caused the user interface to lock up and lag on weak network connections
 * fixed bug that prevented the developer from being notified that the compliance report ran successfully
 * replaced a method that was erroneously removed in 1.1.0 


## 1.1.0

### Android
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/android/com/mokimobility/MokiManageSDK/1.1.0)
 * added access to Compliance information
 * added opt in to run Compliance Checks on heartbeat
 * added access to security information
 * added option to pause and resume MokiManage

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.1.0)
 * added access to Compliance information
 * added option to report up to date Compliance information on each heartbeat
 * surfaced support identifier in the enrollment tab of the ASM settings views
 * removed dependency on NXJson
 * fixed bug that forced users to enable ASM


## 1.0.0

### Android
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/android/com/mokimobility/MokiManageSDK/1.0.0)

### iOS
[Download](https://github.com/MokiMobility/MokiManageSDK/tree/1.0.0)
