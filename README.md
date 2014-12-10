Android MokiManage SDK Getting Started
======================================

##Installation

###build.gradle

1. Include this repository:

		maven { url 'http://mvn.mokimobility.com:8081/nexus/content/repositories/releases/' }

	It may look something like this

		repositories {
 			maven { url 'http://mvn.mokimobility.com:8081/nexus/content/repositories/releases/' }
	    	mavenLocal()
		   	mavenCentral()
		}

2. Include this dependency:

		compile 'sdk-android:moki-sdk:1.2.2'
	
	It may look something like this  
	
     	dependencies {
        	compile fileTree(dir: 'libs', include: ['*.jar'])
        	compile 'sdk-android:moki-sdk:1.2.2'
        }
 
###AndroidManifest.xml
    
1. Include these permissions:

		<uses-permission android:name="android.permission.READ_PHONE_STATE" />
    	<uses-permission android:name="android.permission.INTERNET" />
	    <uses-permission android:name="android.permission.READ_CONTACTS" />
	    <uses-permission android:name="android.permission.ACCESS_COURSE_LOCATION" />
	    <uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" />
	    <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
	    <uses-permission android:name="android.permission.ACCESS_SUPERUSER" />
	    <uses-permission android:name="android.permission.WAKE_LOCK" />
	    <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
	    <uses-permission android:name="android.permission.RECEIVE_BOOT_COMPLETED" />
	    <uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />
	    <uses-permission android:name="android.permission.BLUETOOTH" />
	    <uses-permission android:name="com.google.android.c2dm.permission.RECEIVE" />
	    
	In addition, add these permission but replace `com.example.packagename` with your package name 
	    
	    <uses-permission android:name="com.example.packagename.permission.C2D_MESSAGE" />
	    
	    <permission
        android:name="com.example.packagename.permission.C2D_MESSAGE"
        android:protectionLevel="signature" />


2. Include these receivers:

		<receiver
            android:name="com.moki.aem.receivers.LogAlarmReceiver"
            android:exported="false" />
        <receiver
            android:name="com.moki.aem.receivers.HeartBeatAlarmReceiver"
            android:exported="false" />
        <receiver
            android:name="com.moki.aem.receivers.ComplianceAlarmReceiver"
            android:exported="false" />
        <receiver
            android:name="com.moki.manage.api.alerts.AlertReceiver"
            android:exported="false" />
        <receiver
            android:name="com.moki.appregistration.receiver.NotificationReceiver"
            android:exported="false" >
            <intent-filter>
                <action android:name="com.moki.manage.MokiManangeAction" />
            </intent-filter>
        </receiver>

        <receiver
            android:name="com.moki.appregistration.receiver.UDIDReceiver"
            android:exported="true">
            <intent-filter>
                <action android:name="com.moki.udid.request"/>
                <action android:name="com.moki.udid.response"/>
            </intent-filter>
        </receiver>

        <receiver
            android:name="com.moki.aem.receivers.AEMCommandReceiver"
            android:exported="false" >
            <intent-filter>
                <action android:name="com.moki.aem.aemCommandIntent" />
            </intent-filter>
        </receiver>	

	In addition, add this receiver but replace `com.example.packagename` with your package name 

		<receiver
            android:name="com.moki.gcm.GCMBroadcastReceiver"
            android:permission="com.google.android.c2dm.permission.SEND" >
            <intent-filter>
                <action android:name="com.google.android.c2dm.intent.RECEIVE" />
                <action android:name="com.google.android.c2dm.intent.REGISTRATION" />
                <category android:name="com.example.packagename" />
            </intent-filter>
        </receiver>
        
3. Include these services:		
		
		<service android:name="com.moki.gcm.GCMService" />
        <service android:name="com.moki.aem.services.AemIntentService" />
        <service android:name="com.moki.appregistration.util.UDIDService"/>	
	
##Implementation

###Initializing

The best place to do this is in your extended Application class.

1. Access your api key, tenant id, and app id

	These can be found on [mokimanage.com](https://www.mokimanage.com/app#settings/devSettings) and correlate to your account.
	
		public static final String API_KEY = "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx";
	    public static final String APP_ID = "xxxxxxxxxx";
	    public static final String TENANT_ID = "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx";
 
2. Initialize the sdk with the following function call

		mokiManage = MokiManage.sharedInstance(API_KEY, TENANT_APP_ID, this, true, true, false);
		
3. Register your app with your tenant

		mokiManage.silentlyRegisterDevice(TENANT_ID);

4. Call pause() and resume() where needed

	Pause and resume will stop and start background processing of the sdk. When your application is in the background it is in your best intrest to stop the sdk from running to conserve device resources.

		mokiManage.pause();
		mokiManage.resume();


	For ease it is best to extend the android.os.Application class and specify that class name in your manifest like so:  

		<application android:name=".ExampleApplication"

###Example Application Class

Below is an example of what is needed in the subclass of android.os.Application excluding implementing Application.ActivityLifecycleCallbacks if you are targeting a build version lower than API level 14.
	
		public class ExampleApplication extends Application {
	    	public static final String API_KEY = "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx";
		    public static final String APP_ID = "xxxxxxxxxx";
		    public static final String TENANT_ID = "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx";
		    
		    private static MokiManage mokiManage;
		    private static ExampleApplication instance;
		    private int activeActivityCount = 0;
		
			@Override
		    public void onCreate() {
		        super.onCreate();
		
		        instance = this;
		
		        mokiManage = MokiManage.sharedInstance(API_KEY, APP_ID, this, true, true, false);
			
		        if(!mokiManage.isRegistered()){
		            mokiManage.silentlyRegisterDevice(TENANT_ID);
		        }
		    }
		    @Override
		    public void onActivityStarted(Activity activity) {
		        activeActivityCount++;
		        if(activeActivityCount == 1){
		            mokiManage.resume();
		        }
		    }
		    @Override
		    public void onActivityStopped(Activity activity) {
		        activeActivityCount--;
		        if(activeActivityCount == 0){
		            mokiManage.pause();
		        }
		    }
		    @Override
		    public void onActivityCreated(Activity activity, Bundle savedInstanceState) {
		    }
		    @Override
		    public void onActivityDestroyed(Activity activity) {
		    }
		    @Override
		    public void onActivityPaused(Activity activity) {
		    }
		    @Override
		    public void onActivityResumed(Activity activity) {
		    }
		    @Override
		    public void onActivitySaveInstanceState(Activity activity, Bundle outState) {
		    }
		}
