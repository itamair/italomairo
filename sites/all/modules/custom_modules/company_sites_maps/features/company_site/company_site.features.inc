<?php
/**
 * @file
 * company_site.features.inc
 */

/**
 * Implements hook_node_info().
 */
function company_site_node_info() {
  $items = array(
    'company_site' => array(
      'name' => t('Company Site'),
      'base' => 'node_content',
      'description' => t('A company site with its geolocation, category and tipology'),
      'has_title' => '1',
      'title_label' => t('Titolo'),
      'help' => '',
    ),
  );
  return $items;
}
