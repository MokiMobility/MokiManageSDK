var app = angular.module('app', [], ['$routeProvider', function($routeProvider){
    $routeProvider.when('/', {
        templateUrl: '/app/partials/home.html',
        controller: 'HomeController'
    });

    $routeProvider.when('/aem', {
        templateUrl: '/app/partials/aem/aem-intro.html',
        link: {
            prev: false,
            next: '/aem/ios/apns',
            nextText: 'APNS'
        }
    });

    $routeProvider.when('/aem/ios/apns', {
        templateUrl: '/app/partials/aem/ios/apns.html',
        link: {
            prev: '/aem',
            prevText: 'AEM',
            next: ''
        }
    });

}]);
