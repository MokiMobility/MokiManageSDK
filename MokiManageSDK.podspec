Pod::Spec.new do |s|
  s.name         = "MokiManageSDK"
  s.version      = "1.2.8"
  s.summary      = "Integrate your application with MokiManage."
  s.description  = <<-DESC
                    Using this SDK your application can integrate with [MokiManage](http://MokiManage.com/).
                    This will help you monitor the applications environment like:
                    * location
                    * network connectivity
                    * battery charge
                    * memory usage
                    * etc.
                    
                    This will also allow you to manage the settings of your application remotely.
                   DESC
  s.homepage     = "http://mokimobility.github.io/MokiManageSDK/"
  
  s.license      = {
    :type => 'Commercial',
    :text => <<-LICENSE
              All text and design is copyright © 2013 MokiMobility

              All rights reserved.

              https://mokimobility.com/
    LICENSE
  }

  s.author       = { "MokiMobility" => "info@mokimobility.com" }
  s.source       = { :git => "git@github.com:MokiMobility/MokiManageSDK.git", :branch => "ios", :tag => "1.2.8" }

  s.platform     = :ios, '7.0'

  s.source_files = '*.{h,m,mm,c,cpp}'
  s.resources = "Images/*.png", "*.storyboard", "*.xib"
  s.preserve_paths = "libMokiManage.a"
  s.library = 'MokiManage'
  s.frameworks = 'ExternalAccessory', 'CoreTelephony', 'CoreLocation', 'SystemConfiguration', 'Foundation', 'CoreGraphics', 'Security', 'Accelerate', 'QuartzCore', 'MobileCoreServices', 'AVFoundation'
  s.requires_arc = true
  s.xcconfig = { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/MokiManageSDK"' }

	s.dependency 'MBProgressHUD', '~> 0.8'
	s.dependency 'Reachability', '~> 3.1.1'
	s.dependency 'FXBlurView', '~> 1.5.3'
	s.dependency 'GoogleAnalytics-iOS-SDK', '~> 3.0'
	s.dependency 'CocoaAsyncSocket', '~> 7.4'
	s.dependency 'AFNetworking', '~> 2.2'
	
end
