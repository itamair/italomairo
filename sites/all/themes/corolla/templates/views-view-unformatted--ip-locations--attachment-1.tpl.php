<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php print '<div class="leaflet-map-select"><span class="label">'.t("Zoom on a project ").'</span><select ><option value="all" selected =​"selected">​'.t("All the projects").'</option>'; ?>

<?php foreach ($rows as $id => $row): ?>
  <?php $row_class = ($classes_array[$id]) ? $row_class = $classes_array[$id] : '';?>
    <?php print '<option value="'.$row_class.'">'.$row.'</option>'; ?>
<?php endforeach; ?>
<?php print "</select></div>"; ?>