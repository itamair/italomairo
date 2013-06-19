<?php

$view = new view();
$view->name = 'getlocation_map';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'getlocations_fields';
$view->human_name = 'Getlocation_map (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Projects Locations Map';
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
$handler->display->display_options['style_plugin'] = 'getlocations';
$handler->display->display_options['style_options']['width'] = '95%';
$handler->display->display_options['style_options']['height'] = '480px';
$handler->display->display_options['style_options']['node_map_marker'] = 'circular bullet_red';
$handler->display->display_options['style_options']['term_map_marker'] = 'circular bullet_red';
$handler->display->display_options['style_options']['behavior'] = array(
  'scale' => 0,
  'overview' => 0,
  'overview_opened' => 0,
  'scrollwheel' => 1,
);
$handler->display->display_options['style_options']['streetview_show'] = 1;
$handler->display->display_options['style_options']['fullscreen'] = 1;
$handler->display->display_options['style_options']['useclustermanager'] = 0;
$handler->display->display_options['style_options']['custom_content_enable'] = 1;
$handler->display->display_options['style_options']['custom_content_source'] = 'nothing';
$handler->display->display_options['row_plugin'] = 'fields';
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
/* Relazione: Getlocations Fields: ID nodo */
$handler->display->display_options['relationships']['nid']['id'] = 'nid';
$handler->display->display_options['relationships']['nid']['table'] = 'getlocations_fields_entities';
$handler->display->display_options['relationships']['nid']['field'] = 'nid';
$handler->display->display_options['relationships']['nid']['label'] = 'contenuto';
/* Campo: Getlocations Fields: Glid */
$handler->display->display_options['fields']['glid']['id'] = 'glid';
$handler->display->display_options['fields']['glid']['table'] = 'getlocations_fields';
$handler->display->display_options['fields']['glid']['field'] = 'glid';
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Campo: Getlocations Fields: Latitude (WGS84 decimal) */
$handler->display->display_options['fields']['latitude']['id'] = 'latitude';
$handler->display->display_options['fields']['latitude']['table'] = 'getlocations_fields';
$handler->display->display_options['fields']['latitude']['field'] = 'latitude';
/* Campo: Getlocations Fields: Longitude (WGS84 decimal) */
$handler->display->display_options['fields']['longitude']['id'] = 'longitude';
$handler->display->display_options['fields']['longitude']['table'] = 'getlocations_fields';
$handler->display->display_options['fields']['longitude']['field'] = 'longitude';
/* Campo: Getlocations Fields: Marker */
$handler->display->display_options['fields']['marker']['id'] = 'marker';
$handler->display->display_options['fields']['marker']['table'] = 'getlocations_fields';
$handler->display->display_options['fields']['marker']['field'] = 'marker';
/* Campo: Getlocations Fields: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'getlocations_fields';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'nid';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
/* Campo: Contenuto: Immagine di copertina */
$handler->display->display_options['fields']['field_cover_images']['id'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['table'] = 'field_data_field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['field'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['relationship'] = 'nid';
$handler->display->display_options['fields']['field_cover_images']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_cover_images']['settings'] = array(
  'image_style' => 'minithumbnail-progetti',
  'image_link' => 'content',
);
$handler->display->display_options['fields']['field_cover_images']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_cover_images']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_cover_images']['separator'] = '';
/* Campo: Contenuto: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['relationship'] = 'nid';
$handler->display->display_options['fields']['body']['label'] = 'Corpo';
$handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '400',
);
/* Campo: Contenuto: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['relationship'] = 'nid';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['text'] = 'Read More';
/* Campo: Globale: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = 'Infowindow';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="infowindow">
<div class="content">
<div class=\'image\'>[field_cover_images]</div>
<div class=\'title\'><strong>[title]</strong></div>
<div class=\'body\'>[body]</div>
</div>
<div class=\'info\'>
<div class=\'readmore\'>[view_node]</div>
</div>
</div>';
/* Filter criterion: Contenuto: Pubblicato */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
/* Filter criterion: Contenuto: Tipo */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'my_project' => 'my_project',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'getlocation-map';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Locations Map';
$handler->display->display_options['menu']['weight'] = '3';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Blocco */
$handler = $view->new_display('block', 'Blocco', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Project Location Map';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'getlocations';
$handler->display->display_options['style_options']['width'] = '95%';
$handler->display->display_options['style_options']['height'] = '220px';
$handler->display->display_options['style_options']['node_map_marker'] = 'circular bullet_red';
$handler->display->display_options['style_options']['term_map_marker'] = 'circular bullet_red';
$handler->display->display_options['style_options']['controltype'] = 'none';
$handler->display->display_options['style_options']['pancontrol'] = 0;
$handler->display->display_options['style_options']['mtc'] = 'none';
$handler->display->display_options['style_options']['maptype'] = 'Hybrid';
$handler->display->display_options['style_options']['behavior'] = array(
  'scale' => 0,
  'overview' => 0,
  'overview_opened' => 0,
  'scrollwheel' => 1,
);
$handler->display->display_options['style_options']['streetview_show'] = 1;
$handler->display->display_options['style_options']['fullscreen'] = 1;
$handler->display->display_options['style_options']['nodezoom'] = '11';
$handler->display->display_options['style_options']['markeraction'] = '3';
$handler->display->display_options['style_options']['useclustermanager'] = 0;
$handler->display->display_options['style_options']['custom_content_enable'] = 1;
$handler->display->display_options['style_options']['custom_content_source'] = 'nothing';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Contenuto: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['exception']['title'] = 'Tutti';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['block_description'] = 'Mappa Singola Location';

/* Display: Blocco */
$handler = $view->new_display('block', 'Blocco', 'block_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Project Location Map';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'getlocations';
$handler->display->display_options['style_options']['width'] = '95%';
$handler->display->display_options['style_options']['height'] = '220px';
$handler->display->display_options['style_options']['node_map_marker'] = 'circular bullet_red';
$handler->display->display_options['style_options']['term_map_marker'] = 'circular bullet_red';
$handler->display->display_options['style_options']['controltype'] = 'none';
$handler->display->display_options['style_options']['pancontrol'] = 0;
$handler->display->display_options['style_options']['mtc'] = 'none';
$handler->display->display_options['style_options']['minzoom'] = '9';
$handler->display->display_options['style_options']['nodezoom'] = '7';
$handler->display->display_options['style_options']['markeraction'] = '3';
$handler->display->display_options['style_options']['markerclusterer_minsize'] = '-1';
$handler->display->display_options['style_options']['draggable'] = 0;
$handler->display->display_options['style_options']['custom_content_enable'] = 1;
$handler->display->display_options['style_options']['custom_content_source'] = 'nothing';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['block_description'] = 'Mappa All Locations';
$translatables['getlocation_map'] = array(
  t('Master'),
  t('Projects Locations Map'),
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
  t('contenuto'),
  t('Glid'),
  t('Latitude (WGS84 decimal)'),
  t('Longitude (WGS84 decimal)'),
  t('Marker'),
  t('Nome'),
  t('Titolo'),
  t('Immagine di copertina'),
  t('Corpo'),
  t('Read More'),
  t('Infowindow'),
  t('<div class="infowindow">
<div class="content">
<div class=\'image\'>[field_cover_images]</div>
<div class=\'title\'><strong>[title]</strong></div>
<div class=\'body\'>[body]</div>
</div>
<div class=\'info\'>
<div class=\'readmore\'>[view_node]</div>
</div>
</div>'),
  t('Page'),
  t('Blocco'),
  t('Project Location Map'),
  t('Tutti'),
  t('Mappa Singola Location'),
  t('Mappa All Locations'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;