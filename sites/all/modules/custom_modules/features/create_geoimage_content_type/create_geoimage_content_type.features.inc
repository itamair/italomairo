<?php
/**
 * @file
 * create_geoimage_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function create_geoimage_content_type_node_info() {
  $items = array(
    'immagine_georiferita' => array(
      'name' => t('TC Geo Image'),
      'base' => 'node_content',
      'description' => t('Stores an Image with a Geofield Location, and other Touring Club specific attributes (as a Drupal node), and might be referenced by other TC Content - Types (such as TC News)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
