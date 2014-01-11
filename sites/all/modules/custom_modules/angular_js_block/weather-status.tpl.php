<?php
/**
 * @file
 * AngularJS template to render a weather block.
 */
?>
<div ng-controller="MyModuleWeather">
  <label for="city">City</label>
  <input type="text" ng-model="city" /></br>
  <label for="units">Units</label>
  <input type="radio" ng-model="units" value="metric"/> Metric
  <input type="radio" ng-model="units" value="imperial"/> Imperial</br>
  <button ng-click="change()">Change</button>
  <h3>{{data.name}}</h3>
  <p>{{description}}</p>
  <p>Temperature: {{main.temp}}</p>
  <p>Wind speed: {{wind.speed}}</p>
</div>
