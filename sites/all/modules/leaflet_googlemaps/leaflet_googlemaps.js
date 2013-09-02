(function ($) {
  Drupal.leaflet._create_layer = Drupal.leaflet.create_layer;
  Drupal.leaflet.create_layer = function(layer, key) {
    if ((layer.type != undefined) && (layer.type == 'google-maps')) {
      var mapLayer = new L.Google(layer.googleMapsType)
      mapLayer._leaflet_id = key;
      return mapLayer;
    }
    return Drupal.leaflet._create_layer(layer, key)
  };
})(jQuery);
