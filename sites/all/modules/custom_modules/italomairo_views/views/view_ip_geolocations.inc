<?php

$view = new view();
$view->name = 'ip_geolocations';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'ip_geoloc';
$view->human_name = 'IP Geolocations (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'IP Geolocations';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'leggi tutto';
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  3 => '3',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
$handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Slittamento';
$handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
$handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
$handler->display->display_options['style_plugin'] = 'ip_geoloc_map';
$handler->display->display_options['style_options']['default_marker_color'] = 'red';
$handler->display->display_options['style_options']['center_option'] = '1';
$handler->display->display_options['style_options']['gps_roles'] = array(
  1 => '1',
  2 => '2',
  3 => 0,
);
$handler->display->display_options['style_options']['map_div_style'] = 'height:600px;';
/* Campo: IP geolocations: Indirizzo IP */
$handler->display->display_options['fields']['ip_address']['id'] = 'ip_address';
$handler->display->display_options['fields']['ip_address']['table'] = 'ip_geoloc';
$handler->display->display_options['fields']['ip_address']['field'] = 'ip_address';
/* Campo: IP geolocations: Indirizzo */
$handler->display->display_options['fields']['formatted_address']['id'] = 'formatted_address';
$handler->display->display_options['fields']['formatted_address']['table'] = 'ip_geoloc';
$handler->display->display_options['fields']['formatted_address']['field'] = 'formatted_address';
$handler->display->display_options['fields']['formatted_address']['label'] = '';
$handler->display->display_options['fields']['formatted_address']['element_type'] = 'strong';
$handler->display->display_options['fields']['formatted_address']['element_label_colon'] = FALSE;
/* Campo: IP geolocations: Latitude (WGS84 decimal) */
$handler->display->display_options['fields']['latitude']['id'] = 'latitude';
$handler->display->display_options['fields']['latitude']['table'] = 'ip_geoloc';
$handler->display->display_options['fields']['latitude']['field'] = 'latitude';
$handler->display->display_options['fields']['latitude']['label'] = 'Lat (WGS84 decimal)';
/* Campo: IP geolocations: Longitude (WGS84 decimal) */
$handler->display->display_options['fields']['longitude']['id'] = 'longitude';
$handler->display->display_options['fields']['longitude']['table'] = 'ip_geoloc';
$handler->display->display_options['fields']['longitude']['field'] = 'longitude';
$handler->display->display_options['fields']['longitude']['label'] = 'Lng (WGS84 decimal)';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'ip-geolocations';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'IP Geolocations';
$handler->display->display_options['menu']['weight'] = '10';
$handler->display->display_options['menu']['context'] = 0;

/* Display: In Allegato */
$handler = $view->new_display('attachment', 'In Allegato', 'attachment_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'ip_address' => 'ip_address',
  'formatted_address' => 'formatted_address',
  'latitude' => 'latitude',
  'longitude' => 'longitude',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'ip_address' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'formatted_address' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'latitude' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'longitude' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['displays'] = array(
  'page' => 'page',
  'default' => 0,
);
$handler->display->display_options['attachment_position'] = 'after';
$translatables['ip_geolocations'] = array(
  t('Master'),
  t('IP Geolocations'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('Voci per pagina'),
  t('- Tutto -'),
  t('Slittamento'),
  t('« prima'),
  t('‹ precedente'),
  t('seguente ›'),
  t('ultima »'),
  t('Indirizzo IP'),
  t('Lat (WGS84 decimal)'),
  t('.'),
  t(','),
  t('Lng (WGS84 decimal)'),
  t('Page'),
  t('In Allegato'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;