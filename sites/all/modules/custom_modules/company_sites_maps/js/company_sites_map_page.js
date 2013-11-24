(function ($) {
    
Drupal.behaviors.company_sites_map = {
    attach:function (context, settings) {
        
        $(settings.leaflet).each(function () {
            
            //console.log(this); //Debug
                       
                var features = {};
                var popups = {};
                
                var thisLeafletMap = (this.lMap) ? this.lMap : null;
                var thisLeafletSettings = this.map;
								
						// Support event to get the latlng of the clicked point on the map (used to set the map bounds in the Getlocations_fields_add module settings)
						//thisLeafletMap.on('click', function(e) {
						//		alert(e.latlng);
						//});
                
                //If it is defined the Leaflet Map in the page Dom, activate all the processings ... 
                if (thisLeafletMap) {

								console.log(thisLeafletMap);
                
                    //Fill the features object with the features, and add a Leaflet popup to it
                    for (var i = 0; i < thisLeafletMap.features.length; i++) {
                        var featureId = thisLeafletMap.features[i].feature_id;
                        features[featureId] = thisLeafletMap.features[i];
                        
                        //Get and define each feature's Lat and Lng point
                        var lat = parseFloat(features[featureId].lat); //devo aggiungere un p√≤ di lat altrimenti il pupop fa al centro del marker
                        var lng = parseFloat(features[featureId].lon);
                        var latlng = new L.LatLng(lat, lng );
                        
                        //Create associative Leaflet popups
                        var popuplatlng = new L.LatLng(lat + 0.00320, lng );
                        popupContent = features[featureId].popup;
    
                        //Create a Leaflet popup associated to the feature
                        features[featureId].Lpopup = L.popup()
                            .setLatLng(popuplatlng)
                            .setContent(popupContent);
                            
                    }
										
										console.log(features); //Debug
                
                }
                
                // Fade in dei click per lo zoom sulla mappa
                $('.projects-list-block .node-row a.map-zoom').fadeIn('slow');
                
                
                $(".company-sites-list .views-row a.map-zoom").bind('mouseover', function(event) {
                    
                    $(this).text(Drupal.t('click to go'));
                    entity_nid = $(this).attr('nid');
                    if(features[entity_nid]) { //If there is a features with that nid ...
                        Drupal.company_sites_map.zoomToFeature (thisLeafletMap, features[entity_nid]);
                    }
                });
        
                $(".leaflet-map-select").change(function(event) {
                    var entity_nid = $('option:selected', this ).attr('value');
                    //console.log(entity_nid, features[entity_nid]); // Debug
                    var action = (entity_nid == 'all') ? Drupal.company_sites_map.mapReset(thisLeafletMap) : Drupal.company_sites_map.zoomToFeature(thisLeafletMap, features[entity_nid]);
                    
                });
            
                
                $(".company-sites-list .views-row a.map-zoom").bind('mouseout', function(event) {
                    $(this).removeClass('highlighted').text('zoom in map');
                    nid = $(this).attr('nid');
                    
                    //markers[nid].closePopup(); //Nel caso di non markeclusters 
                    thisLeafletMap.closePopup(); //Nel caso di markeclusters
                    
                    // Zooomout sulle mappa sulle sue impostazioni inziali, senza bisogno di rigenerarla
                    Drupal.company_sites_map.mapReset (thisLeafletMap);
        
                });
        
                $(".map-reset a").bind('click', function(event) {
                    // Zooomout sulle mappa sulle sue impostazioni inziali, senza bisogno di rigenerarla
                    Drupal.company_sites_map.mapReset (thisLeafletMap);
                });
        
        });

      },
      weight: 50

    }

Drupal.company_sites_map = {
    
    mapReset: function (lMap) {
        lMap.setView([lMap.center.lat, lMap.center.lng], lMap.zoom, true);
        lMap.closePopup();
        $("select.leaflet-map-select option").filter(function() {
            //may want to use $.trim in here
            return $(this).attr('value') == 'all'; 
        }).attr('selected', true);
        
    },
    
    // Zooom sulla mappa con centro del popup creato, senza ricostruzione della mappa
    zoomToFeature: function (map, feature) {    
        
        map.setView([parseFloat(feature.lat) + 0.006, parseFloat(feature.lon)], 14, false).whenReady( function () {
            setTimeout( function () {
            feature.Lpopup.openOn(map);
            }, 200);
        });
     }
}
  

})(jQuery);
