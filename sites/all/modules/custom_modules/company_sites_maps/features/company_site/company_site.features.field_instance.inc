<?php
/**
 * @file
 * company_site.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function company_site_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-company_site-body'
  $field_instances['node-company_site-body'] = array(
    'bundle' => 'company_site',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Indicare qui i dettagli e l\'indirizzo della Sede Aziendale (compariranno con la formattazione imputata)<br>
<strong>Nota: Inputare i contatti (Telefono, Fax, emails, ecc.) nel seguente campo Contatti</strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'entityreference_view_widget' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'body',
    'label' => 'Descrizione & Iindirizzo',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'display_summary' => 0,
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 4,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-company_site-field_geofield_name'
  $field_instances['node-company_site-field_geofield_name'] = array(
    'bundle' => 'company_site',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_geofield_name',
    'label' => 'Geofield Name',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-company_site-field_site_category'
  $field_instances['node-company_site-field_site_category'] = array(
    'bundle' => 'company_site',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Indicare la Categoria della Sede Aziendale',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_site_category',
    'label' => 'Categoria',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-company_site-field_site_contacts'
  $field_instances['node-company_site-field_site_contacts'] = array(
    'bundle' => 'company_site',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Indicare qui i contatti della Sede Aziendale (Telefono, Fax, Emails, ecc.)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_site_contacts',
    'label' => 'Contatti e Riferimenti',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 4,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-company_site-field_site_geofield'
  $field_instances['node-company_site-field_site_geofield'] = array(
    'bundle' => 'company_site',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Indicare la localizzazione della Sede Aziendale',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'geofield_map',
        'settings' => array(
          'geofield_map_baselayers_hybrid' => 1,
          'geofield_map_baselayers_map' => 1,
          'geofield_map_baselayers_physical' => 0,
          'geofield_map_baselayers_satellite' => 1,
          'geofield_map_controltype' => 'default',
          'geofield_map_draggable' => 0,
          'geofield_map_height' => '300px',
          'geofield_map_maptype' => 'map',
          'geofield_map_mtc' => 'standard',
          'geofield_map_overview' => 0,
          'geofield_map_overview_opened' => 0,
          'geofield_map_pancontrol' => 1,
          'geofield_map_scale' => 0,
          'geofield_map_scrollwheel' => 0,
          'geofield_map_streetview_show' => 1,
          'geofield_map_width' => '100%',
          'geofield_map_zoom' => 15,
        ),
        'type' => 'geofield_map_map',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_site_geofield',
    'label' => 'Geolocation ',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'entity_translation_sync' => FALSE,
      'local_solr' => array(
        'enabled' => FALSE,
        'lat_field' => 'lat',
        'lng_field' => 'lng',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'geofield_gmap',
      'settings' => array(
        'click_to_place_marker' => 0,
        'confirm_center_marker' => 0,
        'map_type' => 'ROADMAP',
      ),
      'type' => 'geofield_gmap',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-company_site-field_site_type'
  $field_instances['node-company_site-field_site_type'] = array(
    'bundle' => 'company_site',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Indicare la Tipologia della Sede Aziendale',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'i18n_field',
        'settings' => array(),
        'type' => 'i18n_list_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_site_type',
    'label' => 'Tipo',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-company_site-title_field'
  $field_instances['node-company_site-title_field'] = array(
    'bundle' => 'company_site',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Inserisci il titolo di questo contenuto (campo titolo)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'title_field',
    'label' => 'Titolo',
    'required' => TRUE,
    'settings' => array(
      'custom_add_another' => '',
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'taxonomy_term-site_category-field_geomarker'
  $field_instances['taxonomy_term-site_category-field_geomarker'] = array(
    'bundle' => 'site_category',
    'deleted' => 0,
    'description' => 'Indicare il Marker da associare alla Categoria della Sede Aziendale (si consiglia di rinominare il file in modo coerente con il nome della categoria ed utilizzare il formato png per abilitare la trasparenza su forme non quadrate/rettangolari) ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_geomarker',
    'label' => 'Geo Marker',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'custom_add_another' => '',
      'default_image' => 470,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'geomarkers',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '1MB',
      'max_resolution' => '50x50',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'remote' => 0,
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'insert' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__adaptive' => 0,
          'colorbox__anteprima-copertina-project' => 0,
          'colorbox__flexslider_full' => 0,
          'colorbox__flexslider_thumbnail' => 0,
          'colorbox__home-slideshow' => 0,
          'colorbox__large' => 0,
          'colorbox__media_thumbnail' => 0,
          'colorbox__medium' => 0,
          'colorbox__minithumbnail-progetti' => 0,
          'colorbox__nivo-home' => 0,
          'colorbox__square-thumbnail' => 0,
          'colorbox__threshold-480' => 0,
          'colorbox__threshold-768' => 0,
          'colorbox__threshold-992' => 0,
          'colorbox__threshold-1382' => 0,
          'colorbox__thumbnail' => 0,
          'colorbox__thumbnail2' => 0,
          'colorbox__tutta_pagina' => 0,
          'image' => 0,
          'image_adaptive' => 0,
          'image_anteprima-copertina-project' => 0,
          'image_flexslider_full' => 0,
          'image_flexslider_thumbnail' => 0,
          'image_home-slideshow' => 0,
          'image_large' => 0,
          'image_media_thumbnail' => 0,
          'image_medium' => 0,
          'image_minithumbnail-progetti' => 0,
          'image_nivo-home' => 0,
          'image_square-thumbnail' => 0,
          'image_threshold-480' => 0,
          'image_threshold-768' => 0,
          'image_threshold-992' => 0,
          'image_threshold-1382' => 0,
          'image_thumbnail' => 0,
          'image_thumbnail2' => 0,
          'image_tutta_pagina' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Categoria');
  t('Contatti e Riferimenti');
  t('Descrizione & Iindirizzo');
  t('Geo Marker');
  t('Geofield Name');
  t('Geolocation ');
  t('Indicare il Marker da associare alla Categoria della Sede Aziendale (si consiglia di rinominare il file in modo coerente con il nome della categoria ed utilizzare il formato png per abilitare la trasparenza su forme non quadrate/rettangolari) ');
  t('Indicare la Categoria della Sede Aziendale');
  t('Indicare la Tipologia della Sede Aziendale');
  t('Indicare la localizzazione della Sede Aziendale');
  t('Indicare qui i contatti della Sede Aziendale (Telefono, Fax, Emails, ecc.)');
  t('Indicare qui i dettagli e l\'indirizzo della Sede Aziendale (compariranno con la formattazione imputata)<br>
<strong>Nota: Inputare i contatti (Telefono, Fax, emails, ecc.) nel seguente campo Contatti</strong>');
  t('Inserisci il titolo di questo contenuto (campo titolo)');
  t('Tipo');
  t('Titolo');

  return $field_instances;
}
