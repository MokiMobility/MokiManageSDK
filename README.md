MokiManageSDK-Android
=====================
This is a Maven compatible repository and as such you should be able to use this with Maven, Gradle, Ant+Ivy or other build tools compatible with a maven2 layout repository.

Maven
-----
In your `pom.xml` file be sure to add our repository as well as our SDK as a dependency
```
...
  <repository>
    <id>mokimanage-repo</id>
    <url>https://raw.github.com/MokiMobility/MokiManageSDK/android</url>
  </repository>
...
  <dependency>
    <groupId>com.mokimobility</groupId>
    <artifactId>MokiManageSDK</artifactId>
    <version>1.2.0</version>
  </dependency>
...
```

Gradle
------
In your `build.gradle` file be sure to add maven central repository, our repository and of course our SDK as a dependency
```
...
repositories {
    mavenCentral()
    maven {
        url "https://raw.github.com/MokiMobility/MokiManageSDK/android"
    }
}
...
dependencies {
    compile "com.mokimobility:MokiManageSDK:1.2.0"
}
...
```

Ant+Ivy
-------
In your `ivysettings.xml` file be sure to chain our repository along with the central repository in a matter similar to this:
```
<ivysettings>
    <settings defaultResolver="chain"/>
    <resolvers>
        <chain name="chain">
            <ibiblio name="central" m2compatible="true"/>
            <ibiblio name="mm-repo" m2compatible="true" root="https://raw.github.com/MokiMobility/MokiManageSDK/android"/>
        </chain>
    </resolvers>
</ivysettings>
```
And then in your `ivy.xml` file add our SDK as a dependency
```
...
    <dependencies>
        <dependency org="com.mokimobility" name="MokiManageSDK" rev="1.2.0"/>
    </dependencies>
...
```

Manual Usage
------------
If you need to manually manage your build process and dependencies you can download our SDK jar directly: [MokiManageSDK-1.2.0](https://raw.github.com/MokiMobility/MokiManageSDK/android/com/mokimobility/MokiManageSDK/1.2.0/MokiManageSDK-1.2.0.jar)
You will also need to include a dependency:
* [gson-2.2.2](http://repo1.maven.org/maven2/com/google/code/gson/gson/2.2.2/gson-2.2.2.jar)
