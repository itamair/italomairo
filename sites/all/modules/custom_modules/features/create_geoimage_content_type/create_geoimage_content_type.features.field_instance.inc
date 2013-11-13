<?php
/**
 * @file
 * create_geoimage_content_type.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function create_geoimage_content_type_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-immagine_georiferita-field_autore_tc'
  $field_instances['node-immagine_georiferita-field_autore_tc'] = array(
    'bundle' => 'immagine_georiferita',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anteprima_immagine_georiferita' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_autore_tc',
    'label' => 'Autore TC',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'autocomplete_deluxe',
      'settings' => array(
        'autocomplete_deluxe_path' => 'autocomplete_deluxe/taxonomy',
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'delimiter' => '',
        'limit' => 10,
        'min_length' => 0,
        'size' => 60,
      ),
      'type' => 'autocomplete_deluxe_taxonomy',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-immagine_georiferita-field_didascalia_foto'
  $field_instances['node-immagine_georiferita-field_didascalia_foto'] = array(
    'bundle' => 'immagine_georiferita',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anteprima_immagine_georiferita' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_didascalia_foto',
    'label' => 'Didascalia Foto',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 100,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-immagine_georiferita-field_geofield'
  $field_instances['node-immagine_georiferita-field_geofield'] = array(
    'bundle' => 'immagine_georiferita',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anteprima_immagine_georiferita' => array(
        'label' => 'hidden',
        'module' => 'geofield_map',
        'settings' => array(
          'geofield_map_baselayers_hybrid' => 0,
          'geofield_map_baselayers_map' => 1,
          'geofield_map_baselayers_physical' => 0,
          'geofield_map_baselayers_satellite' => 0,
          'geofield_map_controltype' => 'none',
          'geofield_map_draggable' => 0,
          'geofield_map_height' => '75px',
          'geofield_map_maptype' => 'map',
          'geofield_map_mtc' => 'none',
          'geofield_map_overview' => 0,
          'geofield_map_overview_opened' => 0,
          'geofield_map_pancontrol' => 0,
          'geofield_map_scale' => 0,
          'geofield_map_scrollwheel' => 0,
          'geofield_map_streetview_show' => 0,
          'geofield_map_width' => '110px',
          'geofield_map_zoom' => 9,
        ),
        'type' => 'geofield_map_map',
        'weight' => 2,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'entityreference_view_widget' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'geofield_map',
        'settings' => array(
          'geofield_map_baselayers_hybrid' => 0,
          'geofield_map_baselayers_map' => 1,
          'geofield_map_baselayers_physical' => 0,
          'geofield_map_baselayers_satellite' => 0,
          'geofield_map_controltype' => 'none',
          'geofield_map_draggable' => 0,
          'geofield_map_height' => '100px',
          'geofield_map_maptype' => 'map',
          'geofield_map_mtc' => 'none',
          'geofield_map_overview' => 0,
          'geofield_map_overview_opened' => 0,
          'geofield_map_pancontrol' => 0,
          'geofield_map_scale' => 0,
          'geofield_map_scrollwheel' => 0,
          'geofield_map_streetview_show' => 0,
          'geofield_map_width' => '30%',
          'geofield_map_zoom' => 12,
        ),
        'type' => 'geofield_map_map',
        'weight' => 11,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_geofield',
    'label' => 'Geofield',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
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
        'geocoded_field' => 'field_nome_location',
        'geocoded_field_delta' => 1,
        'map_type' => 'ROADMAP',
      ),
      'type' => 'geofield_gmap',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-immagine_georiferita-field_image'
  $field_instances['node-immagine_georiferita-field_image'] = array(
    'bundle' => 'immagine_georiferita',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anteprima_immagine_georiferita' => array(
        'label' => 'hidden',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'auto',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => '',
          'colorbox_node_style' => 'thumbnail',
        ),
        'type' => 'colorbox',
        'weight' => 1,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'auto',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => '',
          'colorbox_node_style' => 'large',
        ),
        'type' => 'colorbox',
        'weight' => 3,
      ),
      'entityreference_view_widget' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'auto',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => '',
          'colorbox_node_style' => 'thumbnail',
        ),
        'type' => 'colorbox',
        'weight' => 12,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_image',
    'label' => 'Immagine',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_image' => 0,
      'file_directory' => 'immagini_georiferite',
      'file_extensions' => 'png gif jpg jpeg',
      'imagecrop' => array(
        'orizzontally_croppable_image' => 'orizzontally_croppable_image',
        'square_cropped_image' => 'square_cropped_image',
        'vertically_cropabble_image' => 'vertically_cropabble_image',
      ),
      'max_filesize' => '5MB',
      'max_resolution' => '1600x1600',
      'min_resolution' => '',
      'title_field' => 1,
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
            'remote' => 'remote',
            'upload' => 'upload',
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
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__adaptive' => 0,
          'colorbox__large' => 0,
          'colorbox__medium' => 0,
          'colorbox__orizzontally_croppable_image' => 0,
          'colorbox__square_cropped_image' => 0,
          'colorbox__threshold-480' => 0,
          'colorbox__threshold-768' => 0,
          'colorbox__threshold-992' => 0,
          'colorbox__threshold-1382' => 0,
          'colorbox__thumbnail' => 0,
          'colorbox__vertically_cropabble_image' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_adaptive' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_orizzontally_croppable_image' => 0,
          'image_square_cropped_image' => 0,
          'image_threshold-480' => 0,
          'image_threshold-768' => 0,
          'image_threshold-992' => 0,
          'image_threshold-1382' => 0,
          'image_thumbnail' => 0,
          'image_vertically_cropabble_image' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'medium',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-immagine_georiferita-field_in_evidenza'
  $field_instances['node-immagine_georiferita-field_in_evidenza'] = array(
    'bundle' => 'immagine_georiferita',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Indicare se questa Immagine Risulta essere in evidenza all\'interno del contenuto a cui è associata',
    'display' => array(
      'anteprima_immagine_georiferita' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_in_evidenza',
    'label' => 'In evidenza',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-immagine_georiferita-field_nome_location'
  $field_instances['node-immagine_georiferita-field_nome_location'] = array(
    'bundle' => 'immagine_georiferita',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anteprima_immagine_georiferita' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'title',
        'settings' => array(
          'title_class' => '',
          'title_link' => '',
          'title_style' => '',
        ),
        'type' => 'title_linked',
        'weight' => 8,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_nome_location',
    'label' => 'Nome Location',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'geocoded_field_delta' => NULL,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-immagine_georiferita-field_notizia_tc'
  $field_instances['node-immagine_georiferita-field_notizia_tc'] = array(
    'bundle' => 'immagine_georiferita',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Il contenuto Touring Club a cui l\'Immagine è associata',
    'display' => array(
      'anteprima_immagine_georiferita' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_notizia_tc',
    'label' => 'Notizia TC',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-immagine_georiferita-field_position'
  $field_instances['node-immagine_georiferita-field_position'] = array(
    'bundle' => 'immagine_georiferita',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anteprima_immagine_georiferita' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_position',
    'label' => 'Position',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-immagine_georiferita-field_tag_location'
  $field_instances['node-immagine_georiferita-field_tag_location'] = array(
    'bundle' => 'immagine_georiferita',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'anteprima_immagine_georiferita' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_tag_location',
    'label' => 'Tag Location',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'autocomplete_deluxe',
      'settings' => array(
        'autocomplete_deluxe_path' => 'autocomplete_deluxe/taxonomy',
        'content_taxonomy_autocomplete_new_terms' => 'allow',
        'delimiter' => '',
        'limit' => 10,
        'min_length' => 0,
        'size' => 60,
      ),
      'type' => 'autocomplete_deluxe_taxonomy',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-immagine_georiferita-title_field'
  $field_instances['node-immagine_georiferita-title_field'] = array(
    'bundle' => 'immagine_georiferita',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Il campo Titolo dell\'immagine andrà a determinare l\'attributo title dell\'Immagine stessa',
    'display' => array(
      'anteprima_immagine_georiferita' => array(
        'label' => 'hidden',
        'module' => 'title',
        'settings' => array(
          'title_class' => '',
          'title_link' => 'content',
          'title_style' => '_none',
        ),
        'type' => 'title_linked',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'title_field',
    'label' => 'Titolo',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'hide_label' => array(
        'entity' => 0,
        'page' => 0,
      ),
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
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Autore TC');
  t('Didascalia Foto');
  t('Geofield');
  t('Il campo Titolo dell\'immagine andrà a determinare l\'attributo title dell\'Immagine stessa');
  t('Il contenuto Touring Club a cui l\'Immagine è associata');
  t('Immagine');
  t('In evidenza');
  t('Indicare se questa Immagine Risulta essere in evidenza all\'interno del contenuto a cui è associata');
  t('Nome Location');
  t('Notizia TC');
  t('Position');
  t('Tag Location');
  t('Titolo');

  return $field_instances;
}
