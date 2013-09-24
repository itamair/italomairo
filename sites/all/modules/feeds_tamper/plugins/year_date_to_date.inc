<?php

/**
 * @file
 * Encode YEAR DATE (like 2009) in a PHP Date.
 */

$plugin = array(
  'form' => 'feeds_tamper_year_date_to_date_form',
  'callback' => 'feeds_tamper_year_date_to_date_callback',
  'name' => 'YEAR Date to Date',
  'multi' => 'loop',
  'category' => 'Date',
);

function feeds_tamper_year_date_to_date_form($importer, $element_key, $settings) {
  $form = array();
  $form['html'] = array(
    '#markup' => t('This will convert a Year Date like "2009" into Date')
  );
  return $form;
}

function feeds_tamper_year_date_to_date_callback($result, $item_key, $element_key, &$field, $settings) {
  if(is_numeric($field) && checkdate("1", "1", $field)) {
    $field =$field."-1-1 00:00:00";
    $date = strtotime($field);
    $field = date('Y-m-d H:i:s', $date);
  } else $field = null;
      //dpm($field);
}

