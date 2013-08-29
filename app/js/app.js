var app = angular.module('app', ['ngCookies'])

//
// ROUTES
//
    .config(['$routeProvider', function ($routeProvider) {

        $routeProvider

            .when('/', {
                templateUrl: 'app/partials/home.html',
                controller: 'HomeController'
            })

            .when('/aem', {
                templateUrl: 'app/partials/aem/aem-intro.html'

            })

//            .when('/aem/ios/apns', {
//                templateUrl: 'app/partials/aem/ios/apns.html',
//                link: {
//                    prev: '/aem',
//                    prevText: 'AEM',
//                    next: ''
//                }
//            })


//  apple quickstart navigation
            .when('/aem/apple/apple-quickstart', {
                templateUrl: 'app/partials/aem/apple/apple-quickstart.html',
                link: {
                    next: '/aem/apple/apns',
                    nextText: 'Setup APNs'
                }
            })

            .when('/aem/apple/apns', {
                templateUrl: 'app/partials/aem/apple/apns.html',
                link: {
                    prev: '/aem/apple/apple-quickstart',
                    prevText: 'Intro',
                    next: '/aem/apple/ios-sdk',
                    nextText: 'Add MokiManage SDK'
                }
            })

            .when('/aem/apple/ios-sdk', {
                templateUrl: 'app/partials/aem/apple/ios-sdk.html',
                link: {
                    prev: '/aem/apple/apns',
                    prevText: 'Setup APNs',
                    next: '/aem/apple/ios-delegate',
                    nextText: 'Setup App Delegate'
                }
            })

            .when('/aem/apple/ios-delegate', {
                templateUrl: 'app/partials/aem/apple/ios-delegate.html',
                link: {
                    prev: '/aem/apple/ios-sdk',
                    prevText: 'Add MokiManage SDK',
                    next: '/aem/apple/ios-silent',
                    nextText: 'Silent Enrollment'
                }
            })

            .when('/aem/apple/ios-silent', {
                templateUrl: 'app/partials/aem/apple/ios-silent.html',
                link: {
                    prev: '/aem/apple/ios-delegate',
                    prevText: 'Setup App Delegate',
                    next: '/aem/apple/ios-console',
                    nextText: 'Check MokiManage Console'
                }
            })

            .when('/aem/apple/ios-console', {
                templateUrl: 'app/partials/aem/apple/ios-console.html',
                link: {
                    prev: '/aem/apple/ios-silent',
                    prevText: 'Silent Enrollment'
                }
            })
//End Apple Quickstart Navigation

//Android Quickstart Navigation
            .when('/aem/android/android-quickstart', {
                templateUrl: 'app/partials/aem/android/android-quickstart.html',
                link: {
                    next: '/aem/android/eclipse',
                    nextText: 'Add MokiManage SDK'
                }
            })

            .when('/aem/android/eclipse', {
                templateUrl: 'app/partials/aem/android/eclipse.html',
                link: {
                    prev: '/aem/android/android-quickstart',
                    prevText: 'Intro',
                    next: '/aem/android/manifest',
                    nextText: 'Setup Android Manifest'
                }
            })

            .when('/aem/android/manifest', {
                templateUrl: 'app/partials/aem/android/manifest.html',
                link: {
                    prev: '/aem/android/eclipse',
                    prevText: 'Add MokiManage SDK',
                    next: '/aem/android/extend',
                    nextText: 'Extend the Application Class'
                }
            })

            .when('/aem/android/extend', {
                templateUrl: 'app/partials/aem/android/extend.html',
                link: {
                    prev: '/aem/android/manifest',
                    prevText: 'Setup Android Manifest',
                    next: '/aem/android/broadcasts',
                    nextText: 'Configure to Receive Broadcasts'
                }
            })

            .when('/aem/android/broadcasts', {
                templateUrl: 'app/partials/aem/android/broadcasts.html',
                link: {
                    prev: '/aem/android/extend',
                    prevText: 'Extend the Application Class',
                    next: '/aem/android/silent',
                    nextText: 'Silent Enrollment'
                }
            })

            .when('/aem/android/silent', {
                templateUrl: 'app/partials/aem/android/silent.html',
                link: {
                    prev: '/aem/android/broadcasts',
                    prevText: 'Configure to Receive Broadcasts',
                    next: '/aem/android/android-console',
                    nextText: 'Check the MokiManage Console'
                }
            })

            .when('/aem/android/android-console', {
                templateUrl: 'app/partials/aem/android/android-console.html',
                link: {
                    prev: '/aem/android/silent',
                    prevText: 'Silent Enrollment'
                }
            })
//End Android Quickstart Navigation





            .when('/asm', {
                templateUrl: 'app/partials/asm/asm-intro.html',
                link: {
                    prev: false,
                    next: '/asm/schema-examples',
                    nextText: 'SettingsSchema Examples'
                }
            })

            .when('/asm/schema-examples', {
                templateUrl: 'app/partials/asm/asm-schema-examples.html',
                link: {
                    prev: '/asm',
                    prevText: 'ASM',
                    next: '/asm/update-schema',
                    nextText: 'Updating the schema'
                }
            })

            .when('/asm/update-schema', {
                templateUrl: 'app/partials/asm/asm-update-schema.html',
                link: {
                    prev: '/asm/schema-examples',
                    prevText: 'SettingsSchema Examples',
                    next: '/asm/enable',
                    nextText: 'Enabling the ASM module'
                }
            })

            .when('/asm/enable', {
                templateUrl: 'app/partials/asm/enable-asm.html',
                link: {
                    prev: '/asm/update-schema',
                    prevText: 'Updating the schema',
                    next: '/asm/ui',
                    nextText: 'Using default ASM views'
                }
            })

            .when('/asm/ui', {
                templateUrl: 'app/partials/asm/asm-ui.html',
                link: {
                    prev: '/asm/enable',
                    prevText: 'Enabling the ASM module',
                    next: '/asm/settings',
                    nextText: 'Additional ASM examples'
                }
            })

            .when('/asm/settings', {
                templateUrl: 'app/partials/asm/asm-settings.html',
                link: {
                    prev: '/asm/ui',
                    prevText: 'Using default ASM views'
                }
            })

            .when('/faq', {
                templateUrl: 'app/partials/faq.html'
            })

            .when('/apns-setup', {
                templateUrl: 'app/partials/apns-setup.html'
            })

            .when('/contact', {
                templateUrl: 'app/partials/contact.html'
            })

            .when('/test', {
                templateUrl: 'app/partials/test.html'
            })

            .otherwise({redirectTo: '/'});

    }])

    .run(function ($rootScope, $location) {

        $rootScope.$on('$routeChangeSuccess', function () {
            // $('ul.nav.bs-sidenav > li ul').hide(); // this `hide` and the `show` below is start to a simple, contextual sub menu feature
            $('.nav-selected').removeClass('nav-selected');
            $('.nav.bs-sidenav a[href="#' + $location.path() + '"]').addClass('nav-selected')
            // $('.nav-selected + ul').show();
        })
    });
