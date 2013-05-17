<?php
function ds_my_project_preview() {
  return array(
    'label' => t('My Project Preview'),
    'regions' => array(
        'header' => t('Header'),
        'left' => t('Left'),
        'right' => t('Right'),
        'footer' => t('Footer'),
    ),
    // Add this line if there is a default css file.
    'css' => TRUE,
  );
}
?>