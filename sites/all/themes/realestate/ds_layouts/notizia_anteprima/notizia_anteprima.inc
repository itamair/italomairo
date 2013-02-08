<?php
function ds_notizia_anteprima() {
  return array(
    'label' => t('Notizie - anteprima'),
    'regions' => array(
        'image' => t('Image'),
        'header' => t('Header'),
        'suffix' => t('Suffix'),
        'description' => t('Description'),
        'footer' => t('Footer'),
    ),
    // Add this line if there is a default css file.
    'css' => TRUE,
  );
}
?>