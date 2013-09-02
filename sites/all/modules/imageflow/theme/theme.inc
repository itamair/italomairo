<?php
/**
 * @file
 * Theming functions for the imageflow module.
 */

/**
 * Template preprocess handler for 'imageflow_container' theme.
 */
function template_preprocess_imageflow_container(&$vars) {
  // Each imageflow instance gets a unique id
  $imageflow_id = &drupal_static('imageflow_id', 0);
  $vars['id'] = ++$imageflow_id;

  // Load the used preset.
  if (!empty($vars['settings']['imageflow_preset'])) {
    $preset = imageflow_preset_load($vars['settings']['imageflow_preset']);
  }
  if (empty($preset)) {
    $preset = imageflow_preset_load('default');
  }

  // Attach imageflow JavaScript.
  imageflow_add_js($imageflow_id, $preset);

  // Prepare image elements.
  $items = $vars['items'];
  $vars['items'] = array();
  $image_style = empty($preset['imagestyle']) ? 'medium' : $preset['imagestyle'];
  foreach ($items as $delta => $item) {
    // Link to image file as default fallback.
    if (!isset($item['attributes']['longdesc'])) {
      $item['attributes']['longdesc'] = file_create_url($item['uri']);
    }
    $vars['imageflow'][$delta] = array(
      '#theme' => 'imageflow_image_formatter',
      '#item' => $item,
      '#image_style' => $image_style,
    );
  }
}

/**
 * Theme 'views_view_imageflow'.
 */
function theme_views_view_imageflow($vars) {
  $items = array();

  $view = $vars['view'];
  $img_field_name = $vars['img_field_name'];
  $link_field_name = $vars['link_field_name'];
  foreach ($vars['rows'] as $row) {
    $lang = $row->_field_data[$view->base_field]['entity']->language;
    if (!isset($row->_field_data[$view->base_field]['entity']->{$img_field_name})) {
      continue;
    }
    $item = $row->_field_data[$view->base_field]['entity']->{$img_field_name}[$lang][0];
    if (isset($row->_field_data[$view->base_field]['entity']->{$link_field_name})) {
      $item['attributes']['longdesc'] = $row->_field_data[$view->base_field]['entity']->{$link_field_name}[$lang][0]['url'];
    }
    $items[] = $item;
  }

  return theme('imageflow_container', array(
    'items' => $items,
    'settings' => $vars['options'],
  ));
}

function theme_imageflow_image_formatter($variables) {
  $item = $variables['item'];
  $image = array(
    'path' => $item['uri'], 
    'alt' => $item['alt'],
  );

  if (isset($item['attributes'])) {
    $image['attributes'] = $item['attributes'];
  }

  if (isset($item['width']) && isset($item['height'])) {
    $image['width'] = $item['width'];
    $image['height'] = $item['height'];
  }

  // Do not output an empty 'title' attribute.
  if (drupal_strlen($item['title']) > 0) {
    $image['title'] = $item['title'];
  }

  if ($variables['image_style']) {
    $image['style_name'] = $variables['image_style'];
    $output = theme('imageflow_image_style', $image);
  }
  else {
    $output = theme('imageflow_image', $image);
  }

  return $output;
}

/**
 * Theme 'imageflow_image_style'.
 */
function theme_imageflow_image_style($variables) {
  // Determine the dimensions of the styled image.
  $dimensions = array(
    'width' => $variables['width'], 
    'height' => $variables['height'],
  );

  image_style_transform_dimensions($variables['style_name'], $dimensions);

  $variables['width'] = $dimensions['width'];
  $variables['height'] = $dimensions['height'];

  // Determine the url for the styled image.
  // Base path gets stripped out for the reflect script.
  $variables['path'] = image_style_url($variables['style_name'], $variables['path']);
  $variables['path'] = str_replace ($GLOBALS['base_url'], '', $variables['path']);
  return theme('imageflow_image', $variables);
}

/**
 * Theme 'imageflow_image'.
 */
function theme_imageflow_image($variables) {
  $attributes = $variables['attributes'];
  $attributes['src'] = $variables['path'];

  foreach (array('width', 'height', 'alt', 'title') as $key) {

    if (isset($variables[$key])) {
      $attributes[$key] = $variables[$key];
    }
  }

  return '<img' . drupal_attributes($attributes) . ' />';
}
