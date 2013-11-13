<?php
/**
 * @file
 * crea_contenuto_mio_progetto_articolo.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function crea_contenuto_mio_progetto_articolo_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'request_information_on_this_item' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'service_links_displays_group' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'sld_group_text',
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|article|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'request_information_on_this_item' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'links' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'service_links_displays_group' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'sld_group_text',
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|article|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|my_project|anteprima_my_project';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'my_project';
  $ds_fieldsetting->view_mode = 'anteprima_my_project';
  $ds_fieldsetting->settings = array(
    'request_information_on_this_item' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'service_links_displays_facebook_like' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'sld_single_text',
    ),
  );
  $export['node|my_project|anteprima_my_project'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|my_project|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'my_project';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'request_information_on_this_item' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'service_links_displays_group' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'sld_group_text',
    ),
  );
  $export['node|my_project|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|my_project|flexslider';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'my_project';
  $ds_fieldsetting->view_mode = 'flexslider';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'node_link' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|my_project|flexslider'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|my_project|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'my_project';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'request_information_on_this_item' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'service_links_displays_group' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'sld_group_text',
    ),
    'field_mese_pubblicazione' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|my_project|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function crea_contenuto_mio_progetto_articolo_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'request_information_on_this_item';
  $ds_field->label = 'Request Information on this item';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php 
global $base_url, $language;
$lng = $language->language;
if (!user_is_logged_in() && (isset($entity->field_campo_richiesta_more_info) && isset($entity->field_campo_richiesta_more_info[\'und\'])) && $entity->field_campo_richiesta_more_info[\'und\'][0][\'value\'] == \'1\') {
echo \'<div class="request-mor-info float-right"><a href="\'.$base_url.\'/\'.$lng.\'/node/84/request_info_for/[node:nid]/[node:title-field]">\'. t("Request More Information on this content").\'</a></div>\'; 
}
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['request_information_on_this_item'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function crea_contenuto_mio_progetto_articolo_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_data_di_pubblicazione',
        1 => 'title',
        2 => 'field_sottottolo',
        3 => 'field_category',
        4 => 'field_image',
        5 => 'body',
        6 => 'field_website',
        7 => 'field_tags',
        8 => 'links',
        9 => 'service_links_displays_group',
        10 => 'request_information_on_this_item',
        11 => 'comments',
      ),
    ),
    'fields' => array(
      'field_data_di_pubblicazione' => 'ds_content',
      'title' => 'ds_content',
      'field_sottottolo' => 'ds_content',
      'field_category' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
      'field_website' => 'ds_content',
      'field_tags' => 'ds_content',
      'links' => 'ds_content',
      'service_links_displays_group' => 'ds_content',
      'request_information_on_this_item' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|article|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_data_di_pubblicazione',
        1 => 'title',
        2 => 'field_sottottolo',
        3 => 'field_category',
        4 => 'field_image',
        5 => 'body',
        6 => 'links',
        7 => 'service_links_displays_group',
        8 => 'request_information_on_this_item',
      ),
    ),
    'fields' => array(
      'field_data_di_pubblicazione' => 'ds_content',
      'title' => 'ds_content',
      'field_sottottolo' => 'ds_content',
      'field_category' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
      'links' => 'ds_content',
      'service_links_displays_group' => 'ds_content',
      'request_information_on_this_item' => 'ds_content',
    ),
    'limit' => array(
      'field_image' => '1',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|article|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|my_project|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'my_project';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_category',
        1 => 'field_mese_pubblicazione',
        2 => 'field_cover_images',
        3 => 'field_committente',
        4 => 'body',
        5 => 'immagini_aggiuntive_entity_view_2',
        6 => 'group_immagini',
        7 => 'field_video',
        8 => 'field_attachment',
        9 => 'field_link',
        10 => 'field_tags',
        11 => 'service_links_displays_group',
        12 => 'request_information_on_this_item',
      ),
    ),
    'fields' => array(
      'field_category' => 'ds_content',
      'field_mese_pubblicazione' => 'ds_content',
      'field_cover_images' => 'ds_content',
      'field_committente' => 'ds_content',
      'body' => 'ds_content',
      'immagini_aggiuntive_entity_view_2' => 'ds_content',
      'group_immagini' => 'ds_content',
      'field_video' => 'ds_content',
      'field_attachment' => 'ds_content',
      'field_link' => 'ds_content',
      'field_tags' => 'ds_content',
      'service_links_displays_group' => 'ds_content',
      'request_information_on_this_item' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|my_project|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|my_project|flexslider';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'my_project';
  $ds_layout->view_mode = 'flexslider';
  $ds_layout->layout = 'my_project_preview';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_category',
        1 => 'title',
        2 => 'field_mese_pubblicazione',
      ),
      'left' => array(
        3 => 'field_cover_images',
      ),
      'right' => array(
        4 => 'body',
        5 => 'field_committente',
        6 => 'field_tags',
        7 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_category' => 'header',
      'title' => 'header',
      'field_mese_pubblicazione' => 'header',
      'field_cover_images' => 'left',
      'body' => 'right',
      'field_committente' => 'right',
      'field_tags' => 'right',
      'node_link' => 'right',
    ),
    'limit' => array(
      'field_cover_images' => '1',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|my_project|flexslider'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|my_project|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'my_project';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'my_project_preview';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_mese_pubblicazione',
        1 => 'title',
      ),
      'left' => array(
        2 => 'field_cover_images',
        3 => 'immagini_aggiuntive_entity_view_1',
      ),
      'right' => array(
        4 => 'body',
        5 => 'field_committente',
        6 => 'field_link',
        7 => 'field_tags',
        8 => 'node_link',
        9 => 'service_links_displays_group',
        10 => 'request_information_on_this_item',
      ),
    ),
    'fields' => array(
      'field_mese_pubblicazione' => 'header',
      'title' => 'header',
      'field_cover_images' => 'left',
      'immagini_aggiuntive_entity_view_1' => 'left',
      'body' => 'right',
      'field_committente' => 'right',
      'field_link' => 'right',
      'field_tags' => 'right',
      'node_link' => 'right',
      'service_links_displays_group' => 'right',
      'request_information_on_this_item' => 'right',
    ),
    'limit' => array(
      'field_cover_images' => '1',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['node|my_project|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function crea_contenuto_mio_progetto_articolo_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'anteprima_my_project';
  $ds_view_mode->label = 'Anteprima My Project';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['anteprima_my_project'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'flexslider';
  $ds_view_mode->label = 'Flexslider';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['flexslider'] = $ds_view_mode;

  return $export;
}
