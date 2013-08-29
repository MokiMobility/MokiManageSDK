app.controller('MainController', function($scope, $route, $anchorScroll) {


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

    $scope.iosDisplayed = false;
    $scope.aemDisplayed = false;
    $scope.androidDisplayed = false;


//    console.log($scope.displayed)

    $scope.noDisplay = function() {
        $scope.iosDisplayed = false;
        $scope.aemDisplayed = false;
        $scope.androidDisplayed = false;

    };

    $scope.display = function() {
        $scope.displayed = true;

    };

    $scope.android = function() {
        $scope.iosDisplayed = false;
        $scope.aemDisplayed = false;
        $scope.androidDisplayed = true;
    };

    $scope.ios = function() {
        $scope.iosDisplayed = true;
        $scope.aemDisplayed = false;
        $scope.androidDisplayed = false;
    };


    $scope.aem = function() {
        $scope.iosDisplayed = false;
        $scope.aemDisplayed = true;
        $scope.androidDisplayed = false;
    };

    $('body').scrollspy({ target: '#navbar' });

});