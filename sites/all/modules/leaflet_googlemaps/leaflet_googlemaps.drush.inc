<?php

/**
 * @file
 *   drush integration for leaflet_googlemaps.
 */

/**
 * The Leaflet plugins URI.
 */
define('LEAFLET_PLUGINS_GIT_PATH', 'https://github.com/shramov/leaflet-plugins.git');
define('LEAFLET_PLUGINS_LIBRARIES_FOLDER', 'leaflet-plugins');

/**
 * Implements hook_drush_command().
 */
function leaflet_googlemaps_drush_command() {
  $items = array();

  $items['leaflet-plugins-download'] = array(
    'callback' => 'drush_leaflet_plugins_download',
    'description' => dt("Downloads Leaflet plugins library."),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(
      'path' => dt('Optional. A path where to install library. If omitted Drush will use the default location.'),
    ),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function leaflet_googlemaps_drush_help($section) {
  switch ($section) {
    case 'drush:leaflet-plugins-download':
      return dt("Downloads Leaflet plugins, default location is sites/all/libraries.");
  }
}

/**
 * Implements drush_MODULE_post_COMMAND().
 */
function drush_leaflet_googlemaps_post_enable() {
  $modules = func_get_args();
  if (in_array('leaflet_googlemaps', $modules)) {
    drush_leaflet_plugins_download();
  }
}

/**
 * Command to download the library.
 */
function drush_leaflet_plugins_download() {
  $args = func_get_args();
  $destiny = !empty($args[0]) ? $args[0] : 'sites/all/libraries';

  // In case it already exists
  if (is_dir($destiny . '/' . LEAFLET_PLUGINS_LIBRARIES_FOLDER)) {
    return;
  }

  // Check required tools existence
  if (!drush_shell_exec('type git')) {
    return drush_set_error(dt('Missing dependency: git. Install it before using this command.'));
  }

  // Create the path if it does not exist.
  if (!is_dir($destiny)) {
    drush_op('mkdir', $destiny);
    drush_log(dt('Directory @path was created', array('@path' => $destiny)), 'notice');
  }

  // Set the directory to the download location.
  $origin = getcwd();
  chdir($destiny);

  // Decompress the library
  drush_shell_exec('git clone ' . LEAFLET_PLUGINS_GIT_PATH . ' ' . LEAFLET_PLUGINS_LIBRARIES_FOLDER);
  // Remove the library
  drush_shell_exec('rm -rf ' . LEAFLET_PLUGINS_LIBRARIES_FOLDER . '/.git');

  // Set working directory back to the previous working directory.
  chdir($origin);

  if (is_dir($destiny . '/' . LEAFLET_PLUGINS_LIBRARIES_FOLDER)) {
    drush_log(dt('Leaflet plugins library has been downloaded to @path', array('@path' => $destiny)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to download the Leaflet plugins library to @path', array('@path' => $destiny)), 'error');
  }
}
