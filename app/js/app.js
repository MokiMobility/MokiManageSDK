var app = angular.module('app', [], ['$routeProvider', function($routeProvider){
    $routeProvider.when('/', {
        templateUrl: '/app/partials/home.html',
        controller: 'HomeController'
    });

    $routeProvider.when('/aem', {
        templateUrl: '/app/partials/aem/aem-setup.html'
    });

}]);
