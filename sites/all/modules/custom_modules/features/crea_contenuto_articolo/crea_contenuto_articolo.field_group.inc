<?php
/**
 * @file
 * crea_contenuto_articolo.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crea_contenuto_articolo_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_esposizione_home_blog|node|article|form';
  $field_group->group_name = 'group_esposizione_home_blog';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Esposizione del contenuto in Home e Blog',
    'weight' => '13',
    'children' => array(
      0 => 'field_data_di_pubblicazione',
      1 => 'field_in_blog',
      2 => 'field_in_home_page',
      3 => 'field_in_slideshow',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_esposizione_home_blog|node|article|form'] = $field_group;

  return $export;
}
