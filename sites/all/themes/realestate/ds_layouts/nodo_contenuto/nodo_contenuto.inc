<?php
function ds_nodo_contenuto() {
  return array(
    'label' => t('Nodo - contenuto completo'),
    'regions' => array(
        'header' => t('Header'),
        'suffix' => t('Suffix'),
        'image' => t('Image'),
        'description' => t('Description'),
        'left' => t('Left'),
        'right' => t('Right'),
        'footer' => t('Footer'),
    ),
    // Add this line if there is a default css file.
    //'css' => TRUE,
  );
}
?>