(function ($) {

  Drupal.behaviors.geofield_gmap = {
	
    attach:function (context, settings) {
	//console.log("settings:", settings); //Debug
	//console.log("context:", context); //Debug
	
	//$(settings.geofield_map_params).each(function () {
	$('.field-widget-geofield-gmap', context).each(function () {
		
	//console.log(context); //Debug
	//console.log(settings); //Debug
		
	var mapContentId = $('.geofield-gmap-cnt', this).attr('id');
	//console.log("mapContentId:", mapContentId); //Debug
	//console.log("mapContentId:", mapContentId); //Debug
	
	for (var this_geofield_map_params in settings.geofield_map_params) {
	    
	  if(this_geofield_map_params == mapContentId && settings.geofield_map_params[this_geofield_map_params]['initialized'] == 0) {

		settings.geofield_map_params[this_geofield_map_params]['initialized'] = 1;
		
			var thisParams = settings.geofield_map_params[this_geofield_map_params];
		
			//console.log(mapContentId);
			
			var thisIesForm = ($('#'+mapContentId).parents('.ief-form').length > 0) ? $('#'+mapContentId).parents('.ief-form').attr('id') : null;
			//console.log(thisIesForm); //Debug
			
			thisParams.thisIesForm = thisIesForm;
			
			$('.geofield_lat', this).attr('id', thisParams.latid);
			$('.geofield_lon', this).attr('id', thisParams.lngid);
		
			//alert(jQuery("input[name='" + params.geocoded_field + "']").length);
			//console.log(thisParams.geocoded_field); //Debug
			geocoded_field_div = (thisIesForm != null) ? $("#"+thisIesForm+" input[name*='" + thisParams.geocoded_field + "']", context) : $("input[name*='" + thisParams.geocoded_field + "']", context);
			//console.log(geocoded_field_div); //Debug
			geocoded_field_div/*.attr("disabled", "disabled")*/.css('background', 'red')/*.hide()*/.parents('.field-widget-text-textfield').hide();
			thisParams.geocoded_field_div = geocoded_field_div;
			$("#"+thisParams.searchid, this).val(geocoded_field_div.val());
		
			//console.log(thisParams); //Debug
			
			geofield_gmap_initialize(thisParams);
			
			$(thisParams.search.selector).keyup(function() {
					$(thisParams.geocoded_field_div.selector).val($(thisParams.search.selector).val());
			});
			
			$(".geofield-gmap-center", context).click(function(event) {
				//console.log(mapid); //Debug
					geofield_gmap_center(thisParams);
					return false;
			});
			
			$(".geofield-gmap-marker", context).click(function(event) {
				//console.log(mapid); //Debug
					geofield_gmap_marker(thisParams);
					return false;
			});
	    
	  };
	    
	}

		
	});

	var geofield_gmap_geocoder;	
	
	function geofield_gmap_initialize (params){
		
		for (var key in params) {
			if (params[key] instanceof Array) {
			//console.log(key); //Debug
			params[key] = params[key][0];
			}
		}

		if (!geofield_gmap_geocoder) {
			geofield_gmap_geocoder = new google.maps.Geocoder();
		}	
		
		//console.log(params.lat); //Debug
		if (typeof params.lat === "undefined" || typeof params.lng === "undefined") return;
		
	  var location = new google.maps.LatLng(params.lat, params.lng);
	  var options = {
			    zoom: 11,
			    center: location,
			    mapTypeId: google.maps.MapTypeId.SATELLITE,
			    scaleControl: true,
			    zoomControlOptions: {
				style: google.maps.ZoomControlStyle.LARGE,
			    },
			  };
			  
	//console.log("map options:", options); //Debug
	
	  switch (params.map_type) {
		  case "ROADMAP":
			  options.mapTypeId = google.maps.MapTypeId.ROADMAP;
			  break;
		  case "SATELITE":
			  options.mapTypeId = google.maps.MapTypeId.SATELITE;
			  break;
		  case "HYBRID":
			  options.mapTypeId = google.maps.MapTypeId.HYBRID;
			  break;
		  case "TERRAIN":
			  options.mapTypeId = google.maps.MapTypeId.TERRAIN;
			  break;
		 default:
			 options.mapTypeId = google.maps.MapTypeId.ROADMAP;
	  }
	  
	  var map = new google.maps.Map(document.getElementById(params.mapid), options);
	  params.map = map;
	  
	  //console.log("mapId:", geofield_gmap_data[params.mapid]); //Debug
	  //console.log("map center:", geofield_gmap_data[params.mapid].map.getCenter()); //Debug
	
	  
	  // fix http://code.google.com/p/gmaps-api-issues/issues/detail?id=1448
	  google.maps.event.addListener(map, "idle", function(){
			google.maps.event.trigger(map, 'resize'); 
		});	  
	  
	
	  
	  var marker = new google.maps.Marker({
	    map: map,
	    draggable: params.widget,
	  });
	  
	  params.marker = marker;
	  
	  //console.log(location); //Debug
		
	  marker.setPosition(location);
		
		//console.log(marker, marker.getPosition());//Debug
	  
	  //console.log("mapMarker:", geofield_gmap_data[params.mapid].marker); //Debug
	  
	  if (params.widget && params.latid && params.lngid) {
		
		//console.log("latId:", params.latid); //Debug
		//console.log("latField:", $("#" + params.latid)); //Debug
		
		  params.lat = $("#" + params.latid).val();
		  params.lng = $("#" + params.lngid).val();
		  
		  if (params.searchid) {
			params.search = $("#" + params.searchid);
			params.search.autocomplete({
		      //This bit uses the geocoder to fetch address values
		      source: function(request, response) {
			geofield_gmap_geocoder.geocode( {'address': request.term }, function(results, status) {
			  response(jQuery.map(results, function(item) {
					//console.log(item); Debug
			    return {
			      label:  item.formatted_address,
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
			$("#"+params.latid).val(ui.item.latitude.toFixed(6));
			$("#"+params.lngid).val(ui.item.longitude.toFixed(6));
			var location = new google.maps.LatLng(ui.item.latitude, ui.item.longitude);
			marker.setPosition(location);
			map.setCenter(location);
			map.setZoom(15);
			
			//Set the value of the Geocoded Field to the the Geocoder Value result
			$(params.geocoded_field_div.selector).val(ui.item.value);
		      }
		    });
			
			//Add listener to marker for reverse geocoding
			  google.maps.event.addListener(marker, 'dragend', function() {
			    geofield_gmap_geocoder.geocode({'latLng': marker.getPosition()}, function(results, status) {
			      if (status == google.maps.GeocoderStatus.OK) {
				if (results[0]) {
				  params.search.val(results[0].formatted_address);
					console.log(params, $(params.geocoded_field_div));
				  $(params.geocoded_field_div.selector).val($(params.search.selector).val());
				  //console.log('params.search.selector', $(params.search.selector).val());
				  console.log($(params));
					console.log($("#"+params.latid));
				  //console.log(marker, marker.getPosition());
					
				  $("#"+params.latid).val(marker.getPosition().lat().toFixed(6));
				  $("#"+params.lngid).val(marker.getPosition().lng().toFixed(6));
				}
			      }
			    });
			  });
		  }
		  
		  if (params.click_to_place_marker) {
			//change marker position with mouse click  
			  google.maps.event.addListener(map,'click', function(event) {
				var position = new google.maps.LatLng( event.latLng.lat() , event.latLng.lng());
				marker.setPosition(position);
				$("#"+params.latid).val(position.lat().toFixed(6));
				$("#"+params.lngid).val(position.lng().toFixed(6));
				//google.maps.event.trigger(geofield_gmap_data[params.mapid].map, 'resize');
				geofield_gmap_geocoder.geocode({'latLng': position}, function(results, status) {
				  if (status == google.maps.GeocoderStatus.OK) {
				    if (results[0]) {
				      params.search.val(results[0].formatted_address);
				      $(params.geocoded_field_div.selector).val($(params.search.selector).val());
				    }
				  }
				});
			  });
		  }
		  
		//geofield_onchange = function() {
		//      var location = new google.maps.LatLng(
		//	parseInt(geofield_gmap_data[params.mapid].lat.val().toFixed(6)),
		//	parseInt(geofield_gmap_data[params.mapid].lng.val().toFixed(6)));
		//	marker.setPosition(location);
		//	map.setCenter(location);
		//      };
		//   
		//geofield_gmap_data[params.mapid].lat.change(geofield_onchange);
		//geofield_gmap_data[params.mapid].lng.change(geofield_onchange);
	    }
		  
	}
	
	
	
	function geofield_gmap_center (params) {
		google.maps.event.trigger(params.map, 'resize');
		params.map.setCenter(params.marker.getPosition());
	}
	
	function geofield_gmap_marker (params) {
		
		//console.log(geofield_gmap_data[mapid].confirm_center_marker); //Debug
		if (params.confirm_center_marker != 'false') {
			if (!window.confirm('Change marker position ?')) return;
		}
		
		//console.log(geofield_gmap_data[mapid]); //Debug
		
		google.maps.event.trigger(params.map, 'resize');
		var position = params.map.getCenter();
		//console.log(position); //Debug
		params.marker.setPosition(position);
		$("#"+params.latid).val(position.lat().toFixed(6));
		$("#"+params.lngid).val(position.lng().toFixed(6));
		
		if (params.search) {
			geofield_gmap_geocoder.geocode({'latLng': position}, function(results, status) {
		      if (status == google.maps.GeocoderStatus.OK) {
			if (results[0]) {
				params.search.val(results[0].formatted_address);
			}
		      }
		    });
		}
	}
	
    } //end of the attach:function (context, settings)
    
  } // end of Drupal.behaviors.geofield_gmap = {



})(jQuery);


