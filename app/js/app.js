var app = angular.module('app', ['ngCookies'])

//
// ROUTES
//
.config(['$routeProvider', function($routeProvider){
    
    $routeProvider
    
    .when('/', {
        templateUrl: 'app/partials/home.html',
        controller: 'HomeController'
    })
    
    
    .when('/quickstart/apple', {
        templateUrl: 'app/partials/quickstart.html'
    })
    .when('/quickstart/android', {
        templateUrl: 'app/partials/quickstart.html'
    })
    
    .when('/aem', {
        templateUrl: 'app/partials/aem/aem-intro.html',
//        link: {
//            prev: false,
//            next: '/quickstart/apple',
//            nextText: 'Quickstart'
//        }
    })
    
    .when('/aem/ios/apns', {
        templateUrl: 'app/partials/aem/ios/apns.html',
        link: {
            prev: '/aem',
            prevText: 'AEM',
            next: ''
        }
    })

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

.run(function($rootScope, $location, $locationProvider) {
    
    $locationProvider.html5Mode(true);
    
    $rootScope.$on('$routeChangeSuccess', function () {
        // $('ul.nav.bs-sidenav > li ul').hide(); // this `hide` and the `show` below is start to a simple, contextual sub menu feature
        $('.nav-selected').removeClass('nav-selected');
        $('.nav.bs-sidenav a[href="#'+$location.path()+'"]').addClass('nav-selected')
        // $('.nav-selected + ul').show();
    })
});
