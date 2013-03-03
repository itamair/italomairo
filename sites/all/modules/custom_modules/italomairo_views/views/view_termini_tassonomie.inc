<?php

$view = new view();
$view->name = 'elenco_termini_tassonomie';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'taxonomy_term_data';
$view->human_name = 'Elenco Termini Tassonomie (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Elenco Companies';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'leggi tutto';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'administer nodes';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'name' => 'name',
  'machine_name' => 'machine_name',
  'field_website' => 'field_website',
  'edit_term' => 'edit_term',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'machine_name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_website' => array(
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
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<div class="add-company" style="float:right; margin-right: 16px"><a href="/admin/structure/taxonomy/companies/add">Aggiungi Company</a></div>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Campo: Termine della tassonomia: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = 'Termine';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
/* Campo: Vocabolario della tassonomia: Nome ad uso interno */
$handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
$handler->display->display_options['fields']['machine_name']['table'] = 'taxonomy_vocabulary';
$handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
$handler->display->display_options['fields']['machine_name']['label'] = 'Vocabolario';
/* Campo: Termine della tassonomia: website */
$handler->display->display_options['fields']['field_website']['id'] = 'field_website';
$handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
$handler->display->display_options['fields']['field_website']['field'] = 'field_website';
$handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
/* Campo: Termine della tassonomia: Term edit link */
$handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['label'] = '';
$handler->display->display_options['fields']['edit_term']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['edit_term']['text'] = 'modifica';
/* Criterio di ordinamento: Termine della tassonomia: ID Termine */
$handler->display->display_options['sorts']['tid']['id'] = 'tid';
$handler->display->display_options['sorts']['tid']['table'] = 'taxonomy_term_data';
$handler->display->display_options['sorts']['tid']['field'] = 'tid';
$handler->display->display_options['sorts']['tid']['order'] = 'DESC';
/* Criterio di ordinamento: Termine della tassonomia: Nome */
$handler->display->display_options['sorts']['name']['id'] = 'name';
$handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['sorts']['name']['field'] = 'name';
/* Filter criterion: Vocabolario della tassonomia: Nome ad uso interno */
$handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
$handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['value'] = array(
  'all' => 'all',
  'canali' => 'canali',
  'category' => 'category',
  'companies' => 'companies',
  'newsletters' => 'newsletters',
  'tags' => 'tags',
);
/* Filter criterion: Termine della tassonomia: Vocabolario */
$handler->display->display_options['filters']['vid']['id'] = 'vid';
$handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
$handler->display->display_options['filters']['vid']['field'] = 'vid';
$handler->display->display_options['filters']['vid']['exposed'] = TRUE;
$handler->display->display_options['filters']['vid']['expose']['operator_id'] = 'vid_op';
$handler->display->display_options['filters']['vid']['expose']['label'] = 'Vocabolario';
$handler->display->display_options['filters']['vid']['expose']['operator'] = 'vid_op';
$handler->display->display_options['filters']['vid']['expose']['identifier'] = 'vid';
$handler->display->display_options['filters']['vid']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['vid']['expose']['remember_roles'] = array(
  2 => '2',
  3 => '3',
  1 => 0,
);

/* Display: Page Termini Tassonomie */
$handler = $view->new_display('page', 'Page Termini Tassonomie', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'taxonomies-terms';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Elenco Termini Tassonomie';
$handler->display->display_options['menu']['weight'] = '10';
$handler->display->display_options['menu']['context'] = 0;
$translatables['elenco_companies'] = array(
  t('Master'),
  t('Elenco Companies'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('<div class="add-company" style="float:right; margin-right: 16px"><a href="/admin/structure/taxonomy/companies/add">Aggiungi Company</a></div>'),
  t('Termine'),
  t('Vocabolario'),
  t('website'),
  t('modifica'),
  t('Page Termini Tassonomie'),
);

/* Define this new view from code in views list */
$views[$view->name] = $view;