<?php
function ds_notizia_anteprima() {
  return array(
    'label' => t('Notizie - anteprima'),
    'regions' => array(
        'header' => t('Header'),
        'suffix' => t('Suffix'),
        'left' => t('Left'),
        'right' => t('Right'),
        'footer' => t('Footer'),
    ),
    // Add this line if there is a default css file.
    'css' => TRUE,
  );
}
?>