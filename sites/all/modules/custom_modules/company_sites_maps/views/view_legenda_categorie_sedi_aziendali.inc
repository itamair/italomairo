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
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['name']['alter']['text'] = '<div class="legend-item"><span class="marker-icon">[field_geomarker]</span> <span class="marker-title">[name]</span></div>';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
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
$translatables['legenda_categorie_sedi_aziendali'] = array(
  t('Master'),
  t('Legenda'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('<div class="legend-item"><span class="marker-icon">[field_geomarker]</span> <span class="marker-title">[name]</span></div>'),
  t('Block'),
  t('Legenda Categorie Sedi'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;