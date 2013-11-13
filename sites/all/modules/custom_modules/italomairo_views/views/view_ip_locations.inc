<?php

$view = new view();
$view->name = 'ip_locations';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Map ip Locations (in code)';
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
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'ip_geoloc_map';
$handler->display->display_options['style_options']['ip_geoloc_views_plugin_latitude'] = 'field_geoaddress';
$handler->display->display_options['style_options']['ip_geoloc_views_plugin_longitude'] = '';
$handler->display->display_options['style_options']['default_marker_color'] = 'italo_red_marker';
$handler->display->display_options['style_options']['center_option'] = '3';
$handler->display->display_options['style_options']['gps_roles'] = array(
  1 => '1',
  2 => '2',
  3 => 0,
);
$handler->display->display_options['style_options']['map_options'] = '{"zoom":14}';
$handler->display->display_options['style_options']['map_div_style'] = 'width: 100%; height: 600px;';
/* Campo: Contenuto: Location Geografica */
$handler->display->display_options['fields']['field_getlocationfield']['id'] = 'field_getlocationfield';
$handler->display->display_options['fields']['field_getlocationfield']['table'] = 'field_data_field_getlocationfield';
$handler->display->display_options['fields']['field_getlocationfield']['field'] = 'field_getlocationfield';
$handler->display->display_options['fields']['field_getlocationfield']['label'] = '';
$handler->display->display_options['fields']['field_getlocationfield']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_getlocationfield']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_getlocationfield']['settings'] = array(
  'display_showmap' => 0,
  'display_maplink' => 0,
  'display_mapwidth' => '300px',
  'display_mapheight' => '200px',
  'display_latlong' => 0,
  'display_dms' => 0,
  'display_onemap' => 0,
  'display_name' => 1,
  'display_street' => 0,
  'display_additional' => 0,
  'display_city' => 0,
  'display_province' => 0,
  'display_postal_code' => 0,
  'display_country' => 0,
  'country_full' => 0,
  'nodezoom' => '12',
  'minzoom_map' => '-1',
  'maxzoom_map' => '-1',
  'controltype' => 'small',
  'pancontrol' => 1,
  'mtc' => 'standard',
  'maptype' => 'Map',
  'baselayers' => array(
    'Map' => 1,
    'Satellite' => 1,
    'Hybrid' => 1,
    'Physical' => 1,
    'OpenStreetMap' => 0,
  ),
  'behavior' => array(
    'scale' => 0,
    'overview' => 0,
    'overview_opened' => 0,
    'scrollwheel' => 0,
  ),
  'draggable' => 1,
  'map_backgroundcolor' => '',
  'show_maplinks' => 0,
  'show_bubble_on_one_marker' => 0,
  'fullscreen' => 0,
  'streetview_show' => 0,
  'trafficinfo' => 0,
  'trafficinfo_state' => 0,
  'bicycleinfo' => 0,
  'bicycleinfo_state' => 0,
  'transitinfo' => 0,
  'transitinfo_state' => 0,
  'poi_show' => 1,
  'transit_show' => 1,
  'polygons_enable' => 0,
  'polygons_strokecolor' => '#FF0000',
  'polygons_strokeopacity' => '0.8',
  'polygons_strokeweight' => '3',
  'polygons_fillcolor' => '#FF0000',
  'polygons_fillopacity' => '0.35',
  'polygons_clickable' => 0,
  'polygons_message' => '',
  'polygons_coords' => '',
  'rectangles_enable' => 0,
  'rectangles_strokecolor' => '#FF0000',
  'rectangles_strokeopacity' => '0.8',
  'rectangles_strokeweight' => '3',
  'rectangles_fillcolor' => '#FF0000',
  'rectangles_fillopacity' => '0.35',
  'rectangles_clickable' => 0,
  'rectangles_message' => '',
  'rectangles_coords' => '',
  'circles_enable' => 0,
  'circles_strokecolor' => '#FF0000',
  'circles_strokeopacity' => '0.8',
  'circles_strokeweight' => '3',
  'circles_fillcolor' => '#FF0000',
  'circles_fillopacity' => '0.35',
  'circles_radius' => '0',
  'circles_clickable' => 0,
  'circles_message' => '',
  'circles_coords' => '',
  'polylines_enable' => 0,
  'polylines_strokecolor' => '#FF0000',
  'polylines_strokeopacity' => '0.8',
  'polylines_strokeweight' => '3',
  'polylines_clickable' => 0,
  'polylines_message' => '',
  'polylines_coords' => '',
  'kml_url' => '',
  'kml_url_click' => 0,
  'kml_url_infowindow' => 0,
  'kml_url_viewport' => 0,
  'kml_url_button' => 0,
  'kml_url_button_label' => '',
  'kml_url_button_state' => 0,
  'markeractiontype' => '1',
  'markeraction' => '1',
);
/* Campo: Contenuto: Categoria */
$handler->display->display_options['fields']['field_category']['id'] = 'field_category';
$handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
$handler->display->display_options['fields']['field_category']['field'] = 'field_category';
$handler->display->display_options['fields']['field_category']['label'] = '';
$handler->display->display_options['fields']['field_category']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_category']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_category']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_category']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_category']['field_api_classes'] = TRUE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_type'] = 'h4';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['title_field']['element_wrapper_class'] = 'title';
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h4';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['title']['element_wrapper_class'] = 'title';
/* Campo: Contenuto: Immagini */
$handler->display->display_options['fields']['field_cover_images']['id'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['table'] = 'field_data_field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['field'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['label'] = '';
$handler->display->display_options['fields']['field_cover_images']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_cover_images']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_cover_images']['element_wrapper_class'] = 'cover-image';
$handler->display->display_options['fields']['field_cover_images']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_cover_images']['settings'] = array(
  'image_style' => 'medium',
  'image_link' => 'content',
);
$handler->display->display_options['fields']['field_cover_images']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_cover_images']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_cover_images']['field_api_classes'] = TRUE;
/* Campo: Contenuto: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'read-all';
$handler->display->display_options['fields']['view_node']['text'] = 'read all';
/* Campo: Globale: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_category]
[field_cover_images]


';
$handler->display->display_options['fields']['nothing']['element_type'] = 'div';
$handler->display->display_options['fields']['nothing']['element_class'] = 'infowindow-container';
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
  'my_project' => 'my_project',
);

/* Display: Page IP Views Leaflet */
$handler = $view->new_display('page', 'Page IP Views Leaflet', 'page_1');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'projects-map';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'ip_geoloc_leaflet';
$handler->display->display_options['style_options']['ip_geoloc_views_plugin_latitude'] = 'field_getlocationfield';
$handler->display->display_options['style_options']['ip_geoloc_views_plugin_longitude'] = 'field_getlocationfield';
$handler->display->display_options['style_options']['default_marker_color'] = 'project_marker';
$handler->display->display_options['style_options']['center_option'] = '0';
$handler->display->display_options['style_options']['map'] = 'google-road-high-res';
$handler->display->display_options['style_options']['map_height'] = '600';
$handler->display->display_options['style_options']['cluster_radius'] = '15';
$handler->display->display_options['style_options']['tooltips']['marker_tooltip'] = 'title';
$handler->display->display_options['style_options']['map_options']['maxzoom'] = '16';
$handler->display->display_options['style_options']['map_options']['zoom'] = '2';
$handler->display->display_options['style_options']['map_options']['scrollwheelzoom'] = '1';
$handler->display->display_options['style_options']['map_options']['dragging'] = '1';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relazione: Contenuto: Autore */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
$handler->display->display_options['path'] = 'ip-projects-locations';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Projects Locations Map';
$handler->display->display_options['menu']['weight'] = '3';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Block IP Views Leaflet All */
$handler = $view->new_display('block', 'Block IP Views Leaflet All', 'block_2');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'view-mini-map  block_ip_mini_map';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'ip_geoloc_leaflet';
$handler->display->display_options['style_options']['ip_geoloc_views_plugin_latitude'] = 'field_getlocationfield';
$handler->display->display_options['style_options']['ip_geoloc_views_plugin_longitude'] = 'field_getlocationfield';
$handler->display->display_options['style_options']['default_marker_color'] = 'project_marker';
$handler->display->display_options['style_options']['center_option'] = '0';
$handler->display->display_options['style_options']['map'] = 'google-road-high-res';
$handler->display->display_options['style_options']['map_height'] = '180';
$handler->display->display_options['style_options']['cluster_radius'] = '15';
$handler->display->display_options['style_options']['tags']['tag_css_class'] = 'tag-below-marker';
$handler->display->display_options['style_options']['map_options']['maxzoom'] = '18';
$handler->display->display_options['style_options']['map_options']['zoom'] = '2';
$handler->display->display_options['style_options']['map_options']['scrollwheelzoom'] = '1';
$handler->display->display_options['style_options']['map_options']['dragging'] = '1';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Piè di pagina: Globale: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<?php
global $base_url, $language;
$lng = $language -> language;
echo "<h4 class=\'goto-mainmap\'><strong><a  href=\'".$base_url."/".$lng."/ip-projects-locations\'>".t(\'Wide the map\')."</a></h4></strong></h4>";
?>';
$handler->display->display_options['footer']['area']['format'] = 'php_code';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenuto: Location Geografica */
$handler->display->display_options['fields']['field_getlocationfield']['id'] = 'field_getlocationfield';
$handler->display->display_options['fields']['field_getlocationfield']['table'] = 'field_data_field_getlocationfield';
$handler->display->display_options['fields']['field_getlocationfield']['field'] = 'field_getlocationfield';
$handler->display->display_options['fields']['field_getlocationfield']['label'] = '';
$handler->display->display_options['fields']['field_getlocationfield']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_getlocationfield']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_getlocationfield']['settings'] = array(
  'display_showmap' => 0,
  'display_maplink' => 0,
  'display_mapwidth' => '300px',
  'display_mapheight' => '200px',
  'display_latlong' => 0,
  'display_dms' => 0,
  'display_onemap' => 0,
  'display_name' => 1,
  'display_street' => 0,
  'display_additional' => 0,
  'display_city' => 0,
  'display_province' => 0,
  'display_postal_code' => 0,
  'display_country' => 0,
  'country_full' => 0,
  'nodezoom' => '12',
  'minzoom_map' => '-1',
  'maxzoom_map' => '-1',
  'controltype' => 'small',
  'pancontrol' => 1,
  'mtc' => 'standard',
  'maptype' => 'Map',
  'baselayers' => array(
    'Map' => 1,
    'Satellite' => 1,
    'Hybrid' => 1,
    'Physical' => 1,
    'OpenStreetMap' => 0,
  ),
  'behavior' => array(
    'scale' => 0,
    'overview' => 0,
    'overview_opened' => 0,
    'scrollwheel' => 0,
  ),
  'draggable' => 1,
  'map_backgroundcolor' => '',
  'show_maplinks' => 0,
  'show_bubble_on_one_marker' => 0,
  'fullscreen' => 0,
  'streetview_show' => 0,
  'trafficinfo' => 0,
  'trafficinfo_state' => 0,
  'bicycleinfo' => 0,
  'bicycleinfo_state' => 0,
  'transitinfo' => 0,
  'transitinfo_state' => 0,
  'poi_show' => 1,
  'transit_show' => 1,
  'polygons_enable' => 0,
  'polygons_strokecolor' => '#FF0000',
  'polygons_strokeopacity' => '0.8',
  'polygons_strokeweight' => '3',
  'polygons_fillcolor' => '#FF0000',
  'polygons_fillopacity' => '0.35',
  'polygons_clickable' => 0,
  'polygons_message' => '',
  'polygons_coords' => '',
  'rectangles_enable' => 0,
  'rectangles_strokecolor' => '#FF0000',
  'rectangles_strokeopacity' => '0.8',
  'rectangles_strokeweight' => '3',
  'rectangles_fillcolor' => '#FF0000',
  'rectangles_fillopacity' => '0.35',
  'rectangles_clickable' => 0,
  'rectangles_message' => '',
  'rectangles_coords' => '',
  'circles_enable' => 0,
  'circles_strokecolor' => '#FF0000',
  'circles_strokeopacity' => '0.8',
  'circles_strokeweight' => '3',
  'circles_fillcolor' => '#FF0000',
  'circles_fillopacity' => '0.35',
  'circles_radius' => '0',
  'circles_clickable' => 0,
  'circles_message' => '',
  'circles_coords' => '',
  'polylines_enable' => 0,
  'polylines_strokecolor' => '#FF0000',
  'polylines_strokeopacity' => '0.8',
  'polylines_strokeweight' => '3',
  'polylines_clickable' => 0,
  'polylines_message' => '',
  'polylines_coords' => '',
  'kml_url' => '',
  'kml_url_click' => 0,
  'kml_url_infowindow' => 0,
  'kml_url_viewport' => 0,
  'kml_url_button' => 0,
  'kml_url_button_label' => '',
  'kml_url_button_state' => 0,
  'markeractiontype' => '1',
  'markeraction' => '1',
);
/* Campo: Contenuto: Categoria */
$handler->display->display_options['fields']['field_category']['id'] = 'field_category';
$handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
$handler->display->display_options['fields']['field_category']['field'] = 'field_category';
$handler->display->display_options['fields']['field_category']['label'] = '';
$handler->display->display_options['fields']['field_category']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_category']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_category']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_category']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_category']['field_api_classes'] = TRUE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_type'] = 'h4';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['title_field']['element_wrapper_class'] = 'title';
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h4';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['title']['element_wrapper_class'] = 'title';
/* Campo: Contenuto: Immagini */
$handler->display->display_options['fields']['field_cover_images']['id'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['table'] = 'field_data_field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['field'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['label'] = '';
$handler->display->display_options['fields']['field_cover_images']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_cover_images']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_cover_images']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_cover_images']['settings'] = array(
  'image_style' => 'thumbnail2',
  'image_link' => '',
);
$handler->display->display_options['fields']['field_cover_images']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_cover_images']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_cover_images']['field_api_classes'] = TRUE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['block_description'] = 'Blocco IP Leaflet Map All';

