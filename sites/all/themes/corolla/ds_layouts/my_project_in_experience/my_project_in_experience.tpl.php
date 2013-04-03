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
<div class="ds-my-project-in-experience <?php print $classes;?> clearfix">
  
  <div class="group-content">

    <?php if ($left): ?>
      <div class="group-left <?php print $left_classes; ?>">
        <?php print $left; ?>
      </div>
    <?php endif; ?>
  
    <?php if ($right): ?>
      <div class="group-right <?php print $right_classes; ?>">
        <?php print $right; ?>
      </div>
    <?php endif; ?>
  
  </div>


</div>