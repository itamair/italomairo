(function ($) {

    $(document).ready(function () {
 
        //alert ('Javascript enabled!');
        //console.log(document);
    
    $('.block').fadeIn('slow');

    });

})(jQuery);

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