/* Display: Block IP Views Leaflet Single */
$handler = $view->new_display('block', 'Block IP Views Leaflet Single', 'block_1');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'view-mini-map  block_ip_mini_map';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'ip_geoloc_leaflet';
$handler->display->display_options['style_options']['ip_geoloc_views_plugin_latitude'] = 'field_getlocationfield';
$handler->display->display_options['style_options']['ip_geoloc_views_plugin_longitude'] = 'field_getlocationfield';
$handler->display->display_options['style_options']['default_marker_color'] = 'project_marker';
$handler->display->display_options['style_options']['center_option'] = '0';
$handler->display->display_options['style_options']['map'] = 'google-hybrid';
$handler->display->display_options['style_options']['map_height'] = '220';
$handler->display->display_options['style_options']['cluster_radius'] = '15';
$handler->display->display_options['style_options']['tooltips']['marker_tooltip'] = 'title_field';
$handler->display->display_options['style_options']['tags']['tag_css_class'] = 'tag-below-marker';
$handler->display->display_options['style_options']['map_options']['maxzoom'] = '15';
$handler->display->display_options['style_options']['map_options']['zoom'] = '11';
$handler->display->display_options['style_options']['map_options']['scrollwheelzoom'] = '1';
$handler->display->display_options['style_options']['map_options']['dragging'] = '1';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['footer'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenuto: Location Geografica */
$handler->display->display_options['fields']['field_getlocationfield']['id'] = 'field_getlocationfield';
$handler->display->display_options['fields']['field_getlocationfield']['table'] = 'field_data_field_getlocationfield';
$handler->display->display_options['fields']['field_getlocationfield']['field'] = 'field_getlocationfield';
$handler->display->display_options['fields']['field_getlocationfield']['label'] = '';
$handler->display->display_options['fields']['field_getlocationfield']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_getlocationfield']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_getlocationfield']['settings'] = array(
  'display_showmap' => 0,
  'display_maplink' => 0,
  'display_mapwidth' => '300px',
  'display_mapheight' => '200px',
  'display_latlong' => 0,
  'display_dms' => 0,
  'display_onemap' => 0,
  'display_name' => 1,
  'display_street' => 0,
  'display_additional' => 0,
  'display_city' => 0,
  'display_province' => 0,
  'display_postal_code' => 0,
  'display_country' => 0,
  'country_full' => 0,
  'nodezoom' => '12',
  'minzoom_map' => '-1',
  'maxzoom_map' => '-1',
  'controltype' => 'small',
  'pancontrol' => 1,
  'mtc' => 'standard',
  'maptype' => 'Map',
  'baselayers' => array(
    'Map' => 1,
    'Satellite' => 1,
    'Hybrid' => 1,
    'Physical' => 1,
    'OpenStreetMap' => 0,
  ),
  'behavior' => array(
    'scale' => 0,
    'overview' => 0,
    'overview_opened' => 0,
    'scrollwheel' => 0,
  ),
  'draggable' => 1,
  'map_backgroundcolor' => '',
  'show_maplinks' => 0,
  'show_bubble_on_one_marker' => 0,
  'fullscreen' => 0,
  'streetview_show' => 0,
  'trafficinfo' => 0,
  'trafficinfo_state' => 0,
  'bicycleinfo' => 0,
  'bicycleinfo_state' => 0,
  'transitinfo' => 0,
  'transitinfo_state' => 0,
  'poi_show' => 1,
  'transit_show' => 1,
  'polygons_enable' => 0,
  'polygons_strokecolor' => '#FF0000',
  'polygons_strokeopacity' => '0.8',
  'polygons_strokeweight' => '3',
  'polygons_fillcolor' => '#FF0000',
  'polygons_fillopacity' => '0.35',
  'polygons_clickable' => 0,
  'polygons_message' => '',
  'polygons_coords' => '',
  'rectangles_enable' => 0,
  'rectangles_strokecolor' => '#FF0000',
  'rectangles_strokeopacity' => '0.8',
  'rectangles_strokeweight' => '3',
  'rectangles_fillcolor' => '#FF0000',
  'rectangles_fillopacity' => '0.35',
  'rectangles_clickable' => 0,
  'rectangles_message' => '',
  'rectangles_coords' => '',
  'circles_enable' => 0,
  'circles_strokecolor' => '#FF0000',
  'circles_strokeopacity' => '0.8',
  'circles_strokeweight' => '3',
  'circles_fillcolor' => '#FF0000',
  'circles_fillopacity' => '0.35',
  'circles_radius' => '0',
  'circles_clickable' => 0,
  'circles_message' => '',
  'circles_coords' => '',
  'polylines_enable' => 0,
  'polylines_strokecolor' => '#FF0000',
  'polylines_strokeopacity' => '0.8',
  'polylines_strokeweight' => '3',
  'polylines_clickable' => 0,
  'polylines_message' => '',
  'polylines_coords' => '',
  'kml_url' => '',
  'kml_url_click' => 0,
  'kml_url_infowindow' => 0,
  'kml_url_viewport' => 0,
  'kml_url_button' => 0,
  'kml_url_button_label' => '',
  'kml_url_button_state' => 0,
  'markeractiontype' => '1',
  'markeraction' => '1',
);
/* Campo: Contenuto: Categoria */
$handler->display->display_options['fields']['field_category']['id'] = 'field_category';
$handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
$handler->display->display_options['fields']['field_category']['field'] = 'field_category';
$handler->display->display_options['fields']['field_category']['label'] = '';
$handler->display->display_options['fields']['field_category']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_category']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_category']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_category']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_category']['field_api_classes'] = TRUE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_type'] = 'h4';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['title_field']['element_wrapper_class'] = 'title';
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h4';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['title']['element_wrapper_class'] = 'title';
/* Campo: Contenuto: Immagini */
$handler->display->display_options['fields']['field_cover_images']['id'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['table'] = 'field_data_field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['field'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['label'] = '';
$handler->display->display_options['fields']['field_cover_images']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_cover_images']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_cover_images']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_cover_images']['settings'] = array(
  'image_style' => 'thumbnail2',
  'image_link' => '',
);
$handler->display->display_options['fields']['field_cover_images']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_cover_images']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_cover_images']['field_api_classes'] = TRUE;
/* Campo: Getlocations Fields: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'getlocations_fields';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['name']['element_wrapper_class'] = 'location-name';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Contenuto: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['exception']['title'] = 'Tutti';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['block_description'] = 'Blocco IP Leaflet Map Single';

/* Display: In Allegato elenco progetti */
$handler = $view->new_display('attachment', 'In Allegato elenco progetti', 'attachment_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Elenco Progetti';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = '[nid]';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'title_field' => 'title_field',
  'name' => 'name',
);
$handler->display->display_options['row_options']['separator'] = ' - ';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['element_type'] = 'h4';
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['title_field']['element_wrapper_class'] = 'title';
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Select a Project';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h4';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['title']['element_wrapper_class'] = 'title';
/* Campo: Contenuto: Anno inizio */
$handler->display->display_options['fields']['field_anno_inizio']['id'] = 'field_anno_inizio';
$handler->display->display_options['fields']['field_anno_inizio']['table'] = 'field_data_field_anno_inizio';
$handler->display->display_options['fields']['field_anno_inizio']['field'] = 'field_anno_inizio';
$handler->display->display_options['fields']['field_anno_inizio']['label'] = '';
$handler->display->display_options['fields']['field_anno_inizio']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_anno_inizio']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_anno_inizio']['settings'] = array(
  'format_type' => 'anno',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
/* Campo: Getlocations Fields: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'getlocations_fields';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Criterio di ordinamento: Contenuto: Anno inizio (field_anno_inizio) */
$handler->display->display_options['sorts']['field_anno_inizio_value']['id'] = 'field_anno_inizio_value';
$handler->display->display_options['sorts']['field_anno_inizio_value']['table'] = 'field_data_field_anno_inizio';
$handler->display->display_options['sorts']['field_anno_inizio_value']['field'] = 'field_anno_inizio_value';
$handler->display->display_options['sorts']['field_anno_inizio_value']['order'] = 'DESC';
/* Criterio di ordinamento: Contenuto: Data di inserimento */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['displays'] = array(
  'page_1' => 'page_1',
  'default' => 0,
  'block_2' => 0,
  'block_1' => 0,
);
$translatables['ip_locations'] = array(
  t('Master'),
  t('Projects Locations Map'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('read all'),
  t('[field_category]
[field_cover_images]


'),
  t('Page IP Views Leaflet'),
  t('author'),
  t('Block IP Views Leaflet All'),
  t('<?php
global $base_url, $language;
$lng = $language -> language;
echo "<h4 class=\'goto-mainmap\'><strong><a  href=\'".$base_url."/".$lng."/ip-projects-locations\'>".t(\'Wide the map\')."</a></h4></strong></h4>";
?>'),
  t('Blocco IP Leaflet Map All'),
  t('Block IP Views Leaflet Single'),
  t('Tutti'),
  t('Blocco IP Leaflet Map Single'),
  t('In Allegato elenco progetti'),
  t('Elenco Progetti'),
  t('Select a Project'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;