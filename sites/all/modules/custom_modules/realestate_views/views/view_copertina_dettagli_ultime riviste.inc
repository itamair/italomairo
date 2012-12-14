<?php

$view = new view();
$view->name = 'copertina_dettagli_ultime_riviste';
$view->description = 'Espone l\'ultima copertina di una rivista';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Copertina e Dettagli Ultime Riviste (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
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
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
/* Campo: Contenuto: Rivista */
$handler->display->display_options['fields']['field_rivista_realestate']['id'] = 'field_rivista_realestate';
$handler->display->display_options['fields']['field_rivista_realestate']['table'] = 'field_data_field_rivista_realestate';
$handler->display->display_options['fields']['field_rivista_realestate']['field'] = 'field_rivista_realestate';
$handler->display->display_options['fields']['field_rivista_realestate']['label'] = '';
$handler->display->display_options['fields']['field_rivista_realestate']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_rivista_realestate']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_rivista_realestate']['alter']['path'] = '/node/[nid]';
$handler->display->display_options['fields']['field_rivista_realestate']['element_type'] = 'h2';
$handler->display->display_options['fields']['field_rivista_realestate']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_rivista_realestate']['type'] = 'taxonomy_term_reference_plain';
/* Campo: Contenuto: Copertina */
$handler->display->display_options['fields']['field_imm_copertine']['id'] = 'field_imm_copertine';
$handler->display->display_options['fields']['field_imm_copertine']['table'] = 'field_data_field_imm_copertine';
$handler->display->display_options['fields']['field_imm_copertine']['field'] = 'field_imm_copertine';
$handler->display->display_options['fields']['field_imm_copertine']['label'] = '';
$handler->display->display_options['fields']['field_imm_copertine']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_imm_copertine']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_imm_copertine']['settings'] = array(
  'image_style' => 'copertina_rivista',
  'image_link' => 'content',
);
/* Criterio di ordinamento: Contenuto: Mese di pubblicazione (field_pubb_mese_anno) */
$handler->display->display_options['sorts']['field_pubb_mese_anno_value']['id'] = 'field_pubb_mese_anno_value';
$handler->display->display_options['sorts']['field_pubb_mese_anno_value']['table'] = 'field_data_field_pubb_mese_anno';
$handler->display->display_options['sorts']['field_pubb_mese_anno_value']['field'] = 'field_pubb_mese_anno_value';
$handler->display->display_options['sorts']['field_pubb_mese_anno_value']['order'] = 'DESC';
/* Criterio di ordinamento: Contenuto: Data di inserimento */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Contextual filter: Contenuto: Rivista (field_rivista_realestate) */
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['id'] = 'field_rivista_realestate_tid';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['table'] = 'field_data_field_rivista_realestate';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['field'] = 'field_rivista_realestate_tid';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['exception']['title'] = 'Tutti';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['default_argument_type'] = 'taxonomy_tid';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['default_argument_options']['node'] = TRUE;
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['default_argument_options']['vocabularies'] = array(
  'riviste_realestate' => 'riviste_realestate',
);
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['summary_options']['items_per_page'] = '25';
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

