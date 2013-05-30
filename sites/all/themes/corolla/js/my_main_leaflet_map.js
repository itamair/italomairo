(function ($) {
    
    
    /*** Define some context general variables  ***/
    var markers = {};  // Associative Markers list object
    var markersList = []; // Unassociative Markers ordinated list array
    var features = {};  // Associative Features list object
    var featuresList = [];  // Unassociative Features ordinated list array
    var thisLeafletSettings ; //The Leaflet map general settings object
    var thisLeafletMap ;  //The Leaflet map object
    
        
        //retrieve the Leaflet Markers and Lefalet Features data from the Leaflet (or Leaflet Markeclusterer) module
        $(document).bind('leaflet.feature', function(e, lFeature, feature) {
            
            markers[feature.feature_id] = lFeature; 
            features[feature.feature_id] = feature;
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
    
    
    // Just once the page is loaded ...
    $(document).ready(function () {
        
        function mapReset (lMap) {
            lMap.setView([lMap.center.lat, lMap.center.lng], lMap.zoom, true);
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
            
            nid = $(this).attr('nid');
            
            // If there are no Murkerclusters just this line fires the marker click event (& opens the popup)
            //thisLeafletMap.setView(new L.LatLng(markers[nid]._latlng.lat, markers[nid]._latlng.lng), 14, false);
            //markers[nid].fire('click');
            
            // If there are Murkerclusters we need all this below
            lat = parseFloat(features[nid].lat) + 0.00015; //devo aggiungere un pò di lat altrimenti il pupop fa al centro del marker
            lng = parseFloat(features[nid].lon);
            latlng = new L.LatLng(lat, lng );
            popupContent = features[nid].popup;

            //Create a Leaflet popup and open it in the latlng place
            popup = L.popup()
                .setLatLng(latlng)
                .setContent(popupContent)
                .openOn(thisLeafletMap);
            
            // Zooom sulla mappa con centro del popup creato, senza ricostruzione della mappa
            thisLeafletMap.setView([lat, lng], 12, false);
            

    
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

})(jQuery);
