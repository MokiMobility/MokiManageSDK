MokiManageSDK-iOS
=================
version 1.2.6


Dependencies
------------

* iOS 5.0+

CocoaPods
---------

This SDK is [CocoaPods](http://cocoapods.org/) compatible. if you are currently using cocoapods then add this dependency line to your `Podfile`

```
pod 'MokiManageSDK', :git => 'https://github.com/MokiMobility/MokiManageSDK.git', :tag => '1.2.6'
```

if you are starting a brand new project this could be your entire `Podfile`

```
platform :ios, "5.0"

pod 'MokiManageSDK', :git => 'https://github.com/MokiMobility/MokiManageSDK.git', :tag => '1.2.6'
```

*Notice* the declaration that iOS is at least verion `"5.0"`

***Warning:*** *Cocoa Pods had a problem with its master pod repo on Jan 30th, 2014. You must run the following 2 commands to fix it*

    pod repo remove master
    pod setup

For more information visit http://blog.cocoapods.org/Repairing-Our-Broken-Specs-Repository/
