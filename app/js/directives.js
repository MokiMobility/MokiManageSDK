app.directive('contextSwitcher', function(){
    return {
        controller: function($scope, $cookieStore){
            $scope.context = $cookieStore.get('context') || 'apple';  
            $scope.contextSwitch=function(ctx){
                $scope.context = ctx;
                $cookieStore.put('context',ctx);
            }
        },
        template: '<div class="btn-group"><button class="btn btn-default" ng-click="contextSwitch(\'android\')" context-active="android"><i class="icon-android icon-large"></i></button><button class="btn btn-default" context-active="apple" ng-click="contextSwitch(\'apple\')"><i class="icon-apple icon-large"></i></button></div>',
        restrict: 'C',
        replace: true
    };
}).directive('contextActive', function(){
    return {
        controller : function($scope, $element, $attrs, $transclude){
            $scope.$watch('context',function(value){
                if($attrs.contextActive===value) {
                    $element.removeClass('inactive').addClass('active');
                } else {
                    $element.removeClass('active').addClass('inactive');   
                }
            });
        },
        restrict : 'A'
    };
}).directive('contextShow', function(){
    return {
        controller : function($scope, $element, $attrs, $transclude){
            $scope.$watch('context',function(value){
                if($attrs.contextShow===value) {
                    $element.show();
                } else {
                    $element.hide();   
                }
            });
        },
        restrict : 'A'
    };
}).directive('contextIcon', function(){
    return {
        template: '<i class="icon-{{context}}"></i>',
        restrict : 'C'
    };
});