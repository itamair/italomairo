<?php

$view = new view();
$view->name = 'contatti_rivista';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Contatti Rivista (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Contatto Commerciale';
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
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
$handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Slittamento';
$handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
$handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'field_nome_cognome_editoriale' => 'field_nome_cognome_editoriale',
  'field_email_editoriale' => 'field_email_editoriale',
);
$handler->display->display_options['row_options']['separator'] = ' - ';
/* Relazione: Contenuto: Rivista (field_rivista_realestate) */
$handler->display->display_options['relationships']['field_rivista_realestate_tid']['id'] = 'field_rivista_realestate_tid';
$handler->display->display_options['relationships']['field_rivista_realestate_tid']['table'] = 'field_data_field_rivista_realestate';
$handler->display->display_options['relationships']['field_rivista_realestate_tid']['field'] = 'field_rivista_realestate_tid';
/* Campo: Termine della tassonomia: Nome Cognome Commerciale */
$handler->display->display_options['fields']['field_nome_cognome_commerciale']['id'] = 'field_nome_cognome_commerciale';
$handler->display->display_options['fields']['field_nome_cognome_commerciale']['table'] = 'field_data_field_nome_cognome_commerciale';
$handler->display->display_options['fields']['field_nome_cognome_commerciale']['field'] = 'field_nome_cognome_commerciale';
$handler->display->display_options['fields']['field_nome_cognome_commerciale']['relationship'] = 'field_rivista_realestate_tid';
$handler->display->display_options['fields']['field_nome_cognome_commerciale']['label'] = '';
$handler->display->display_options['fields']['field_nome_cognome_commerciale']['element_label_colon'] = FALSE;
/* Campo: Termine della tassonomia: Email Commerciale */
$handler->display->display_options['fields']['field_email_commerciale']['id'] = 'field_email_commerciale';
$handler->display->display_options['fields']['field_email_commerciale']['table'] = 'field_data_field_email_commerciale';
$handler->display->display_options['fields']['field_email_commerciale']['field'] = 'field_email_commerciale';
$handler->display->display_options['fields']['field_email_commerciale']['relationship'] = 'field_rivista_realestate_tid';
/* Criterio di ordinamento: Contenuto: Data di inserimento */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  'rivista' => 'rivista',
);

/* Display: Contatti Rivista */
$handler = $view->new_display('entity_view', 'Contatti Rivista', 'entity_view_3');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Contatti';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'field_nome_cognome_commerciale' => 'field_nome_cognome_commerciale',
  'field_email_commerciale' => 'field_email_commerciale',
);
$handler->display->display_options['row_options']['separator'] = ' - ';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Termine della tassonomia: Contatti */
$handler->display->display_options['fields']['field_contatti']['id'] = 'field_contatti';
$handler->display->display_options['fields']['field_contatti']['table'] = 'field_data_field_contatti';
$handler->display->display_options['fields']['field_contatti']['field'] = 'field_contatti';
$handler->display->display_options['fields']['field_contatti']['relationship'] = 'field_rivista_realestate_tid';
$handler->display->display_options['fields']['field_contatti']['label'] = '';
$handler->display->display_options['fields']['field_contatti']['element_label_colon'] = FALSE;
$handler->display->display_options['entity_type'] = 'node';
$handler->display->display_options['bundles'] = array(
  0 => 'rivista',
);
$handler->display->display_options['show_title'] = 1;
$translatables['contatti_rivista'] = array(
  t('Master'),
  t('Contatto Commerciale'),
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
  t('term from field_rivista_realestate'),
  t('Email Commerciale'),
  t('Tutti'),
  t('Contatti Rivista'),
  t('Contatti'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;