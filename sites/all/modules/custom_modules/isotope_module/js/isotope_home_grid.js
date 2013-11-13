(function($) {
  $(document).ready(function() {

    var $container = $('.isotope-container .view-content');
    
    $container.addClass('variable-sizes isotope-container');
    
    $container.imagesLoaded(function() {
        $container.isotope({
            itemSelector: '.isotope-element',
            masonry : {columnWidth : 0},
            getSortData : {
              rowNumber : function( $elem ) {
                return parseFloat($elem.attr('row'));
              },
            },
            sortBy : 'rowNumber',
            //sortAscending : false,
        });
    });
  
    
    });
})(jQuery);