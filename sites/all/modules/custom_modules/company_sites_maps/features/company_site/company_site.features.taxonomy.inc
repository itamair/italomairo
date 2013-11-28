<?php
/**
 * @file
 * company_site.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function company_site_taxonomy_default_vocabularies() {
  return array(
    'site_category' => array(
      'name' => 'Site Category',
      'machine_name' => 'site_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
