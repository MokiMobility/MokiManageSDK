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
    
    .when('/test', {
        templateUrl: 'app/partials/test.html'
    })
    
    .otherwise({redirectTo: '/'});

}])

.run(function($rootScope, $location) {
    $rootScope.$on('$routeChangeSuccess', function () {
        // $('ul.nav.bs-sidenav > li ul').hide(); // this `hide` and the `show` below is start to a simple, contextual sub menu feature
        $('.nav-selected').removeClass('nav-selected');
        $('.nav.bs-sidenav a[href="#'+$location.path()+'"]').addClass('nav-selected')
        // $('.nav-selected + ul').show();
    })
});
