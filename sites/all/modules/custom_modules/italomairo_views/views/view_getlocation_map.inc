<?php

$view = new view();
$view->name = 'ultime_notizie';
$view->description = 'Elenco delle ultime notizie';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Ultime Notizie (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Ultime Notizie';
$handler->display->display_options['use_ajax'] = TRUE;
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
$handler->display->display_options['pager']['options']['items_per_page'] = '4';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
$handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Slittamento';
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['style_options']['columns'] = '2';
$handler->display->display_options['row_plugin'] = 'node';
$handler->display->display_options['row_options']['view_mode'] = 'ultime_notizie';
$handler->display->display_options['row_options']['links'] = FALSE;
/* Campo: Contenuto: Data di pubblicazione della Notizia */
$handler->display->display_options['fields']['field_data']['id'] = 'field_data';
$handler->display->display_options['fields']['field_data']['table'] = 'field_data_field_data';
$handler->display->display_options['fields']['field_data']['field'] = 'field_data';
$handler->display->display_options['fields']['field_data']['label'] = '';
$handler->display->display_options['fields']['field_data']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_data']['settings'] = array(
  'format_type' => 'medium',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Criterio di ordinamento: Contenuto: Data di pubblicazione della Notizia (field_data) */
$handler->display->display_options['sorts']['field_data_value']['id'] = 'field_data_value';
$handler->display->display_options['sorts']['field_data_value']['table'] = 'field_data_field_data';
$handler->display->display_options['sorts']['field_data_value']['field'] = 'field_data_value';
$handler->display->display_options['sorts']['field_data_value']['order'] = 'DESC';
/* Criterio di ordinamento: Contenuto: Data di inserimento */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Contextual filter: Contenuto: Has taxonomy term ID (with depth) */
$handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
$handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
$handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
$handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title'] = 'Tutti';
$handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '2';
$handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = TRUE;
$handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = TRUE;
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
  'article' => 'article',
  'blog' => 'blog',
  'notizia' => 'notizia',
);
/* Filter criterion: Contenuto: In evidenza/slideshow home (field_in_evidenza) */
$handler->display->display_options['filters']['field_in_evidenza_value']['id'] = 'field_in_evidenza_value';
$handler->display->display_options['filters']['field_in_evidenza_value']['table'] = 'field_data_field_in_evidenza';
$handler->display->display_options['filters']['field_in_evidenza_value']['field'] = 'field_in_evidenza_value';
$handler->display->display_options['filters']['field_in_evidenza_value']['operator'] = 'not';
$handler->display->display_options['filters']['field_in_evidenza_value']['value'] = array(
  1 => '1',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

/* Display: In Allegato */
$handler = $view->new_display('attachment', 'In Allegato', 'attachment_1');
$handler->display->display_options['enabled'] = FALSE;
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '4';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'field_data' => 'field_data',
  'title' => 'title',
);
$handler->display->display_options['row_options']['separator'] = ' - ';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<h2>Older News</h2>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
$handler->display->display_options['displays'] = array(
  'block' => 'block',
  'default' => 0,
);
$handler->display->display_options['attachment_position'] = 'after';
$handler->display->display_options['inherit_pager'] = TRUE;
$translatables['ultime_notizie'] = array(
  t('Master'),
  t('Ultime Notizie'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('Voci per pagina'),
  t('- Tutto -'),
  t('Slittamento'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('Tutti'),
  t('Block'),
  t('In Allegato'),
  t('<h2>Older News</h2>'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;