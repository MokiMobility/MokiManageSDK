var app = angular.module('app', [], ['$routeProvider', function($routeProvider){
    $routeProvider.when('/', {
        templateUrl: '/app/partials/home.html'
    });

}]);
