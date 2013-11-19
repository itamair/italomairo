/*! A fix for the iOS orientationchange zoom bug.
 Script by @scottjehl, rebound by @wilto.
 MIT / GPLv2 License.
*/
(function(w){

	// This fix addresses an iOS bug, so return early if the UA claims it's something else.
	var ua = navigator.userAgent;
	if( !( /iPhone|iPad|iPod/.test( navigator.platform ) && /OS [1-5]_[0-9_]* like Mac OS X/i.test(ua) && ua.indexOf( "AppleWebKit" ) > -1 ) ){
		return;
	}

    var doc = w.document;

    if( !doc.querySelector ){ return; }

    var meta = doc.querySelector( "meta[name=viewport]" ),
        initialContent = meta && meta.getAttribute( "content" ),
        disabledZoom = initialContent + ",maximum-scale=1",
        enabledZoom = initialContent + ",maximum-scale=10",
        enabled = true,
		x, y, z, aig;

    if( !meta ){ return; }

    function restoreZoom(){
        meta.setAttribute( "content", enabledZoom );
        enabled = true;
    }

    function disableZoom(){
        meta.setAttribute( "content", disabledZoom );
        enabled = false;
    }

    function checkTilt( e ){
		aig = e.accelerationIncludingGravity;
		x = Math.abs( aig.x );
		y = Math.abs( aig.y );
		z = Math.abs( aig.z );

		// If portrait orientation and in one of the danger zones
        if( (!w.orientation || w.orientation === 180) && ( x > 7 || ( ( z > 6 && y < 8 || z < 8 && y > 6 ) && x > 5 ) ) ){
			if( enabled ){
				disableZoom();
			}
        }
		else if( !enabled ){
			restoreZoom();
        }
    }

	w.addEventListener( "orientationchange", restoreZoom, false );
	w.addEventListener( "devicemotion", checkTilt, false );

})( this );;
(function ($) {
  Drupal.behaviors.ATmenuToggle = {
    attach: function (context, settings) {

      var activeTheme = Drupal.settings["ajaxPageState"]["theme"];
      var themeSettings = Drupal.settings['adaptivetheme'];
      var mtsTP = themeSettings[activeTheme]['menu_toggle_settings']['tablet_portrait'];
      var mtsTL = themeSettings[activeTheme]['menu_toggle_settings']['tablet_landscape'];

      var breakpoints = {
         bp1: themeSettings[activeTheme]['media_query_settings']['smalltouch_portrait'],
         bp2: themeSettings[activeTheme]['media_query_settings']['smalltouch_landscape'],
      };

      if (mtsTP == 'true') { breakpoints.push(bp3 + ':' + themeSettings[activeTheme]['media_query_settings']['tablet_portrait']); }
      if (mtsTL == 'true') { breakpoints.push(bp4 + ':' + themeSettings[activeTheme]['media_query_settings']['tablet_portrait']); }

      $(".at-menu-toggle h2").removeClass('element-invisible').addClass('at-menu-toggle-button').wrapInner('<a href="#menu-toggle" class="at-menu-toggle-button-link" />');
      $(".at-menu-toggle ul[class*=menu]:nth-of-type(1)").wrap('<div class="menu-toggle" />');

      !function(breakName, query){

        // Run the callback on current viewport
        cb({
            media: query,
            matches: matchMedia(query).matches
        });

        // Subscribe to breakpoint changes
        matchMedia(query).addListener(cb);

      }(name, breakpoints[name]);

      // Callback
      function cb(data){

        // Toggle menus open or closed
        $(".at-menu-toggle-button-link").click(function() {
          $(this).parent().siblings('.menu-toggle').slideToggle(100, 'swing');
          return false;
        });

      }

      //console.log(themeSettings);
    }
  };
})(jQuery);
;
