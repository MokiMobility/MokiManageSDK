app.controller('MainController', function($scope, $route) {


    $scope.$route = $route;
    $scope.$on('$routeChangeSuccess', function (scope, next, current) {

        if (!next)
            return;

        if (next.$$route.redirectTo == '/')
            return $scope.home = true;

        if (next.$$route.templateUrl.indexOf('home.html') != -1)
            $scope.home = true;
        else
            $scope.home = false;

    });

    $scope.displayed = false;
    $scope.aemDisplayed = false;


//    console.log($scope.displayed)

    $scope.noDisplay = function() {
        $scope.displayed = false;
        $scope.aemDisplayed = false;

    };

    $scope.display = function() {
        $scope.displayed = true;

    };

    $scope.aemDisplay = function() {
        $scope.aemDisplayed = true;
    };

    $('body').scrollspy({ target: '#navbar' });

});