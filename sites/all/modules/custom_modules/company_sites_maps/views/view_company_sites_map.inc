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
$handler->display->display_options['title'] = 'Company Sites';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'leggi tutto';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
$handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
$handler->display->display_options['style_options']['differentiator']['differentiator_field'] = 'field_site_category';
$handler->display->display_options['style_options']['default_marker_color'] = 'default';
$handler->display->display_options['style_options']['center_option'] = '0';
$handler->display->display_options['style_options']['map'] = 'google-road-high-res';
$handler->display->display_options['style_options']['map_height'] = '400';
$handler->display->display_options['style_options']['cluster_radius'] = '';
$handler->display->display_options['style_options']['tooltips']['marker_tooltip'] = 'title';
$handler->display->display_options['style_options']['map_options']['maxzoom'] = '18';
$handler->display->display_options['style_options']['map_options']['zoom'] = '12';
$handler->display->display_options['style_options']['map_options']['scrollwheelzoom'] = '1';
$handler->display->display_options['style_options']['map_options']['dragging'] = '1';
/* Intestazione: Globale: PHP */
$handler->display->display_options['header']['php']['id'] = 'php';
$handler->display->display_options['header']['php']['table'] = 'views';
$handler->display->display_options['header']['php']['field'] = 'php';
$handler->display->display_options['header']['php']['php_output'] = '<div class="map-reset"><a href="javascript:void(0)"><?php print t(\'Reset the map\'); ?></a></div>
<div class="map-legend"><a href="javascript:void(0)" title="<?php print t(\'Legend\'); ?>"><?php print t(\'Legend\'); ?></a></div>
';
/* No results behavior: Globale: PHP */
$handler->display->display_options['empty']['php']['id'] = 'php';
$handler->display->display_options['empty']['php']['table'] = 'views';
$handler->display->display_options['empty']['php']['field'] = 'php';
$handler->display->display_options['empty']['php']['empty'] = TRUE;
$handler->display->display_options['empty']['php']['php_output'] = '<?php print t(\'Any Company Sites Added Yet. The Company Sites Map cannot be generated\') ?>
';
/* Relazione: Contenuto: Categoria (field_site_category) */
$handler->display->display_options['relationships']['field_site_category_tid']['id'] = 'field_site_category_tid';
$handler->display->display_options['relationships']['field_site_category_tid']['table'] = 'field_data_field_site_category';
$handler->display->display_options['relationships']['field_site_category_tid']['field'] = 'field_site_category_tid';
$handler->display->display_options['relationships']['field_site_category_tid']['required'] = TRUE;
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Campo: Contenuto: Tipo */
$handler->display->display_options['fields']['field_site_type']['id'] = 'field_site_type';
$handler->display->display_options['fields']['field_site_type']['table'] = 'field_data_field_site_type';
$handler->display->display_options['fields']['field_site_type']['field'] = 'field_site_type';
$handler->display->display_options['fields']['field_site_type']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_site_type']['delta_offset'] = '0';
/* Campo: Contenuto: Categoria */
$handler->display->display_options['fields']['field_site_category']['id'] = 'field_site_category';
$handler->display->display_options['fields']['field_site_category']['table'] = 'field_data_field_site_category';
$handler->display->display_options['fields']['field_site_category']['field'] = 'field_site_category';
$handler->display->display_options['fields']['field_site_category']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_site_category']['type'] = 'i18n_taxonomy_term_reference_plain';
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
<div class="type">[field_site_type]</div>
<div class="category">[field_site_category]</div>
<div class="body">[body]</div>
<div class="latlng">[field_site_geofield]</div>
<div class="links">[edit_node]</div>
</div>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Criterio di ordinamento: Draggableviews: Peso */
$handler->display->display_options['sorts']['weight']['id'] = 'weight';
$handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
$handler->display->display_options['sorts']['weight']['field'] = 'weight';
$handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'company_sites_map:page_1';
$handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
/* Criterio di ordinamento: Contenuto: Nid */
$handler->display->display_options['sorts']['nid']['id'] = 'nid';
$handler->display->display_options['sorts']['nid']['table'] = 'node';
$handler->display->display_options['sorts']['nid']['field'] = 'nid';
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
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Contenuto: Tipo (field_site_type) */
$handler->display->display_options['filters']['field_site_type_value']['id'] = 'field_site_type_value';
$handler->display->display_options['filters']['field_site_type_value']['table'] = 'field_data_field_site_type';
$handler->display->display_options['filters']['field_site_type_value']['field'] = 'field_site_type_value';
$handler->display->display_options['filters']['field_site_type_value']['value'] = array(
  'sales' => 'sales',
  'service' => 'service',
);
$handler->display->display_options['filters']['field_site_type_value']['group'] = 1;
$handler->display->display_options['filters']['field_site_type_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_site_type_value']['expose']['operator_id'] = 'field_site_type_value_op';
$handler->display->display_options['filters']['field_site_type_value']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['field_site_type_value']['expose']['operator'] = 'field_site_type_value_op';
$handler->display->display_options['filters']['field_site_type_value']['expose']['identifier'] = 'field_site_type_value';
$handler->display->display_options['filters']['field_site_type_value']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_site_type_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['enabled'] = FALSE;
$handler->display->display_options['path'] = 'company-sites-map';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Company Sites Map';
$handler->display->display_options['menu']['weight'] = '19';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: In Allegato Company Sites List */
$handler = $view->new_display('attachment', 'In Allegato Company Sites List', 'attachment_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'company-sites-list';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['footer'] = FALSE;
$handler->display->display_options['defaults']['empty'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relazione: Contenuto: Categoria (field_site_category) */
$handler->display->display_options['relationships']['field_site_category_tid']['id'] = 'field_site_category_tid';
$handler->display->display_options['relationships']['field_site_category_tid']['table'] = 'field_data_field_site_category';
$handler->display->display_options['relationships']['field_site_category_tid']['field'] = 'field_site_category_tid';
$handler->display->display_options['relationships']['field_site_category_tid']['required'] = TRUE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Globale: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = '';
$handler->display->display_options['fields']['php']['exclude'] = TRUE;
$handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php
global $base_url, $language;
$lng = $language->language;
print $base_url.\'/\'.$lng;
?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
/* Campo: Termine della tassonomia: Geo Marker */
$handler->display->display_options['fields']['field_geomarker']['id'] = 'field_geomarker';
$handler->display->display_options['fields']['field_geomarker']['table'] = 'field_data_field_geomarker';
$handler->display->display_options['fields']['field_geomarker']['field'] = 'field_geomarker';
$handler->display->display_options['fields']['field_geomarker']['relationship'] = 'field_site_category_tid';
$handler->display->display_options['fields']['field_geomarker']['label'] = '';
$handler->display->display_options['fields']['field_geomarker']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_geomarker']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_geomarker']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_geomarker']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_class'] = 'site-content-title';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Campo: Contenuto: Tipo */
$handler->display->display_options['fields']['field_site_type']['id'] = 'field_site_type';
$handler->display->display_options['fields']['field_site_type']['table'] = 'field_data_field_site_type';
$handler->display->display_options['fields']['field_site_type']['field'] = 'field_site_type';
$handler->display->display_options['fields']['field_site_type']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_site_type']['delta_offset'] = '0';
/* Campo: Contenuto: Categoria */
$handler->display->display_options['fields']['field_site_category']['id'] = 'field_site_category';
$handler->display->display_options['fields']['field_site_category']['table'] = 'field_data_field_site_category';
$handler->display->display_options['fields']['field_site_category']['field'] = 'field_site_category';
$handler->display->display_options['fields']['field_site_category']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_site_category']['type'] = 'i18n_taxonomy_term_reference_plain';
/* Campo: Contenuto: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Contatti e Riferimenti */
$handler->display->display_options['fields']['field_site_contacts']['id'] = 'field_site_contacts';
$handler->display->display_options['fields']['field_site_contacts']['table'] = 'field_data_field_site_contacts';
$handler->display->display_options['fields']['field_site_contacts']['field'] = 'field_site_contacts';
$handler->display->display_options['fields']['field_site_contacts']['label'] = '';
$handler->display->display_options['fields']['field_site_contacts']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_site_contacts']['element_label_colon'] = FALSE;
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
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = '';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="site-content" nid="[nid]">
<div class="column col-1">
<div class="geomarker">[field_geomarker]</div>
</div>
<div class="column col-2">
<div class="title">[title]</div>
<div class="type">[field_site_type]</div>
<div class="category">[field_site_category]</div>
</div>
<div class="column col-3">
<div class="body">[body]</div>
</div>
<div class="column col-4">
<!--<div class="latlng">[field_site_geofield]</div>-->
<!--<div class="ordine">Ordine di Visualizz.: [field_site_order]</div>-->
<div class="contacts">[field_site_contacts]</div>
<div class="links">[edit_node]</div>
</div>
</div>';
$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
$handler->display->display_options['displays'] = array(
  'page' => 'page',
  'block_1' => 'block_1',
  'default' => 0,
);
$handler->display->display_options['attachment_position'] = 'after';
$handler->display->display_options['inherit_exposed_filters'] = TRUE;

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->display->display_options['block_description'] = 'Company Sites Map View';

/* Display: Pagina Manage Sites */
$handler = $view->new_display('page', 'Pagina Manage Sites', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Manage Company Sites';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'create company_site content';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'draggableviews' => 'draggableviews',
  'nid' => 'nid',
  'title' => 'title',
  'field_site_type' => 'field_site_type',
  'field_site_category' => 'field_site_category',
  'body' => 'body',
  'field_site_contacts' => 'field_site_contacts',
  'field_geofield_name' => 'field_geofield_name',
  'field_site_geofield' => 'field_site_geofield',
  'edit_node' => 'edit_node',
  'nothing' => 'nothing',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'draggableviews' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'nid' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_site_type' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_site_category' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'body' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_site_contacts' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_geofield_name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_site_geofield' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'edit_node' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'nothing' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Intestazione: Globale: PHP */
$handler->display->display_options['header']['php']['id'] = 'php';
$handler->display->display_options['header']['php']['table'] = 'views';
$handler->display->display_options['header']['php']['field'] = 'php';
$handler->display->display_options['header']['php']['php_output'] = '<?php print l(t(\'Add a Company Site\'), \'node/add/company-site\', array(\'query\' => array(\'destination\' => \'manage-company-sites\'))); ?>
';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Globale: PHP */
$handler->display->display_options['empty']['php']['id'] = 'php';
$handler->display->display_options['empty']['php']['table'] = 'views';
$handler->display->display_options['empty']['php']['field'] = 'php';
$handler->display->display_options['empty']['php']['empty'] = TRUE;
$handler->display->display_options['empty']['php']['php_output'] = '<?php print t(\'Any Company Sites Added Yet. The Company Sites List cannot be generated\') ?>
';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Draggableviews: Contenuto */
$handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
$handler->display->display_options['fields']['draggableviews']['table'] = 'node';
$handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
$handler->display->display_options['fields']['draggableviews']['label'] = 'Order';
$handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Name';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Campo: Contenuto: Tipo */
$handler->display->display_options['fields']['field_site_type']['id'] = 'field_site_type';
$handler->display->display_options['fields']['field_site_type']['table'] = 'field_data_field_site_type';
$handler->display->display_options['fields']['field_site_type']['field'] = 'field_site_type';
$handler->display->display_options['fields']['field_site_type']['label'] = 'Type';
$handler->display->display_options['fields']['field_site_type']['delta_offset'] = '0';
/* Campo: Contenuto: Categoria */
$handler->display->display_options['fields']['field_site_category']['id'] = 'field_site_category';
$handler->display->display_options['fields']['field_site_category']['table'] = 'field_data_field_site_category';
$handler->display->display_options['fields']['field_site_category']['field'] = 'field_site_category';
$handler->display->display_options['fields']['field_site_category']['label'] = 'Category';
$handler->display->display_options['fields']['field_site_category']['type'] = 'i18n_taxonomy_term_reference_plain';
/* Campo: Contenuto: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = 'Dett & Indirizzo';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Contatti e Riferimenti */
$handler->display->display_options['fields']['field_site_contacts']['id'] = 'field_site_contacts';
$handler->display->display_options['fields']['field_site_contacts']['table'] = 'field_data_field_site_contacts';
$handler->display->display_options['fields']['field_site_contacts']['field'] = 'field_site_contacts';
$handler->display->display_options['fields']['field_site_contacts']['label'] = 'Contatti';
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
  'labels' => 0,
);
/* Campo: Contenuto: Link modifica */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = '';
$handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
/* Campo: Globale: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div>
<div class="title">[title]</div>
<div class="type">[field_site_type]</div>
<div class="category">[field_site_category]</div>
<div class="body">[body]</div>
<div class="latlng">[field_site_geofield]</div>
<div class="links">[edit_node]</div>
</div>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['path'] = 'manage-company-sites';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Manage Company Sites';
$handler->display->display_options['menu']['weight'] = '100';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['company_sites_map'] = array(
  t('Master'),
  t('Company Sites'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('term from field_site_category'),
  t('Nid'),
  t('Tipo'),
  t('Categoria'),
  t('Location'),
  t('<div>
<div class="title">[title]</div>
<div class="type">[field_site_type]</div>
<div class="category">[field_site_category]</div>
<div class="body">[body]</div>
<div class="latlng">[field_site_geofield]</div>
<div class="links">[edit_node]</div>
</div>'),
  t('Type'),
  t('Page'),
  t('In Allegato Company Sites List'),
  t('<div class="site-content" nid="[nid]">
<div class="column col-1">
<div class="geomarker">[field_geomarker]</div>
</div>
<div class="column col-2">
<div class="title">[title]</div>
<div class="type">[field_site_type]</div>
<div class="category">[field_site_category]</div>
</div>
<div class="column col-3">
<div class="body">[body]</div>
</div>
<div class="column col-4">
<!--<div class="latlng">[field_site_geofield]</div>-->
<!--<div class="ordine">Ordine di Visualizz.: [field_site_order]</div>-->
<div class="contacts">[field_site_contacts]</div>
<div class="links">[edit_node]</div>
</div>
</div>'),
  t('Block'),
  t('Company Sites Map View'),
  t('Pagina Manage Sites'),
  t('Manage Company Sites'),
  t('Order'),
  t('Name'),
  t('Category'),
  t('Dett & Indirizzo'),
  t('Contatti'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;