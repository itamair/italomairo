(function ($) {
    
Drupal.behaviors.company_sites_map = {
				attach:function (context, settings) {
						
				if (typeof String.prototype.startsWith != 'function') {
						// see below for better implementation!
						String.prototype.startsWith = function (str){
							return this.indexOf(str) == 0;
						};
				}
        
        $(settings.leaflet).each(function () {
            
						if (this.mapId.startsWith('ip-geoloc-map-of-view-company_sites_map')) {
	
								//console.log(this); //Debug
						
								$(".company-sites-list .views-row").attr('title', '').tooltip({
										content: Drupal.t('Click to Zoom'),
										position: {
										my: "center bottom-10",
										at: "right-50 top",
										},
										//track: true,
										//show: { effect: "blind", duration: 800},
									});
								
								var mapResetDiv = '<div class="map-reset"><a href="javascript:void(0)">' + Drupal.t('Reset the map') + '</a></div>';
								//console.log($(".company-sites-list").length);
								if ($(".company-sites-list .map-reset").length < 1) {
										$(".company-sites-list").append(mapResetDiv);
										$(".company-sites-list .map-reset").hide();
								}
								
								$( ".legenda-categorie-sedi").dialog({						
										autoOpen: false,
										show: { effect: "blind", duration: 800 },
										width: ($(".ip-geoloc-map.leaflet-view").width()*2)/5,
										modal: true,
										appendTo: ".ip-geoloc-map.leaflet-view",
										draggable: false,
										position: { my: "right top", at: "right-10 top+10", of: ".ip-geoloc-map.leaflet-view" },
										title: Drupal.t('Legend'),
										closeOnEscape: true,
								});
								
								$('.map-legend').click(function() {
										$( ".legenda-categorie-sedi").dialog( "open" );
								});					
													 
										var features = {};
										var popups = {};
										
										var thisLeafletMap = (this.lMap) ? this.lMap : null;
										var thisLeafletSettings = this.map;
										
										var mapReset, companySitesListReset, companySiteFocus, centreToFeature;
										
								// Support event to get the latlng of the clicked point on the map (used to set the map bounds in the Getlocations_fields_add module settings)
								//thisLeafletMap.on('click', function(e) {
								//		alert(e.latlng);
								//});
								
								//If it is defined the Leaflet Map in the page Dom, activate all the processings ... 
								if (thisLeafletMap) {

								//console.log(thisLeafletMap);
								
										//Fill the features object with the features, and add a Leaflet popup to it
										for (var i = 0; i < thisLeafletMap.features.length; i++) {
												var featureId = thisLeafletMap.features[i].feature_id;
												
												
												features[featureId] = thisLeafletMap.features[i];
												
												features[featureId].lFeature.unbindPopup().on('click', Drupal.company_sites_map.onMarkerClick);
												
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
														
										};
										
										//console.log(features); //Debug
								
								}		
								
								//$(".company-sites-list .views-row .site-content").each(function() {										
								//		if ($(".column.col-4 .map-reset", this).length == 0) {
								//				$(".column.col-4", this).append('<div class="map-reset"><a class="tipsy" title="Here I am" href="javascript:void(0)">' + Drupal.t('Reset the map') + '</a></div>');
								//		}
								//});

								
								$(".company-sites-list .views-row").bind('mouseenter', function(event) {
										if (!$(this).hasClass('strong-highlighted')) {
												var thisSelector = this;
												Drupal.company_sites_map.resetAllTimeOutEvents(mapReset, companySitesListReset, companySiteFocus);
												companySiteFocus = setTimeout( function () {
														$(".company-sites-list .views-row").removeClass('highlighted').removeClass('sublighted');
														//console.log('mouseEnteredInViewRowSiteContent');
														entity_nid = $(thisSelector).attr('nid');
														//console.log(thisSelector);
														if(features[entity_nid]) { //If there is a features with that nid ...
																$(thisSelector).addClass('highlighted');
																$(".company-sites-list .views-row").not($(".company-sites-list .views-row.highlighted")).addClass('sublighted');
																centreToFeature = setTimeout( function () {
																		Drupal.company_sites_map.centreToFeature (thisLeafletMap, features[entity_nid]);
																}, 300);
														}
												}, 200);
										}
								});

								$(".company-sites-list .views-row").bind('click', function(event) {
										if (!$(this).hasClass('strong-highlighted')) {
												//console.log($(this));
												var thisSelector = this;
												Drupal.company_sites_map.resetAllTimeOutEvents(mapReset, companySitesListReset, companySiteFocus);
												companySiteFocus = setTimeout( function () {
														$(".company-sites-list .views-row").removeClass('highlighted').removeClass('sublighted').removeClass('strong-highlighted');
														//console.log('mouseClickedInViewRowSiteContent');
														entity_nid = $(thisSelector).attr('nid');
														//console.log(thisSelector);
														if(features[entity_nid]) { //If there is a features with that nid ...
																$(thisSelector).addClass('strong-highlighted').fadeIn('slow').tooltip( "disable" );
																//console.log($(thisSelector));
																$(".company-sites-list .views-row").not('.strong-highlighted').fadeOut('slow');
																//$(".company-sites-list .views-row.strong-highlighted").fadeIn('slow');
																zoomToFeature = setTimeout( function () {
																		Drupal.company_sites_map.zoomToFeature (thisLeafletMap, features[entity_nid]);
																}, 200);
																$(".company-sites-list .map-reset").fadeIn('slow');
																console.log('x');
														}
												}, 100);
										};
								});

								$(".company-sites-list .views-row").bind('mouseleave', function(event) {
										var thisSelector = this;
										Drupal.company_sites_map.resetAllTimeOutEvents(mapReset, companySitesListReset, companySiteFocus, centreToFeature);
										companySitesListReset = setTimeout( function () {
												//console.log('mouseLeftFromViewRowSiteContent');
												if($(thisSelector).hasClass('highlighted')) {
														Drupal.company_sites_map.mapReset (thisLeafletMap); // Zooomout sulle mappa sulle sue impostazioni inziali, senza bisogno di rigenerarla
														};
										}, 1000);
				
								});
								
								
								$(".ip-geoloc-map.leaflet-view").bind('mouseenter', function(event) {
										//console.log('mouseEnteredInMap');
										Drupal.company_sites_map.resetAllTimeOutEvents(mapReset, companySitesListReset, companySiteFocus);
								});
								
								$(".ip-geoloc-map.leaflet-view").bind('mouseleave', function(event) {
										//console.log('mouseLeftTheMap');
										mapReset = setTimeout( function () {
												Drupal.company_sites_map.mapReset (thisLeafletMap); // Zooomout sulle mappa sulle sue impostazioni inziali, senza bisogno di rigenerarla
										}, 20000);
								});
				
								$(".map-reset a").bind('click', function(event) {
										event.stopPropagation();
										$(".company-sites-list .views-row").removeClass('highlighted').removeClass('sublighted');
										// Zooomout sulle mappa sulle sue impostazioni inziali, senza bisogno di rigenerarla
										Drupal.company_sites_map.mapReset(thisLeafletMap);
								});
						
						}
				});

      },
      weight: 50

    };

Drupal.company_sites_map = {
    
    mapReset: function (lMap) {
				
				$(".company-sites-list .views-row").removeClass('highlighted').removeClass('sublighted').removeClass('strong-highlighted').tooltip( "enable" ).fadeIn('Slow');
				$(".company-sites-list .map-reset").hide();
				lMap.setView([lMap.center.lat, lMap.center.lng], lMap.zoom, {reset: true, animate: 1});
        //lMap.closePopup();
        //$("select.leaflet-map-select option").filter(function() {
        //    //may want to use $.trim in here
        //    return $(this).attr('value') == 'all'; 
        //}).attr('selected', true);
				//console.log('mapHasBeenReset');
        
    },
		
    // Zooom sulla mappa con centro del popup creato, senza ricostruzione della mappa
    centreToFeature: function (map, feature) {
        map.setView([parseFloat(feature.lat) /*+ 0.006*/, parseFloat(feature.lon)], map.zoom + 1, false).whenReady( function () {
				//setTimeout( function () {
				//feature.Lpopup.openOn(map);
				////console.log('openpopup');
				//}, 200);
        });
     },
    
    // Zooom sulla mappa con centro del popup creato, senza ricostruzione della mappa
    zoomToFeature: function (map, feature) {				
        map.setView([parseFloat(feature.lat) /*+ 0.006*/, parseFloat(feature.lon)], Math.max(13, map.zoom + 3), false).whenReady( function () {
				//setTimeout( function () {
				//feature.Lpopup.openOn(map);
				////console.log('openpopup');
				//}, 200);
        });
     },
		 
		// Zooom sulla mappa con centro del popup creato, senza ricostruzione della mappa
		resetAllTimeOutEvents: function (mapReset, companySitesListReset, companySiteFocus,centreToFeature) {
        if (companySiteFocus )clearTimeout(companySiteFocus); //Stop/Clear any possible event started ...
				if (companySitesListReset )clearTimeout(companySitesListReset); //Stop/Clear any possible event started ...
				if (centreToFeature)clearTimeout(centreToFeature );
				if (mapReset )clearTimeout(mapReset); //Stop/Clear any possible event started ...
     },
		 
		onMarkerClick: function (e) {
				//console.log(e);
				//console.log($(".company-sites-list .views-row[nid=" + e.target.feature_id + "]"));
				$(".company-sites-list .views-row .site-content[nid=" + e.target.feature_id + "]").trigger('click');
		}
};
  

})(jQuery);
