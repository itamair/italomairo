(function ($) {
    
    
    /*** Define some context general variables  ***/
    var markers = {};  // Associative Markers list object
    var markersList = []; // Unassociative Markers ordinated list array
    var features = {};  // Associative Features list object
    var popups = {};    // Associative Popups list object
    
    var featuresList = [];  // Unassociative Features ordinated list array
    var thisLeafletSettings ; //The Leaflet map general settings object
    var thisLeafletMap ;  //The Leaflet map object
    
        
        //retrieve the Leaflet Markers and Lefalet Features data from the Leaflet (or Leaflet Markeclusterer) module
        $(document).bind('leaflet.feature', function(e, lFeature, feature) {
            
            markers[feature.feature_id] = lFeature; 
            features[feature.feature_id] = feature;

            //Create associative Leaflet popups
            var lat = parseFloat(feature.lat) + 0.00060; //devo aggiungere un pò di lat altrimenti il pupop fa al centro del marker
            var lng = parseFloat(feature.lon);
            var latlng = new L.LatLng(lat, lng );
            popupContent = feature.popup;

            //Create a Leaflet popup and open it in the latlng place
            popups[feature.feature_id] = L.popup()
                .setLatLng(latlng)
                .setContent(popupContent);

            markersList.push(lFeature);
            featuresList.push(feature);
            
            //console.log(feature);
            //console.log(lFeature);
            
        });
        

        //retrieve the Leaflet map general settings and object itself from the Leaflet (or Leaflet Markeclusterer) module
        $(document).bind('leaflet.map', function(e, settingsLeaflet, lMap) {
            thisLeafletSettings = settingsLeaflet;
            thisLeafletMap = lMap;
        });
    
    
  Drupal.behaviors.corolla = {
    
    attach:function (context, settings) {
        
        // Support event to get the latlng of the clicked point on the map (used to set the map bounds in the Getlocations_fields_add module settings)
        //thisLeafletMap.on('click', function(e) {
        //    alert(e.latlng);
        //});
        
        
        //console.log(context);
        console.log(settings);
        
        $(settings).each(function () {
                
            //console.log(thisLeafletSettings);
            //console.log(thisLeafletMap);
            
            function mapReset (lMap) {
                lMap.setView([lMap.center.lat, lMap.center.lng], lMap.zoom, true);
                lMap.closePopup();
                $("select.leaflet-map-select option").filter(function() {
                    //may want to use $.trim in here
                    return $(this).attr('value') == 'all'; 
                }).attr('selected', true);
                
            }
            
                // Zooom sulla mappa con centro del popup creato, senza ricostruzione della mappa
             function zoomToFeature (nid) {
                console.log(thisLeafletMap);
                
                /*** test to add Alternative Tile Layers ...
                
                //Add new Tile Layer
                var cloudmadeUrl = 'http://{s}.tile.cloudmade.com/API-key/{styleId}/256/{z}/{x}/{y}.png',
                cloudmadeAttribution = 'Map data &copy; 2011 OpenStreetMap contributors, Imagery &copy; 2011 CloudMade';
    
                var minimal   = L.tileLayer(cloudmadeUrl, {styleId: 22677, attribution: cloudmadeAttribution}),
                    midnight  = L.tileLayer(cloudmadeUrl, {styleId: 999,   attribution: cloudmadeAttribution}),
                    motorways = L.tileLayer(cloudmadeUrl, {styleId: 46561, attribution: cloudmadeAttribution});
    
                var overlayMaps  = {
                    "Minimal": minimal,
                    "Night View": midnight,
                    "Motorways": motorways
                };
                
                L.control.layers(overlayMaps).addTo(thisLeafletMap);
    
                midnight.addToMap(thisLeafletMap);
                
                ****////
      
                
                thisLeafletMap.setView([parseFloat(features[nid].lat), parseFloat(features[nid].lon)], 14, false).whenReady( function () {
                    setTimeout( function () {
                    popups[nid].openOn(thisLeafletMap);
                    }, 400);
                });
             }
    
            //Funzione per slideshow dei popup dei markers, in assenza di Murkerclusters (evento fire sui singoli markers)
            function loopFireMarkerClick (markersList) {
                var i = 0;
                var timerId = setInterval(function(){
                        markersList[i].fire('click');
                        i++;
                        if(i >= markers.length) clearInterval(timerId);
                    }, 1700);
            }
        
            /*** Funzione per slideshow dei popup dei markers, in presenza di Murkerclusters 
            ***  Creo di volta in volta un nuovo popup nella posizione del Marker (Feature) e lo apro ...
            ** */
            function loopFeaturesOpenPopUps (featuresList) {
                var i = 0;
                var timerId = setInterval(function(){
                      
                    var lat = parseFloat(featuresList[i].lat) + 0.0015;
                    var lng = parseFloat(featuresList[i].lon);
                    var latlng = new L.LatLng(lat, lng );
                    var popupContent = featuresList[i].popup;
                    
                    var popup = L.popup()
                        .setLatLng(latlng)
                        .setContent(popupContent)
                        .openOn(thisLeafletMap);
                        
                        i++;
                        if(i >= featuresList.length) clearInterval(timerId);
                    }, 1500);
            }
    
            // PopUps Slideshows ...
            
            // Without MarkersClusters ... 
            //loopFireMarkerClick (markersList);
            
            // With MarkersClusters ... 
            //loopFeaturesOpenPopUps (featuresList);
            
            var nid;
            var lat;
            var lng;
            var latlng;
            var popupContent;
            var popup;
            
            //console.log(thisLeafletMap);
            //console.log(thisLeafletSettings);
            
            // Fade in dei click per lo zoom sulla mappa
            $('.projects-list-block .node-row a.map-zoom').fadeIn('slow');
        
            $(".projects-list-block .views-row a.map-zoom").bind('mouseover', function(event) {
                
                entity_nid = $(this).attr('nid');
                
                // If there are no Murkerclusters just this line fires the marker click event (& opens the popup)
                //thisLeafletMap.setView(new L.LatLng(markers[nid]._latlng.lat, markers[nid]._latlng.lng), 14, false);
                //markers[nid].fire('click');
                
                // If there are Murkerclusters we need all this below
                //lat = parseFloat(features[nid].lat) + 0.0035; //devo aggiungere un pò di lat altrimenti il pupop fa al centro del marker
                //lng = parseFloat(features[nid].lon);
                //latlng = new L.LatLng(lat, lng );
                //popupContent = features[nid].popup;
    
                //Create a Leaflet popup and open it in the latlng place
                //popup = L.popup()
                //    .setLatLng(latlng)
                //    .setContent(popupContent);
    
                zoomToFeature (entity_nid);
                
            });
    
            $(".leaflet-map-select").change(function(event) {
                
                console.log($('option:selected', this ).attr('value'));
                
                var entity_nid = $('option:selected', this ).attr('value');
                
                var action = (entity_nid == 'all') ? mapReset(thisLeafletMap) : zoomToFeature(entity_nid);
           
                //zoomToFeature (entity_nid);
                
            });
        
            
            $(".projects-list-block .views-row a.map-zoom").bind('mouseout', function(event) {
            
            
                $(this).removeClass('highlighted').text('zoom in map');
                nid = $(this).attr('nid');
                
                //markers[nid].closePopup(); //Nel caso di non markeclusters 
                thisLeafletMap.closePopup(); //Nel caso di markeclusters
                
                // Zooomout sulle mappa sulle sue impostazioni inziali, senza bisogno di rigenerarla
                mapReset (thisLeafletMap);
    
            });
    
            $(".map-reset a").bind('click', function(event) {
                // Zooomout sulle mappa sulle sue impostazioni inziali, senza bisogno di rigenerarla
                mapReset (thisLeafletMap);
            });
        
        
        });

      }

    }
  
  

})(jQuery);
