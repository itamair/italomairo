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
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
