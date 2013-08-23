app.controller('MainController', function($scope) {

    $scope.$on('$routeChangeSuccess', function (scope, next, current) {

        console.log(current)

    });

});