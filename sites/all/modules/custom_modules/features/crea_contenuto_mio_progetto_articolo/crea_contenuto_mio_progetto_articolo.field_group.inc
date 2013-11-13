<?php
/**
 * @file
 * crea_contenuto_mio_progetto_articolo.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crea_contenuto_mio_progetto_articolo_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_esposizione_home_blog|node|my_project|form';
  $field_group->group_name = 'group_esposizione_home_blog';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'my_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Esposizione del contenuto in Home',
    'weight' => '12',
    'children' => array(
      0 => 'field_in_home_page',
      1 => 'field_in_slideshow',
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
  $export['group_esposizione_home_blog|node|my_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_immagini|node|my_project|default';
  $field_group->group_name = 'group_immagini';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'my_project';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '5',
    'children' => array(
      0 => 'immagini_aggiuntive_entity_view_2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Images',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_immagini|node|my_project|default'] = $field_group;

  return $export;
}
