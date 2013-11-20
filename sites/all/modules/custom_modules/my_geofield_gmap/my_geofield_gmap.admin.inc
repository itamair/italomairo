<?php

/**
 * Hook_settings_form
 * @return
 *   Returns the form.
 */
function my_geofield_gmap_settings_form() {
  
  $defaults = my_geofield_gmap_defaults();

  $form = array();
  
  $my_geofield_gmap_settings = variable_get('my_geofield_gmap_setup', array());
  //dpm($my_geofield_gmap_settings);
  
  $entity_type = 'node';
  
  $entity_fields = field_info_fields();
  //dpm($entity_fields); //Debug
  
  $geolocation_fields_options = array(NULL => 'any');

  /*** First we check if there is a getlocations field, and store it in the $geocoded_field variable ****/
  foreach ($entity_fields as $this_field) {
      //dpm($this_field);
      if ($this_field['type'] == 'text') {
         $geolocation_fields_options[$this_field['field_name']] = $this_field['field_name'];
      }
  }
  
  //dpm($geolocation_fields_options); //Debug


  $form['my_geofield_gmap_setup'] = array(
      '#type' => 'fieldset',
      '#title' => t('My Geofield GMap Specific Setups'),
      '#description' => t('The settings here will provide specific additional settings for the My Geofield GMap module.'),
      // This will store all the defaults in one variable.
      '#tree' => TRUE,
  );

  //$form['my_geofield_gmap_setup']['my_geocoded_field'] = array(
  //    '#type' => 'textfield',
  //    '#default_value' => (isset($my_geofield_gmap_settings['my_geocoded_field'])) ? $my_geofield_gmap_settings['my_geocoded_field'] : $defaults['geocoded_field'],
  //    '#size' => 20,
  //    '#title' => 'Geocoded Field',
  //    '#maxlength' => 60,
  //    '#description' => t('Specify the machine name of the field that should be written with the output address of the Geofield, a general setup of the site'),
  //);
  
  $form['my_geofield_gmap_setup']['my_geocoded_field'] = array(
      '#type' => 'select',
      '#default_value' => (isset($my_geofield_gmap_settings['my_geocoded_field'])) ? $my_geofield_gmap_settings['my_geocoded_field'] : $defaults['geocoded_field'],
      '#size' => 0,
      '#title' => 'Geocoded Field',
      '#maxlength' => 60,
      '#description' => t('Specify the machine name of the field that should be written with the output address of the Geofield, a general setup of the site'),
      '#options' => $geolocation_fields_options,
  );

    //dpm($form);
    
    return system_settings_form($form);
  
}

/**
 * Hook_settings_form_validate
 */
function my_geofield_gmap_settings_form_validate ($form, &$form_state) {
  
}