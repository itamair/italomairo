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
<div class="ds-client-in-experience <?php print $classes;?> clearfix">
  
  <div class="client-in-experience">

    <?php if ($left): ?>
      <span class="left <?php print $left_classes; ?>">
        <?php print $left; ?>
      </span>
    <?php endif; ?>
  
    <?php if ($right): ?>
      <span class="right <?php print $right_classes; ?>">
        <?php print $right; ?>
      </span>
    <?php endif; ?>
  
  </div>


</div>