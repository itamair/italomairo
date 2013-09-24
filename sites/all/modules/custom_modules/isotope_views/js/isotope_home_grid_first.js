(function($) {
  $(document).ready(function() {

    //var $container = $('.isotope-container');
    //
    //$container.isotope({
    //	itemSelector: '.isotope-element'
    //});
    
    var $container = $('.isotope-container');
    
    $container.addClass('variable-sizes');

      // hacky way of adding random size classes
      $container.find('.isotope-element').each(function(){
        console.log(this);
        if ( Math.random() > 0.9 ) {
          $(this).addClass('width2');
        }
        if ( Math.random() > 0.6 ) {
          $(this).addClass('height2');
        }
      });  
    
    //$container.imagesLoaded(function() {
    //        setTimeout(function () {
    //                $('.isotope-container').isotope({
    //  // options
    //  itemSelector : '.isotope-element', 
    //
    //                });
    //        }, 50)
    //});
    
    $container.imagesLoaded(function() {
    $container.isotope({
    	itemSelector: '.isotope-element',
        //masonry: {
        //    columnWidth: 0
        //},
        //masonryHorizontal: {
        //    rowHeight: 230
        //}
    });
    });
    

    $('#filters a').click(function(){
      var selector = $(this).attr('data-filter');
      $container.isotope({ filter: selector });
      return false;
    });
   
    });
})(jQuery);