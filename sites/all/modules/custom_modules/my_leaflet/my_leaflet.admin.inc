<?php

/**
 * Function to display the getlocations admin settings form
 * @return
 *   Returns the form.
 */
function my_leaflet_settings_form() {
  
  $defaults = my_leaflet_defaults();

  $form = array();

  $form['my_leaflet_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Alters the Leaflet and Leaflet Markecluster Module JS loaded Files'),
    '#description' => t('Choose to load the original JS files or the one in this module\'s ones'),
    // This will store all the defaults in one variable.
    '#tree' => TRUE,
  );

    $my_leaflet_settings = variable_get('my_leaflet_settings', array());

    $form['my_leaflet_settings']['leaflet_js_override'] = array(
			'#type' => 'select',
      '#default_value' => (!empty($my_leaflet_settings['leaflet_js_override'])) ? $my_leaflet_settings['leaflet_js_override'] : $defaults['leaflet_js_override'],
      '#options' => array('1'=>'Yes', '0' => 'No'),
      '#attributes' => array('id' => 'override_leaflet-js-override'),
      '#title' => 'Override Leaflet Module original JS file',
      '#description' => t('Specify if you want to override (or not) the Leaflet Module original JS file with the one stored in this My Leaflet Module one'),
    );
    
    $form['my_leaflet_settings']['leaflet_markecluster_js_override'] = array(
			'#type' => 'select',
      '#default_value' => (!empty($my_leaflet_settings['leaflet_markecluster_js_override'])) ? $my_leaflet_settings['leaflet_markecluster_js_override'] : $defaults['leaflet_markecluster_js_override'],
      '#options' => array('1'=>'Yes', '0' => 'No'),
      '#attributes' => array('id' => 'override_leaflet-js-override'),
      '#title' => 'Override Leaflet Markecluster original JS file',
      '#description' => t('Specify if you want to override (or not) the Leaflet Markecluster Module original JS file with the one stored in this My Leaflet Module one'),
    );
    
    //dpm($form);
    
    return system_settings_form($form);
  
}