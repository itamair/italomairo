
(function ($) {

 $(document).ready(function () {
    
    $('.block').fadeIn('slow');
 
 });
 
})(jQuery);

;
/**
 * jQuery Mobile Menu 
 * Turn unordered list menu into dropdown select menu
 * version 1.0(31-OCT-2011)
 * 
 * Built on top of the jQuery library
 *   http://jquery.com
 * 
 * Documentation
 *   http://github.com/mambows/mobilemenu
 */
(function($){
$.fn.mobileMenu = function(options) {
 
 var defaults = {
   defaultText: 'Navigate to...',
   className: 'select-menu',
   subMenuClass: 'sub-menu',
   subMenuDash: '&ndash;'
  },
  settings = $.extend( defaults, options ),
  el = $(this);
 
 this.each(function(){
  // ad class to submenu list
  el.find('ul').addClass(settings.subMenuClass);

  // Create base menu
  $('<select />',{
   'class' : settings.className
  }).insertAfter( el );

  // Create default option
  $('<option />', {
   "value"  : '#',
   "text"  : settings.defaultText
  }).appendTo( '.' + settings.className );

  // Create select option from menu
  el.find('a,.separator').each(function(){
   var $this  = $(this),
     optText = $this.text(),
     optSub = $this.parents( '.' + settings.subMenuClass ),
     len   = optSub.length,
     dash;
   
   // if menu has sub menu
   if( $this.parents('ul').hasClass( settings.subMenuClass ) ) {
    dash = Array( len+1 ).join( settings.subMenuDash );
    optText = dash + optText;
   }
   if($this.is('span')){
    // Now build menu and append it
   $('<optgroup />', {
    "label" : optText,
   }).appendTo( '.' + settings.className );
   }
   else{
    // Now build menu and append it
   $('<option />', {
    "value" : this.href,
    "html" : optText,
    "selected" : (this.href == window.location.href)
   }).appendTo( '.' + settings.className );
   }

  }); // End el.find('a').each

  // Change event on select element
  $('.' + settings.className).change(function(){
   var locations = $(this).val();
   if( locations !== '#' ) {
    window.location.href = $(this).val();
   }
  });
  $('.select-menu').show();

 });
 return this;
};
})(jQuery);

jQuery(function(){
   jQuery('.region-secondary-content .menu:first').mobileMenu();
  })
;
(function ($) {
  
  jQuery(document).ready(function($) {

	//Correct youtube URL's to one's that work with colorbox
	//http://drupal.org/node/1368274#comment-5353436
	$('a.colorbox-load').each(function(){
	  //alert('ciao');
	  var newUrl = $(this).attr('href').replace('youtube.com/watch?v=', 'youtube.com/v/');
	  $(this).attr('href', newUrl);
	});

	//Force youtube's iframe embed to use wmode="transparent"
	//http://drupal.org/node/1368274#comment-5353632
	//http://maxmorgandesign.com/fix_youtube_iframe_overlay_and_z_index_issues/
	$("iframe").each(function(){
      var ifr_source = $(this).attr('src');
      var wmode = "wmode=transparent";
      if(ifr_source.indexOf('?') != -1) $(this).attr('src',ifr_source+'&'+wmode);
      else $(this).attr('src',ifr_source+'?'+wmode);
	});

	//Force all embedded videos to use wmode="transparent"
	//http://stackoverflow.com/questions/2704485/how-to-add-wmode-transparent-for-every-flash-object-ebmed-tag
	$("object").append('<param name="wMode" value="transparent"/>');
  
  });

})(jQuery);;
