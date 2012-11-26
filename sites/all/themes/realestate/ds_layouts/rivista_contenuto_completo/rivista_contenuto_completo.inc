<?php
function ds_rivista_contenuto_completo() {
  return array(
    'label' => t('Rivista - contenuto completo'),
    'regions' => array(
        'header' => t('Header'),
        'logo' => t('Logo container'),
        'copertine' => t('Copertine'),
        'descrizione' => t('Descrizione'),
        'left' => t('Left'),
        'right' => t('Right'),
        'footer' => t('Footer'),
    ),
    // Add this line if there is a default css file.
    'css' => TRUE,
  );
}
?>