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
    
    .when('/quickstart/android', {
        templateUrl: 'app/partials/quickstart/android.html'
    })
    
    .when('/quickstart/ios', {
        templateUrl: 'app/partials/quickstart/ios.html'
    })
    
    .when('/aem', {
        templateUrl: 'app/partials/aem/aem-intro.html',
        link: {
            prev: false,
            next: '/aem/ios/apns',
            nextText: 'APNS'
        }
    })
    
    .when('/aem/ios/apns', {
        templateUrl: 'app/partials/aem/ios/apns.html',
        link: {
            prev: '/aem',
            prevText: 'AEM',
            next: ''
        }
    })
    
    .otherwise({redirectTo: '/'});

}])

.run(function($rootScope, $location) {
    $rootScope.$on('$routeChangeSuccess', function () {
        $('.nav-selected').removeClass('nav-selected');
        $('.nav.bs-sidenav a[href="#'+$location.path()+'"]').addClass('nav-selected')
    })
});
