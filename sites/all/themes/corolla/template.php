<?php
// Corolla by Adaptivethemes.com

/**
 * Override or insert vars into the html template.
 */
function corolla_preprocess_html(&$vars) {
  global $theme_key;
  $theme_name = $theme_key;

  // Add a class for the active color scheme
  if (module_exists('color')) {
    $class = check_plain(get_color_scheme_name($theme_name));
    $vars['classes_array'][] = 'color-scheme-' . drupal_html_class($class);
  }

  // Add class for the active theme
  $vars['classes_array'][] = drupal_html_class($theme_name);

  // Add theme settings classes
  $settings_array = array(
    'box_shadows',
    'body_background',
    'menu_bullets',
    'content_corner_radius',
    'tabs_corner_radius',
  );
  foreach ($settings_array as $setting) {
    $vars['classes_array'][] = at_get_setting($setting);
  }
  
}

/**
 * Hook into the color module.
 */
function corolla_process_html(&$vars) {
  if (module_exists('color')) {
    _color_html_alter($vars);
  }
}
function corolla_process_page(&$vars) {
  if (module_exists('color')) {
    _color_page_alter($vars);
  } 

}

/**
 * Override or insert vars into the block template.
 */
function corolla_preprocess_block(&$vars) {
  if ($vars['block']->module == 'superfish' || $vars['block']->module == 'nice_menu') {
    $vars['content_attributes_array']['class'][] = 'clearfix';
  }
  if ($vars['block']->region == 'menu_bar' || $vars['block']->region == 'header') {
    $vars['title_attributes_array']['class'][] = 'element-invisible';
  }
}

/**
 * Returns HTML for a sort icon.
 *
 * @param $vars
 *   An associative array containing:
 *   - style: Set to either 'asc' or 'desc', this determines which icon to show.
 */
function corolla_tablesort_indicator($vars) {
  // Use custom arrow images.
  if ($vars['style'] == 'asc') {
    return theme('image', array('path' => path_to_theme() . '/css/images/tablesort-ascending.png', 'alt' => t('sort ascending'), 'title' => t('sort ascending')));
  }
  else {
    return theme('image', array('path' => path_to_theme() . '/css/images/tablesort-descending.png', 'alt' => t('sort descending'), 'title' => t('sort descending')));
  }
}

/**
 * Returns HTML for a fieldset form element and its children.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #attributes, #children, #collapsed, #collapsible,
 *     #description, #id, #title, #value.
 *
 * @ingroup themeable
 */
function corolla_fieldset($vars) {

  $element = $vars['element'];
  element_set_attributes($element, array('id'));
  _form_set_class($element, array('form-wrapper'));

  $output = '<fieldset' . drupal_attributes($element['#attributes']) . '>';

  // add a class to the fieldset wrapper if a legend exists, in some instances they do not
  $class = "without-legend";

  if (!empty($element['#title'])) {

    // Always wrap fieldset legends in a SPAN for CSS positioning.
    $output .= '<legend><span class="fieldset-legend">' . $element['#title'] . '</span></legend>';

    // Add a class to the fieldset wrapper if a legend exists, in some instances they do not
    $class = 'with-legend';
  }

  $output .= '<div class="fieldset-wrapper ' . $class  . '">';

  if (!empty($element['#description'])) {
    $output .= '<div class="fieldset-description">' . $element['#description'] . '</div>';
  }

  $output .= $element['#children'];

  if (isset($element['#value'])) {
    $output .= $element['#value'];
  }

  $output .= '</div>';
  $output .= "</fieldset>\n";

  return $output;
}

//* Codice precedentemente aggiunto da Italo per alterare la visualizzazione delle icone dei file Cvs Allegati in download, poi trasferito nella vista del blocco, in quanto andava ad interferire con la formattazione dei file allegati in generale (anche quelli non Cvs nel blocco) ***/

/**
 * Returns HTML for a link to a file.
 *
 * @param $variables
 *   An associative array containing:
 *   - file: A file object to which the link will be created.
 *   - icon_directory: (optional) A path to a directory of icons to be used for
 *     files. Defaults to the value of the "file_icon_directory" variable.
 *
 * @ingroup themeable
 */
/*
 function corolla_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);
  $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  }
  else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
    $options['attributes']['target'] = "_blank";
  }

  return '<span class="file">' . $icon . ' <div class="file_text_url">' . l($link_text, $url, $options) . '</div></span>';
}
*/


/**
 * Returns HTML for an image with an appropriate icon for the given file.
 *
 * @param $variables
 *   An associative array containing:
 *   - file: A file object for which to make an icon.
 *   - icon_directory: (optional) A path to a directory of icons to be used for
 *     files. Defaults to the value of the "file_icon_directory" variable.
 *
 * @ingroup themeable
 */
/*
function corolla_file_icon($variables) {
  $file = $variables['file'];
  $url = (module_exists('file_force')) ? file_force_create_url($file->uri) : file_create_url($file->uri);
  $icon_directory = $variables['icon_directory'];

  $mime = check_plain($file->filemime);
  $icon_url = file_icon_url($file, $icon_directory);
  return '<div class="file_icon"><a href="'.$url.'" ><img class="file-icon" alt="" title="' . $mime . '" src="' . $icon_url . '" width="50px" /></a></div>';
}
*/
