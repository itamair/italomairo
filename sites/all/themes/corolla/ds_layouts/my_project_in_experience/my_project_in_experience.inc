<?php
function ds_my_project_in_experience() {
  return array(
    'label' => t('My Project in Experience'),
    'regions' => array(
        'left' => t('Left'),
        'right' => t('Right'),
    ),
    // Add this line if there is a default css file.
    'css' => TRUE,
  );
}
?>