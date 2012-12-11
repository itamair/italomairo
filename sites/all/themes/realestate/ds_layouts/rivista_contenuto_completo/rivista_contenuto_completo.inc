<?php
function ds_rivista_contenuto_completo() {
  return array(
    'label' => t('Rivista - contenuto completo'),
    'regions' => array(
        'rivista_realestate' => t('Titolo Rivista Realestate'),
        'general_info_rivista' => t('Informazioni Generali Rivista'),
        'header' => t('Header'),
        'logo' => t('Logo container'),
        'copertine' => t('Copertine'),
        'descrizione' => t('Descrizione'),
        'left' => t('Left'),
        'right' => t('Right'),
        'footer' => t('Footer'),
        'archivio' => t('Archivio Riviste'),
    ),
    // Add this line if there is a default css file.
    'css' => TRUE,
  );
}
?>