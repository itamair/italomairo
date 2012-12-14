<?php

$view = new view();
$view->name = 'button_links_rivista';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'More Info & Button Links Rivista';
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
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
$handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Slittamento';
$handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
$handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['wrapper_class'] = '';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relazione: Contenuto: Rivista (field_rivista_realestate) */
$handler->display->display_options['relationships']['field_rivista_realestate_tid']['id'] = 'field_rivista_realestate_tid';
$handler->display->display_options['relationships']['field_rivista_realestate_tid']['table'] = 'field_data_field_rivista_realestate';
$handler->display->display_options['relationships']['field_rivista_realestate_tid']['field'] = 'field_rivista_realestate_tid';
$handler->display->display_options['relationships']['field_rivista_realestate_tid']['required'] = TRUE;
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Campo: Termine della tassonomia: Link Abbonamento su piattaforma Direct Channel */
$handler->display->display_options['fields']['field_link_abbonamento']['id'] = 'field_link_abbonamento';
$handler->display->display_options['fields']['field_link_abbonamento']['table'] = 'field_data_field_link_abbonamento';
$handler->display->display_options['fields']['field_link_abbonamento']['field'] = 'field_link_abbonamento';
$handler->display->display_options['fields']['field_link_abbonamento']['relationship'] = 'field_rivista_realestate_tid';
$handler->display->display_options['fields']['field_link_abbonamento']['label'] = '';
$handler->display->display_options['fields']['field_link_abbonamento']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_link_abbonamento']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_link_abbonamento']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_link_abbonamento']['multi_type'] = 'ol';
/* Campo: Termine della tassonomia: Link_bottone */
$handler->display->display_options['fields']['field_link_bottone']['id'] = 'field_link_bottone';
$handler->display->display_options['fields']['field_link_bottone']['table'] = 'field_data_field_link_bottone';
$handler->display->display_options['fields']['field_link_bottone']['field'] = 'field_link_bottone';
$handler->display->display_options['fields']['field_link_bottone']['relationship'] = 'field_rivista_realestate_tid';
$handler->display->display_options['fields']['field_link_bottone']['label'] = '';
$handler->display->display_options['fields']['field_link_bottone']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_link_bottone']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_link_bottone']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_link_bottone']['multi_type'] = 'ol';
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

/* Display: EVA Links Bottoni della Rivista */
$handler = $view->new_display('entity_view', 'EVA Links Bottoni della Rivista', 'entity_view_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['entity_type'] = 'node';
$handler->display->display_options['bundles'] = array(
  0 => 'rivista',
);

/* Display: EVA More Info Rivista */
$handler = $view->new_display('entity_view', 'EVA More Info Rivista', 'entity_view_3');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Campo: Termine della tassonomia: Descrizione */
$handler->display->display_options['fields']['description_field']['id'] = 'description_field';
$handler->display->display_options['fields']['description_field']['table'] = 'field_data_description_field';
$handler->display->display_options['fields']['description_field']['field'] = 'description_field';
$handler->display->display_options['fields']['description_field']['relationship'] = 'field_rivista_realestate_tid';
$handler->display->display_options['fields']['description_field']['label'] = '';
$handler->display->display_options['fields']['description_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['description_field']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['description_field']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['description_field']['link_to_entity'] = 0;
/* Campo: Termine della tassonomia: Specifiche Tecniche */
$handler->display->display_options['fields']['field_specifiche_tecniche']['id'] = 'field_specifiche_tecniche';
$handler->display->display_options['fields']['field_specifiche_tecniche']['table'] = 'field_data_field_specifiche_tecniche';
$handler->display->display_options['fields']['field_specifiche_tecniche']['field'] = 'field_specifiche_tecniche';
$handler->display->display_options['fields']['field_specifiche_tecniche']['relationship'] = 'field_rivista_realestate_tid';
$handler->display->display_options['fields']['field_specifiche_tecniche']['hide_empty'] = TRUE;
/* Campo: Termine della tassonomia: Frequenza di Pubblicazione */
$handler->display->display_options['fields']['field_frequenza_di_pubblicazione']['id'] = 'field_frequenza_di_pubblicazione';
$handler->display->display_options['fields']['field_frequenza_di_pubblicazione']['table'] = 'field_data_field_frequenza_di_pubblicazione';
$handler->display->display_options['fields']['field_frequenza_di_pubblicazione']['field'] = 'field_frequenza_di_pubblicazione';
$handler->display->display_options['fields']['field_frequenza_di_pubblicazione']['relationship'] = 'field_rivista_realestate_tid';
$handler->display->display_options['fields']['field_frequenza_di_pubblicazione']['element_type'] = 'span';
$handler->display->display_options['fields']['field_frequenza_di_pubblicazione']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['field_frequenza_di_pubblicazione']['hide_empty'] = TRUE;
$handler->display->display_options['entity_type'] = 'node';
$handler->display->display_options['bundles'] = array(
  0 => 'rivista',
);
$translatables['button_links_rivista'] = array(
  t('Master'),
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
  t('Tutti'),
  t('EVA Links Bottoni della Rivista'),
  t('EVA More Info Rivista'),
  t('Specifiche Tecniche'),
  t('Frequenza di Pubblicazione'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;