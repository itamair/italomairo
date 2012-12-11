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
?>
<div class="ds-nodo-contenuto <?php print $classes;?> clearfix">

  <? //dpm($content);
  //dpm($node); ?>

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  
      <?php if ($display_submitted && $display_submitted == TRUE): ?>
      <div class="submitted">
          <span class="date"><?php
          print $date;
          //RE_createdDateR($node);
           ?>
          </span>
          <?php print $name; ?>
      </div>
    <?php endif ?>   

  <?php if ($header && $header != '&nbsp;'): ?>
    <div class="group-header <?php print $header_classes; ?>">
      <?php print $header; ?>
    </div>
  <?php endif; ?>
  
  <?php
  //dpm($image);
  if ($image && $image!= '&nbsp;'):?>
    <div class="group-image <?php print $image_classes; ?>">
      <?php print $image; ?>
    </div>
  <?php endif; ?>


  <?php if ($suffix && $suffix != '&nbsp;'): ?>
    <div class="group-suffix <?php print $suffix_classes; ?>">
      <?php print $suffix; ?>
    </div>
  <?php endif; ?>
  

  <?php if ($description && $description != '&nbsp;'): ?>
    <div class="group-description <?php print $description_classes; ?>">
      <?php print $description; ?>
    </div>
  <?php endif; ?>

  <?php if ($left && $left != '&nbsp;'): ?>
    <div class="group-left <?php print $left_classes; ?>">
      <?php print $left; ?>
    </div>
  <?php endif; ?>

  <?php if ($right && $right != '&nbsp;'): ?>
    <div class="group-right <?php print $right_classes; ?>">
      <?php print $right; ?>
    </div>
  <?php endif; ?>

  <?php if ($footer && $footer != '&nbsp;'): ?>
    <div class="group-footer <?php print $footer_classes; ?>">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>
  
    <?php if (isset($content['addthis'])): ?>
    <div class="addthis">
      <?php print render($content['addthis']); ?>
    </div>
  <?php endif; ?>
  
  <!-- These comments are required for the Drush command. You can remove them in your own copy -->
  <!-- /regions -->

</div>