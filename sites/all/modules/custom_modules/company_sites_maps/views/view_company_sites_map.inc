<?php

$view = new view();
$view->name = 'company_sites_map';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Company Sites Map (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Geoimages';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'leggi tutto';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'ip_geoloc_leaflet';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => '',
    'rendered' => 1,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['style_options']['ip_geoloc_views_plugin_latitude'] = 'field_site_geofield';
$handler->display->display_options['style_options']['ip_geoloc_views_plugin_longitude'] = 'field_site_geofield';
$handler->display->display_options['style_options']['center_option'] = '0';
$handler->display->display_options['style_options']['map'] = 'google-terrain';
$handler->display->display_options['style_options']['map_height'] = '400';
$handler->display->display_options['style_options']['cluster_radius'] = '0';
$handler->display->display_options['style_options']['tooltips']['marker_tooltip'] = 'title';
$handler->display->display_options['style_options']['map_options']['maxzoom'] = '18';
$handler->display->display_options['style_options']['map_options']['zoom'] = '2';
$handler->display->display_options['style_options']['map_options']['scrollwheelzoom'] = '1';
$handler->display->display_options['style_options']['map_options']['dragging'] = '1';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Geofield Name */
$handler->display->display_options['fields']['field_geofield_name']['id'] = 'field_geofield_name';
$handler->display->display_options['fields']['field_geofield_name']['table'] = 'field_data_field_geofield_name';
$handler->display->display_options['fields']['field_geofield_name']['field'] = 'field_geofield_name';
$handler->display->display_options['fields']['field_geofield_name']['label'] = 'Location';
$handler->display->display_options['fields']['field_geofield_name']['exclude'] = TRUE;
/* Campo: Contenuto: Geolocation  */
$handler->display->display_options['fields']['field_site_geofield']['id'] = 'field_site_geofield';
$handler->display->display_options['fields']['field_site_geofield']['table'] = 'field_data_field_site_geofield';
$handler->display->display_options['fields']['field_site_geofield']['field'] = 'field_site_geofield';
$handler->display->display_options['fields']['field_site_geofield']['label'] = '';
$handler->display->display_options['fields']['field_site_geofield']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_site_geofield']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_site_geofield']['click_sort_column'] = 'wkt';
$handler->display->display_options['fields']['field_site_geofield']['type'] = 'geofield_latlon';
$handler->display->display_options['fields']['field_site_geofield']['settings'] = array(
  'data' => 'full',
  'format' => 'decimal_degrees',
  'labels' => 1,
);
/* Campo: Contenuto: Link modifica */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = '';
$handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
$handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
/* Campo: Globale: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div>
<div class="title">[title]</div>
<div class="body">[body]</div>
<div class="latlng">[field_site_geofield]</div>
<div class="links">[edit_node]</div>
</div>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Criterio di ordinamento: Contenuto: Data di inserimento */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Contenuto: Pubblicato */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Contenuto: Tipo */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company_site' => 'company_site',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'company-sites-map';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Company Sites Map';
$handler->display->display_options['menu']['weight'] = '19';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['company_sites_map'] = array(
  t('Master'),
  t('Geoimages'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('Location'),
  t('<div>
<div class="title">[title]</div>
<div class="body">[body]</div>
<div class="latlng">[field_site_geofield]</div>
<div class="links">[edit_node]</div>
</div>'),
  t('Page'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;