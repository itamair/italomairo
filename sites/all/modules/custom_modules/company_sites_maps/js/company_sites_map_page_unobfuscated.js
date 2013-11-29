(function ($) {
    
Drupal.behaviors.company_sites_map = {
				attach:function (context, settings) {
				
				//console.log(settings);
						
				if (typeof String.prototype.startsWith != 'function') {
						// see below for better implementation!
						String.prototype.startsWith = function (str){
							return this.indexOf(str) == 0;
						};
				}
				
				$.widget.bridge('uitooltip', $.ui.tooltip); // handle jQuery plugin naming conflict between jQuery UI and Bootstrap
				     
        $(settings.leaflet).each(function () {
						
						var geofield_gmap_geocoder;
								
						if (!geofield_gmap_geocoder) {
							geofield_gmap_geocoder = new google.maps.Geocoder();
						}
						
						var searchedPlaceIcon = L.icon({
								iconUrl: '/' + settings.company_sites_maps.module_path + '/geomarkers/searched-place.png',				
								iconSize:     [60, 60], // size of the icon
								iconAnchor:   [30, 30], // point of the icon which will correspond to marker's location
								popupAnchor:  [0, -33]
						});
						
            var searchedPlaceMarker = {};
						var closestFeature = {};
						
						if (this.mapId.startsWith('ip-geoloc-map-of-view-company_sites_map')) {
	
								//console.log(this); //Debug
						
								$(".company-sites-list .views-row").attr('title', '').uitooltip({
										content: Drupal.t('Click to Zoom'),
										position: {
										my: "center bottom-10",
										at: "right-50 top",
										//of: '.company-sites-list' ,
										},
										//track: true,
										//show: { effect: "blind", duration: 800},
									});
								
								var mapResetDiv = '<div class="map-reset"><a href="javascript:void(0)">' + Drupal.t('Reset the Sites List and the Map') + '</a></div>';
								//console.log($(".company-sites-list").length);
								if ($(".company-sites-list .map-reset").length < 1) {
										$(".company-sites-list").append(mapResetDiv);
										$(".company-sites-list .map-reset").hide();
								}
								
								$('#search-address-input').val(Drupal.t('Type an address'));
								
								$( ".legenda-categorie-sedi").dialog({						
										autoOpen: false,
										show: { effect: "blind", duration: 800 },
										width: ($(".ip-geoloc-map.leaflet-view").width()*1)/3,
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
												
												features[featureId].lFeature.unbindPopup().on('click', function (e) {
														if(searchedPlaceMarker._leaflet_id) thisLeafletMap.removeLayer(searchedPlaceMarker);
														Drupal.company_sites_map.onMarkerClick(e);
												});
												
												//Get and define each feature's Lat and Lng point
												var lat = parseFloat(features[featureId].lat);
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
																}, 600);
														}
												}, 300);
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
																$(thisSelector).addClass('strong-highlighted').fadeIn('slow').uitooltip( "disable" );
																//console.log($(thisSelector));
																$(".company-sites-list .views-row").not('.strong-highlighted').fadeOut('slow');
																//$(".company-sites-list .views-row.strong-highlighted").fadeIn('slow');
																//console.log((!searchedPlaceMarker._leaflet_id));
																if(!searchedPlaceMarker._leaflet_id) zoomToFeature = setTimeout( function () {
																		Drupal.company_sites_map.zoomToFeature (thisLeafletMap, features[entity_nid]);
																}, 200);
																$(".company-sites-list .map-reset").fadeIn('slow');
														}
												}, 300);
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
										if(searchedPlaceMarker._leaflet_id) thisLeafletMap.removeLayer(searchedPlaceMarker).removeLayer(searchedPlaceMarker.polylineToClosestSite);
										$(".company-sites-list .views-row").removeClass('highlighted').removeClass('sublighted');
										// Zooomout sulle mappa sulle sue impostazioni inziali, senza bisogno di rigenerarla
										Drupal.company_sites_map.mapReset(thisLeafletMap);
								});
						
								$('#search-place-icon').html('<img src="/' + settings.company_sites_maps.module_path + '/geomarkers/searched-place.png" height="20">');
								
								$('#search-address-input').focus(function() {
										$(this).val('');}).autocomplete({
									//This bit uses the geocoder to fetch address values
									source: function(request, response) {
										geofield_gmap_geocoder.geocode( {'address': request.term }, function(results, status) {
											response($.map(results, function(item) {
												//console.log(item); Debug
												return {
													label: item.formatted_address,
													value: item.formatted_address,
													latitude: item.geometry.location.lat(),
													longitude: item.geometry.location.lng()
												}
											}));
										})
									},
									//This bit is executed upon selection of an address
									select: function(event, ui) {
										//console.log(ui); //Debug
										if(searchedPlaceMarker._leaflet_id) thisLeafletMap.removeLayer(searchedPlaceMarker).removeLayer(searchedPlaceMarker.polylineToClosestSite);
										result_address = ui.item.value;
										result_latlng = 'Lat: ' + ui.item.latitude.toFixed(6) + ', Lng:' + ui.item.longitude.toFixed(6);
										//$("#search-latlng-result").html(result_latlng);
										var latlng = L.latLng(ui.item.latitude, ui.item.longitude);
										//console.log(latlng);
										thisLeafletMap.setView(latlng, Math.max(15, thisLeafletMap.zoom + 3), false).whenReady( function () {
												searchedPlaceMarker = L.marker(latlng, {icon: searchedPlaceIcon, clickable: true, riseOnHover: true});
												searchedPlaceMarker.addTo(thisLeafletMap);
										});
										
										searchedPlaceMarker.bindPopup(result_address).openPopup();
										
										
										var closestFeature = Drupal.company_sites_map.findClosestFeature (thisLeafletMap, latlng);
										//console.log('searchedPlaceMarker', searchedPlaceMarker._latlng);
										//console.log('closestFeature', closestFeature);
										//Drupal.company_sites_map.zoomToFeature(thisLeafletMap, closestFeature);
										var closestFeatureLatLng = L.latLng(closestFeature['lat'], closestFeature['lon']);
																														 
										$(".company-sites-list .views-row .site-content[nid=" + closestFeature.feature_id + "]").trigger('click');
										
										fitBoundsToClosestSite = setTimeout( function () {
																		thisLeafletMap.fitBounds(new L.LatLngBounds([latlng, closestFeatureLatLng]), {padding: [40, 40]});
																		searchedPlaceMarker.polylineToClosestSite = L.polyline([latlng, closestFeatureLatLng], {color: 'red', weight: 4}).addTo(thisLeafletMap);
																		//console.log(searchedPlaceMarker.polylineToClosestSite);
																		$('#search-closer-site #search-distance-result').text(closestFeature.distance + ' km');
																		$('#search-closer-site label').text(Drupal.t('Our closer site to'));
																}, 100);
								
							}
						});
						
						}
				});

      },
      weight: 50

    };

