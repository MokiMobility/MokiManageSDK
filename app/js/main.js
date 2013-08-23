app.controller('MainController', function($scope) {

    $scope.$on('$routeChangeSuccess', function (scope, next, current) {

        if (!next)
            return;

        if (next.$$route.templateUrl.indexOf('home.html') != -1) {



            $scope.home = true

        } else
            $scope.home = false

    });

});