<?php
/**
 * @file
 * Display Suite my-project-preview layout template.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 *
 * Regions:
 *
 * - $left: Rendered content for the "Left" region.
 * - $left_classes: String of classes that can be used to style the "Left" region.
 *
 * - $right: Rendered content for the "Right" region.
 * - $right_classes: String of classes that can be used to style the "Right" region.
 */

//dpm($content);

?>
<div class="node-content-wrapper ds-rivista-contenuto-completo <?php print $classes;?> clearfix">

      <?php if (arg(0) == "node" && isset($node->field_rivista_realestate) && $rivista_realestate && $rivista_realestate != '&nbsp;'): ?>
        <h1 class="title"<?php print $title_attributes; ?>><?php print $rivista_realestate; ?></h1>
      <?php endif; ?>
      
      <?php if (arg(0) == "node" && $general_info_rivista && $general_info_rivista != '&nbsp;'): ?>
        <div class="general_info_rivista"><?php print $general_info_rivista; ?></div>
      <?php endif; ?>
  
    <?php if (isset($display_submitted) && $display_submitted): ?>
      <div class="submitted">
          <span class="date"><?php print $date; ?></span>
          <?php print $name; ?>
      </div>
    <?php endif; ?>

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  

  <?php if ($logo && $logo!= '&nbsp;'): ?>
    <div class="group-logo<?php print $logo_classes; ?>">
      <?php print $logo; ?>
    </div>
  <?php endif; ?>

    <?php if ($copertine && $copertine!= '&nbsp;'): ?>
    <div class="group-copertine<?php print $copertine_classes; ?>">
      <?php print $copertine; ?>
    </div>
  <?php endif; ?>
  
    <?php if ($header && $header!= '&nbsp;'): ?>
    <div class="group-header<?php print $header_classes; ?>">
      <?php print $header; ?>
    </div>
  <?php endif; ?>
  
  <?php if ($descrizione && $descrizione!= '&nbsp;'): ?>
    <div class="group-descrizione<?php print $descrizione_classes; ?>">
      <?php print $descrizione; ?>
    </div>
  <?php endif; ?>
  
  <?php if ($right && $right!= '&nbsp;'): ?>
    <div class="group-right<?php print $right_classes; ?>">
      <?php print $right; ?>
    </div>
  <?php endif; ?>

  <?php if ($left && $left!= '&nbsp;'): ?>
    <div class="group-left<?php print $left_classes; ?>">
      <?php print $left; ?>
    </div>
  <?php endif; ?>


  <?php if ($footer && $footer != '&nbsp;'): ?>
    <div class="group-footer<?php print $footer_classes; ?>">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>
  
    <?php if (isset($content['addthis'])): ?>
    <div class="addthis">
      <?php print render($content['addthis']); ?>
    </div>
  <?php endif; ?>
  
    <?php if (isset($archivio) && $archivio!= '&nbsp;'): ?>
    <div class="archivio-riviste">
      <?php print $archivio; ?>
    </div>
  <?php endif; ?>
  
  <!-- These comments are required for the Drush command. You can remove them in your own copy -->
  <!-- /regions -->

</div>