Drupal.company_sites_map = {
    
    mapReset: function (lMap) {
				$('#search-address-input').val(Drupal.t('Type an address'));
				$('#search-closer-site #search-distance-result').text('');
				$('#search-closer-site label').text(Drupal.t('Search our closer site to'));
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
				$('#search-address-input').val(Drupal.t('Type an address'));
				$(".company-sites-list .views-row .site-content[nid=" + e.target.feature_id + "]").trigger('click');
		},

		rad: function (x) {return x*Math.PI/180;},
		
		findClosestFeature: function (thisMap, thisLatLng) {
				
				var thisPlace = thisLatLng;
				
				var lat = thisPlace.lat.toFixed(6);
				var lng = thisPlace.lng.toFixed(6);
				
				var R = 6371; // radius of earth in km
				var distances = [];
				var closest = -1;
				for( i=0;i<thisMap.features.length; i++ ) {
						var mlat = thisMap.features[i].lat.toFixed(6);
						var mlng = thisMap.features[i].lon.toFixed(6);
						var dLat  = this.rad(mlat - lat);
						var dLong = this.rad(mlng - lng);
						var a = Math.sin(dLat/2) * Math.sin(dLat/2) +
								Math.cos(this.rad(lat)) * Math.cos(this.rad(lat)) * Math.sin(dLong/2) * Math.sin(dLong/2);
						var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a));
						var d = R * c;
						distances[i] = d;
						thisMap.features[i].distance = distances[i].toFixed(1);;
						if ( closest == -1 || d < distances[closest] ) {
								closest = i;
						}
				}
				
				return(thisMap.features[closest]);
		}
		
};
  

})(jQuery);
