<?php
function ds_rivista_anteprima() {
  return array(
    'label' => t('Rivista - anteprima'),
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