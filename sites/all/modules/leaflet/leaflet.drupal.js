(function ($) {
  
  //console.log('leaflet_js loaded');

  Drupal.behaviors.leaflet = {
    attach:function (context, settings) {
      
      console.log(settings);

      $(settings.leaflet).each(function () {
        
        
        
        // bail if the map already exists
        var container = L.DomUtil.get(this.mapId);
        if (!container || container._leaflet) {
          return false;
        }

        // load a settings object with all of our map settings
        var settings = {};
        for (var setting in this.map.settings) {
          settings[setting] = this.map.settings[setting];
        }

        // instantiate our new map
        var lMap = new L.Map(this.mapId, settings);

        // add map layers
        var layers = {}, overlays = {};
        var i = 0;
        for (var key in this.map.layers) {
          var layer = this.map.layers[key];
          var map_layer = Drupal.leaflet.create_layer(layer, key);

          layers[key] = map_layer;

          // add the  layer to the map
          if (i >= 0) {
            lMap.addLayer(map_layer);
          }
          i++;
        }
        
        console.log(this.features);

        // add features
        for (i = 0; i < this.features.length; i++) {
          var feature = this.features[i];
          var lFeature;

          // dealing with a layer group
          if (feature.group) {
            var lGroup = new L.LayerGroup();
            for (var groupKey in feature.features) {
              var groupFeature = feature.features[groupKey];
              lFeature = leaflet_create_feature(groupFeature);
              if (groupFeature.popup) {
                lFeature.bindPopup(groupFeature.popup);
              }
              lGroup.addLayer(lFeature);
            }

            // add the group to the layer switcher
            overlays[feature.label] = lGroup;

            lMap.addLayer(lGroup);
          }
          else {
            lFeature = leaflet_create_feature(feature);
            lMap.addLayer(lFeature);

            if (feature.popup) {
              lFeature.bindPopup(feature.popup);
            }
          }

          // Allow others to do something with the feature that was just added to the map
          $(document).trigger('leaflet.feature', [lFeature, feature]);
        }

        // add layer switcher
        if (this.map.settings.layerControl) {
          lMap.addControl(new L.Control.Layers(layers, overlays));
        }

        // center the map
        if (this.map.center) {
          lMap.setView(new L.LatLng(this.map.center.lat, this.map.center.lon), this.map.settings.zoom);
        }
        // if we have provided a zoom level, then use it after fitting bounds
        else if (this.map.settings.zoom) {
          Drupal.leaflet.fitbounds(lMap);
          lMap.setZoom(this.map.settings.zoom);
        }
        // fit to bounds
        else {
          Drupal.leaflet.fitbounds(lMap);
        }

        // add attribution
        if (this.map.settings.attributionControl && this.map.attribution) {
          lMap.attributionControl.setPrefix(this.map.attribution.prefix);
          lMap.attributionControl.addAttribution(this.map.attribution.text);
        }

        // add the leaflet map to our settings object to make it accessible
        this.lMap = lMap;

        // allow other modules to get access to the map object using jQuery's trigger method
        $(document).trigger('leaflet.map', [this.map, lMap]);

        // Destroy features so that an AJAX reload does not get parts of the old set.
        // Required when the View has "Use AJAX" set to Yes.
        this.features = null;
      });

      function leaflet_create_feature(feature) {
        var lFeature;
        switch (feature.type) {
          case 'point':
            lFeature = Drupal.leaflet.create_point(feature);
            break;
          case 'linestring':
            lFeature = Drupal.leaflet.create_linestring(feature);
            break;
          case 'polygon':
            lFeature = Drupal.leaflet.create_polygon(feature);
            break;
          case 'multipolygon':
          case 'multipolyline':
            lFeature = Drupal.leaflet.create_multipoly(feature);
            break;
          case 'json':
            lFeature = Drupal.leaflet.create_json(feature.json);
            break;
          case 'popup':
            lFeature = Drupal.leaflet.create_popup(feature);
            break;
          case 'circle':
            lFeature = Drupal.leaflet.create_circle(feature);
            break;
        }

        // assign our given unique ID, useful for associating nodes
        if (feature.leaflet_id) {
          lFeature._leaflet_id = feature.leaflet_id;
        }

        var options = {};
        if (feature.options) {
          for (var option in feature.options) {
            options[option] = feature.options[option];
          }
          lFeature.setStyle(options);
        }

        return lFeature;
      }

    }
  };

  Drupal.leaflet = {

    bounds: [],

    create_layer: function (layer, key) {
      var map_layer = new L.TileLayer(layer.urlTemplate);
      map_layer._leaflet_id = key;

      if (layer.options) {
        for (var option in layer.options) {
          map_layer.options[option] = layer.options[option];
        }
      }

      // layers served from TileStream need this correction in the y coordinates
      // TODO: Need to explore this more and find a more elegant solution
      if (layer.type == 'tilestream') {
        map_layer.getTileUrl = function (tilePoint) {
          this._adjustTilePoint(tilePoint);
          var zoom = this._getZoomForUrl();
          return L.Util.template(this._url, L.Util.extend({
            s: this._getSubdomain(tilePoint),
            z: zoom,
            x: tilePoint.x,
            y: Math.pow(2, zoom) - tilePoint.y - 1
          }, this.options));
        };
      }
      return map_layer;
    },

    create_circle: function(circle) {
      var latLng = new L.LatLng(circle.lat, circle.lon);
      latLng = latLng.wrap();
      this.bounds.push(latLng);
      if (circle.options) {
        return new L.Circle(latLng, circle.radius, circle.options);
      }
      else {
        return new L.Circle(latLng, circle.radius);
      }
    },

    create_point: function(marker) {
      var latLng = new L.LatLng(marker.lat, marker.lon);
      latLng = latLng.wrap();
      this.bounds.push(latLng);
      var lMarker;

      if (marker.html) {
        if (marker.html_class) {
          var icon = new L.DivIcon({html: marker.html, className: marker.html_class});
        }
        else {
          var icon = new L.DivIcon({html: marker.html});
        }
        // override applicable marker defaults
        if (marker.icon.iconSize) {
          icon.options.iconSize = new L.Point(parseInt(marker.icon.iconSize.x, 10), parseInt(marker.icon.iconSize.y, 10));
        }
        if (marker.icon.iconAnchor) {
          icon.options.iconAnchor = new L.Point(parseFloat(marker.icon.iconAnchor.x), parseFloat(marker.icon.iconAnchor.y));
        }
        lMarker = new L.Marker(latLng, {icon:icon});
      }
      else if (marker.icon) {
        var icon = new L.Icon({iconUrl: marker.icon.iconUrl});

        // override applicable marker defaults
        if (marker.icon.iconSize) {
          icon.options.iconSize = new L.Point(parseInt(marker.icon.iconSize.x, 10), parseInt(marker.icon.iconSize.y, 10));
        }
        if (marker.icon.iconAnchor) {
          icon.options.iconAnchor = new L.Point(parseFloat(marker.icon.iconAnchor.x), parseFloat(marker.icon.iconAnchor.y));
        }
        if (marker.icon.popupAnchor) {
          icon.options.popupAnchor = new L.Point(parseFloat(marker.icon.popupAnchor.x), parseFloat(marker.icon.popupAnchor.y));
        }
        if (marker.icon.shadowUrl !== undefined) {
          icon.options.shadowUrl = marker.icon.shadowUrl;
        }
        if (marker.icon.shadowSize) {
          icon.options.shadowSize = new L.Point(parseInt(marker.icon.shadowSize.x, 10), parseInt(marker.icon.shadowSize.y, 10));
        }
        if (marker.icon.shadowAnchor) {
          icon.options.shadowAnchor = new L.Point(parseInt(marker.icon.shadowAnchor.x, 10), parseInt(marker.icon.shadowAnchor.y, 10));
        }
        if (marker.icon.zIndexOffset) {
          icon.options.zIndexOffset = marker.icon.zIndexOffset;
        }
        var options = {icon:icon};
        if (marker.zIndexOffset) {
          options.zIndexOffset = marker.zIndexOffset;
        }
        lMarker = new L.Marker(latLng, options);
      }
      else {
        lMarker = new L.Marker(latLng);
      }

      if (marker.label) {
        lMarker.options.title = marker.label;
      }

      return lMarker;
    },

    create_linestring: function(polyline) {
      var latlngs = [];
      for (var i = 0; i < polyline.points.length; i++) {
        var latlng = new L.LatLng(polyline.points[i].lat, polyline.points[i].lon);
        latlng = latlng.wrap();
        latlngs.push(latlng);
        this.bounds.push(latlng);
      }
      return new L.Polyline(latlngs);
    },

    create_polygon: function(polygon) {
      var latlngs = [];
      for (var i = 0; i < polygon.points.length; i++) {
        var latlng = new L.LatLng(polygon.points[i].lat, polygon.points[i].lon);
        latlng = latlng.wrap();
        latlngs.push(latlng);
        this.bounds.push(latlng);
      }
      return new L.Polygon(latlngs);
    },

    create_multipoly: function(multipoly) {
      var polygons = [];
      for (var x = 0; x < multipoly.component.length; x++) {
        var latlngs = [];
        var polygon = multipoly.component[x];
        for (var i = 0; i < polygon.points.length; i++) {
          var latlng = new L.LatLng(polygon.points[i].lat, polygon.points[i].lon);
          latlng = latlng.wrap();
          latlngs.push(latlng);
          this.bounds.push(latlng);
        }
        polygons.push(latlngs);
      }
      if (multipoly.multipolyline) {
        return new L.MultiPolyline(polygons);
      }
      else {
        return new L.MultiPolygon(polygons);
      }
    },

    create_json:function(json) {
      lJSON = new L.GeoJSON(json, {
        onEachFeature:function (feature, layer) {
          var has_properties = (typeof feature.properties != 'undefined');

          // bind popups
          if (has_properties && typeof feature.properties.popup != 'undefined') {
            layer.bindPopup(feature.properties.popup);
          }

          for (var layer_id in layer._layers) {
            for (var i in layer._layers[layer_id]._latlngs) {
              Drupal.leaflet.bounds.push(layer._layers[layer_id]._latlngs[i]);
            }
          }

          if (has_properties && typeof feature.properties.style != 'undefined') {
            layer.setStyle(feature.properties.style);
          }

          if (has_properties && typeof feature.properties.leaflet_id != 'undefined') {
            layer._leaflet_id = feature.properties.leaflet_id;
          }
        }
      });

      return lJSON;
    },

    create_popup: function(popup) {
      var latLng = new L.LatLng(popup.lat, popup.lon);
      this.bounds.push(latLng);
      var lPopup = new L.Popup();
      lPopup.setLatLng(latLng);
      if (popup.content) {
        lPopup.setContent(popup.content);
      }
      return lPopup;
    },

    fitbounds:function (lMap) {
      if (this.bounds.length > 0) {
        lMap.fitBounds(new L.LatLngBounds(this.bounds));
      }
    }
  };

})(jQuery);
