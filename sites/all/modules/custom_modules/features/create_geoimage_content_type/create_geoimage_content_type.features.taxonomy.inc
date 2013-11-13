<?php
/**
 * @file
 * create_geoimage_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function create_geoimage_content_type_taxonomy_default_vocabularies() {
  return array(
    'elenco_autori' => array(
      'name' => 'Elenco Autori',
      'machine_name' => 'elenco_autori',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tag_location' => array(
      'name' => 'Tag Location',
      'machine_name' => 'tag_location',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
