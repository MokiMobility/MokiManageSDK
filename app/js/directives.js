app.directive('contextSwitcher', function(){
    return {
        controller: function($rootScope, $cookieStore, $location){
            $rootScope.context = $cookieStore.get('context') || 'apple';  
            $rootScope.contextSwitch=function(ctx){
                $rootScope.context = ctx;
                $cookieStore.put('context',ctx);
                if($location.path().indexOf("quickstart")>=0){
                    $location.path("/quickstart/"+ctx);
                }
            }
        },
        template: '<div class="btn-group"><button class="btn btn-default" ng-click="contextSwitch(\'android\')" context-active="android"><i class="icon-android icon-large"></i></button><button class="btn btn-default" context-active="apple" ng-click="contextSwitch(\'apple\')"><i class="icon-apple icon-large"></i></button></div>',
        restrict: 'C',
        replace: true
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
}).directive('code',function(){
    return {
        restrict:'E',
        link: function(scope, iElement, iAttrs, controller){
                hljs.highlightBlock(iElement.get(0));
            }
    };
}).directive('scrollSpy', function($timeout){
    return {
        restrict: 'A',
        link: function(scope, elem, attr) {
            var offset = parseInt(attr.scrollOffset, 20)
            if(!offset) offset = 10;
            console.log("offset:  " + offset);
            elem.scrollspy({ "offset" : offset});
            scope.$watch(attr.scrollSpy, function(value) {
                $timeout(function() {
                  elem.scrollspy('refresh', { "offset" : offset})
                }, 1);
            }, true);
        }
    }
}).directive('preventDefault', function() {
    return function(scope, element, attrs) {
        jQuery(element).click(function(event) {
            event.preventDefault();
        });
    }
}).directive("scrollTo", ["$window", function($window){
    return {
        restrict : "AC",
        compile : function(){

            function scrollInto(elementId) {
                if(!elementId) $window.scrollTo(0, 0);
                //check if an element can be found with id attribute
                var el = document.getElementById(elementId);
                if(el) el.scrollIntoView();

            }

            return function(scope, element, attr) {
                element.bind("click", function(event){
                    scrollInto(attr.scrollTo);
                });
            };
        }
    };
}]);