/* Display: Ultima Copertina Uscita */
$handler = $view->new_display('entity_view', 'Ultima Copertina Uscita', 'entity_view_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['entity_type'] = 'taxonomy_term';
$handler->display->display_options['bundles'] = array(
  0 => 'riviste_realestate',
);

/* Display: Dettagli Ultima Rivista Uscita */
$handler = $view->new_display('entity_view', 'Dettagli Ultima Rivista Uscita', 'entity_view_2');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Rivista */
$handler->display->display_options['fields']['field_rivista_realestate']['id'] = 'field_rivista_realestate';
$handler->display->display_options['fields']['field_rivista_realestate']['table'] = 'field_data_field_rivista_realestate';
$handler->display->display_options['fields']['field_rivista_realestate']['field'] = 'field_rivista_realestate';
$handler->display->display_options['fields']['field_rivista_realestate']['label'] = '';
$handler->display->display_options['fields']['field_rivista_realestate']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_rivista_realestate']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Mese di pubblicazione */
$handler->display->display_options['fields']['field_pubb_mese_anno']['id'] = 'field_pubb_mese_anno';
$handler->display->display_options['fields']['field_pubb_mese_anno']['table'] = 'field_data_field_pubb_mese_anno';
$handler->display->display_options['fields']['field_pubb_mese_anno']['field'] = 'field_pubb_mese_anno';
$handler->display->display_options['fields']['field_pubb_mese_anno']['label'] = '';
$handler->display->display_options['fields']['field_pubb_mese_anno']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pubb_mese_anno']['settings'] = array(
  'format_type' => 'mese_anno',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
/* Campo: Contenuto: Sottotitolo */
$handler->display->display_options['fields']['field_sottotitolo']['id'] = 'field_sottotitolo';
$handler->display->display_options['fields']['field_sottotitolo']['table'] = 'field_data_field_sottotitolo';
$handler->display->display_options['fields']['field_sottotitolo']['field'] = 'field_sottotitolo';
$handler->display->display_options['fields']['field_sottotitolo']['label'] = '';
$handler->display->display_options['fields']['field_sottotitolo']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '500',
);
/* Campo: Contenuto: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['text'] = 'read all';
$handler->display->display_options['entity_type'] = 'taxonomy_term';
$handler->display->display_options['bundles'] = array(
  0 => 'riviste_realestate',
);

/* Display: Ultima Rivista Uscita */
$handler = $view->new_display('entity_view', 'Ultima Rivista Uscita', 'entity_view_3');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'block-ultima-rivista-uscita';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
/* Campo: Contenuto: Rivista */
$handler->display->display_options['fields']['field_rivista_realestate']['id'] = 'field_rivista_realestate';
$handler->display->display_options['fields']['field_rivista_realestate']['table'] = 'field_data_field_rivista_realestate';
$handler->display->display_options['fields']['field_rivista_realestate']['field'] = 'field_rivista_realestate';
$handler->display->display_options['fields']['field_rivista_realestate']['label'] = '';
$handler->display->display_options['fields']['field_rivista_realestate']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_rivista_realestate']['alter']['path'] = 'node/[nid]';
$handler->display->display_options['fields']['field_rivista_realestate']['element_type'] = 'h2';
$handler->display->display_options['fields']['field_rivista_realestate']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_rivista_realestate']['type'] = 'taxonomy_term_reference_plain';
/* Campo: Contenuto: Copertina */
$handler->display->display_options['fields']['field_imm_copertine']['id'] = 'field_imm_copertine';
$handler->display->display_options['fields']['field_imm_copertine']['table'] = 'field_data_field_imm_copertine';
$handler->display->display_options['fields']['field_imm_copertine']['field'] = 'field_imm_copertine';
$handler->display->display_options['fields']['field_imm_copertine']['label'] = '';
$handler->display->display_options['fields']['field_imm_copertine']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_imm_copertine']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_imm_copertine']['settings'] = array(
  'image_style' => 'thumbnail-bigger',
  'image_link' => 'content',
);
/* Campo: Contenuto: Mese di pubblicazione */
$handler->display->display_options['fields']['field_pubb_mese_anno']['id'] = 'field_pubb_mese_anno';
$handler->display->display_options['fields']['field_pubb_mese_anno']['table'] = 'field_data_field_pubb_mese_anno';
$handler->display->display_options['fields']['field_pubb_mese_anno']['field'] = 'field_pubb_mese_anno';
$handler->display->display_options['fields']['field_pubb_mese_anno']['label'] = '';
$handler->display->display_options['fields']['field_pubb_mese_anno']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_pubb_mese_anno']['settings'] = array(
  'format_type' => 'mese_anno',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
$handler->display->display_options['entity_type'] = 'taxonomy_term';
$handler->display->display_options['bundles'] = array(
  0 => 'riviste_realestate',
);
$translatables['copertina_dettagli_ultime_riviste'] = array(
  t('Master'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('Nid'),
  t('Tutti'),
  t('Ultima Copertina Uscita'),
  t('Dettagli Ultima Rivista Uscita'),
  t('read all'),
  t('Ultima Rivista Uscita'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;