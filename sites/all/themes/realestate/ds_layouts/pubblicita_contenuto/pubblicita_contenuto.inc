<?php
function ds_pubblicita_contenuto() {
  return array(
    'label' => t('Pubblicità - contenuto'),
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