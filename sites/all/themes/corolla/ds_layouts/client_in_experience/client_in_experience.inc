<?php
function ds_client_in_experience() {
  return array(
    'label' => t('Client in Experience'),
    'regions' => array(
        'left' => t('Left'),
        'right' => t('Right'),
    ),
    // Add this line if there is a default css file.
    'css' => TRUE,
  );
}
?>