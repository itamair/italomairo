<?php
/**
 * @file
 * crea_contenuto_articolo.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function crea_contenuto_articolo_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'request_information_on_this_item' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'service_links_displays_group' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'sld_group_text',
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
      'weight' => '2',
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
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'service_links_displays_group' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'sld_group_text',
    ),
  );
  $export['node|article|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function crea_contenuto_articolo_ds_custom_fields_info() {
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
if (isset($entity->field_campo_richiesta_more_info) && isset($entity->field_campo_richiesta_more_info[\'und\']) && $entity->field_campo_richiesta_more_info[\'und\'][0][\'value\'] == \'1\') {
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
function crea_contenuto_articolo_ds_layout_settings_info() {
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
        1 => 'field_category',
        2 => 'title',
        3 => 'field_sottottolo',
        4 => 'field_fonte',
        5 => 'field_image',
        6 => 'body',
        7 => 'field_attachment',
        8 => 'field_website',
        9 => 'field_tags',
        10 => 'service_links_displays_group',
        11 => 'request_information_on_this_item',
        12 => 'field_copyright_warning',
        13 => 'comments',
      ),
    ),
    'fields' => array(
      'field_data_di_pubblicazione' => 'ds_content',
      'field_category' => 'ds_content',
      'title' => 'ds_content',
      'field_sottottolo' => 'ds_content',
      'field_fonte' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
      'field_attachment' => 'ds_content',
      'field_website' => 'ds_content',
      'field_tags' => 'ds_content',
      'service_links_displays_group' => 'ds_content',
      'request_information_on_this_item' => 'ds_content',
      'field_copyright_warning' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
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
        1 => 'field_category',
        2 => 'title',
        3 => 'field_sottottolo',
        4 => 'field_fonte',
        5 => 'field_image',
        6 => 'body',
        7 => 'service_links_displays_group',
        8 => 'request_information_on_this_item',
        9 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_data_di_pubblicazione' => 'ds_content',
      'field_category' => 'ds_content',
      'title' => 'ds_content',
      'field_sottottolo' => 'ds_content',
      'field_fonte' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
      'service_links_displays_group' => 'ds_content',
      'request_information_on_this_item' => 'ds_content',
      'node_link' => 'ds_content',
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
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function crea_contenuto_articolo_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'just_title_subtitle_body_summary';
  $ds_view_mode->label = 'Just Title Subtitle Body Summary';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['just_title_subtitle_body_summary'] = $ds_view_mode;

  return $export;
}
