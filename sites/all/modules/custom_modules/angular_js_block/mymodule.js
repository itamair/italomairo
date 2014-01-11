/**
 * Renders the weather status for a city.
 */
var app = angular.module('myapp', [])
.controller('MyModuleWeather', function($scope, $http, $log) {
  // Set default values for our form fields.
  $scope.city = 'Madrid';
  $scope.units = 'metric';

  // Define a function to process form submission.
  $scope.change = function() {
    // Fetch the data from the public API through JSONP.
    // See http://openweathermap.org/API#weather.
    var url = 'http://api.openweathermap.org/data/2.5/weather';
    $http.jsonp(url, { params : {
        q : $scope.city,
        units : $scope.units,
        callback: 'JSON_CALLBACK'
      }}).
      success(function(data, status, headers, config) {
        $scope.main = data.main;
        $scope.wind = data.wind;
        $scope.description = data.weather[0].description;
      }).
      error(function(data, status, headers, config) {
        // Log an error in the browser's console.
        $log.error('Could not retrieve data from ' + url);
      });
  };

  // Trigger form submission for first load.
  $scope.change();
});
