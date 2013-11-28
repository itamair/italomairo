<?php

$view = new view();
$view->name = 'legenda_categorie_sedi_aziendali';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'taxonomy_term_data';
$view->human_name = 'Legenda Categorie Sedi Aziendali (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Legenda';
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
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'name' => 'name',
  'field_geomarker' => 'field_geomarker',
);
$handler->display->display_options['row_options']['separator'] = ' ';
/* Campo: Termine della tassonomia: Geo Marker */
$handler->display->display_options['fields']['field_geomarker']['id'] = 'field_geomarker';
$handler->display->display_options['fields']['field_geomarker']['table'] = 'field_data_field_geomarker';
$handler->display->display_options['fields']['field_geomarker']['field'] = 'field_geomarker';
$handler->display->display_options['fields']['field_geomarker']['label'] = '';
$handler->display->display_options['fields']['field_geomarker']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_geomarker']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_geomarker']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_geomarker']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Campo: Termine della tassonomia: Nome */
$handler->display->display_options['fields']['name_field']['id'] = 'name_field';
$handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
$handler->display->display_options['fields']['name_field']['field'] = 'name_field';
$handler->display->display_options['fields']['name_field']['label'] = '';
$handler->display->display_options['fields']['name_field']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['name_field']['alter']['text'] = '<div class="legend-item"><span class="marker-icon">[field_geomarker]</span> <span class="marker-title">[name_field]</span></div>';
$handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
/* Filter criterion: Vocabolario della tassonomia: Nome ad uso interno */
$handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
$handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['value'] = array(
  'site_category' => 'site_category',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'legenda-categorie-sedi';
$handler->display->display_options['block_description'] = 'Legenda Categorie Sedi';

/* Display: Pagina */
$handler = $view->new_display('page', 'Pagina', 'page_1');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'legend-sites-categories';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'field_geomarker' => 'field_geomarker',
  'name' => 'name',
  'edit_term' => 'edit_term',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'field_geomarker' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'edit_term' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Termine della tassonomia: ID Termine */
$handler->display->display_options['fields']['tid']['id'] = 'tid';
$handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['tid']['field'] = 'tid';
$handler->display->display_options['fields']['tid']['label'] = '';
$handler->display->display_options['fields']['tid']['exclude'] = TRUE;
$handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
/* Campo: Termine della tassonomia: Geo Marker */
$handler->display->display_options['fields']['field_geomarker']['id'] = 'field_geomarker';
$handler->display->display_options['fields']['field_geomarker']['table'] = 'field_data_field_geomarker';
$handler->display->display_options['fields']['field_geomarker']['field'] = 'field_geomarker';
$handler->display->display_options['fields']['field_geomarker']['label'] = 'GeoMarker';
$handler->display->display_options['fields']['field_geomarker']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_geomarker']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_geomarker']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Campo: Termine della tassonomia: Nome */
$handler->display->display_options['fields']['name_field']['id'] = 'name_field';
$handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
$handler->display->display_options['fields']['name_field']['field'] = 'name_field';
$handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
/* Campo: Termine della tassonomia: Term edit link */
$handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['label'] = '';
$handler->display->display_options['fields']['edit_term']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['edit_term']['text'] = 'edit';
/* Campo: Globale: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = 'translate';
$handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nothing']['alter']['path'] = 'taxonomy/term/[tid]/translate?destination=legend-sites-categories';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['path'] = 'legend-sites-categories';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Legend Sites Categories';
$handler->display->display_options['menu']['weight'] = '48';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['legenda_categorie_sedi_aziendali'] = array(
  t('Master'),
  t('Legenda'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('<div class="legend-item"><span class="marker-icon">[field_geomarker]</span> <span class="marker-title">[name_field]</span></div>'),
  t('Block'),
  t('Legenda Categorie Sedi'),
  t('Pagina'),
  t('.'),
  t(','),
  t('GeoMarker'),
  t('Nome'),
  t('edit'),
  t('translate'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;