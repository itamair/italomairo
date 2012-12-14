<?php

$view = new view();
$view->name = 'ultime_riviste';
$view->description = 'Ultimi Numeri di un tipo di Rivista Real Estate';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Ultime Riviste (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Ultime Riviste';
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
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'node';
$handler->display->display_options['row_options']['view_mode'] = 'full';
/* Relazione: Contenuto: Rivista (field_rivista_realestate) */
$handler->display->display_options['relationships']['field_rivista_realestate_tid']['id'] = 'field_rivista_realestate_tid';
$handler->display->display_options['relationships']['field_rivista_realestate_tid']['table'] = 'field_data_field_rivista_realestate';
$handler->display->display_options['relationships']['field_rivista_realestate_tid']['field'] = 'field_rivista_realestate_tid';
$handler->display->display_options['relationships']['field_rivista_realestate_tid']['required'] = TRUE;
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
/* Campo: Termine della tassonomia: ID Termine */
$handler->display->display_options['fields']['tid']['id'] = 'tid';
$handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['tid']['field'] = 'tid';
$handler->display->display_options['fields']['tid']['relationship'] = 'term_node_tid';
$handler->display->display_options['fields']['tid']['exclude'] = TRUE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = 'taxonomy/term/[tid]/[nid]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Campo: Contenuto: Sottotitolo */
$handler->display->display_options['fields']['field_sottotitolo']['id'] = 'field_sottotitolo';
$handler->display->display_options['fields']['field_sottotitolo']['table'] = 'field_data_field_sottotitolo';
$handler->display->display_options['fields']['field_sottotitolo']['field'] = 'field_sottotitolo';
$handler->display->display_options['fields']['field_sottotitolo']['label'] = '';
$handler->display->display_options['fields']['field_sottotitolo']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Copertina */
$handler->display->display_options['fields']['field_imm_copertine']['id'] = 'field_imm_copertine';
$handler->display->display_options['fields']['field_imm_copertine']['table'] = 'field_data_field_imm_copertine';
$handler->display->display_options['fields']['field_imm_copertine']['field'] = 'field_imm_copertine';
$handler->display->display_options['fields']['field_imm_copertine']['label'] = '';
$handler->display->display_options['fields']['field_imm_copertine']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_imm_copertine']['element_wrapper_class'] = 'copertina';
$handler->display->display_options['fields']['field_imm_copertine']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_imm_copertine']['type'] = 'colorbox';
$handler->display->display_options['fields']['field_imm_copertine']['settings'] = array(
  'colorbox_node_style' => 'thumbnail',
  'colorbox_image_style' => '',
  'colorbox_gallery' => 'post',
  'colorbox_gallery_custom' => '',
  'colorbox_caption' => 'auto',
  'colorbox_caption_custom' => '',
);
/* Campo: Contenuto: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = 'Corpo';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
$handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '300',
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
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['validate']['type'] = 'taxonomy_term';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['validate_options']['vocabularies'] = array(
  'riviste_realestate' => 'riviste_realestate',
);
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

/* Display: Block Ultima Rivista */
$handler = $view->new_display('block', 'Block Ultima Rivista', 'block');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

/* Display: In Allegato Archivio */
$handler = $view->new_display('attachment', 'In Allegato Archivio', 'attachment_1');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'in-archvio';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '1';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'node';
$handler->display->display_options['row_options']['view_mode'] = 'riviste_anteprime';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'in archives';
$handler->display->display_options['header']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Contenuto: Rivista (field_rivista_realestate) */
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['id'] = 'field_rivista_realestate_tid';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['table'] = 'field_data_field_rivista_realestate';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['field'] = 'field_rivista_realestate_tid';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['exception']['title'] = 'Tutti';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['default_argument_type'] = 'taxonomy_tid';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['displays'] = array(
  'block' => 'block',
  'default' => 0,
);
$handler->display->display_options['attachment_position'] = 'after';

/* Display: Blocco Archivio Riviste */
$handler = $view->new_display('block', 'Blocco Archivio Riviste', 'block_1');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'in-archvio';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '2';
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
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'node';
$handler->display->display_options['row_options']['view_mode'] = 'riviste_anteprime';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'in archives';
$handler->display->display_options['header']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Contenuto: Rivista (field_rivista_realestate) */
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['id'] = 'field_rivista_realestate_tid';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['table'] = 'field_data_field_rivista_realestate';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['field'] = 'field_rivista_realestate_tid';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['exception']['title'] = 'Tutti';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['default_argument_options']['code'] = 'if ( arg(0) == \'node\' && is_numeric(arg(1)) && !arg(2) ) {
  $node = node_load(arg(1));
$rivista_tid_field = field_get_items(\'node\', $node, \'field_rivista_realestate\');
$rivista_tid = $rivista_tid_field[0][\'tid\'];
return $rivista_tid;
}';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['validate']['type'] = 'taxonomy_term';
$handler->display->display_options['arguments']['field_rivista_realestate_tid']['validate_options']['vocabularies'] = array(
  'riviste_realestate' => 'riviste_realestate',
);
/* Contextual filter: Contenuto: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['exception']['title'] = 'Tutti';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'if ( arg(0) == \'node\' && is_numeric(arg(1)) && !arg(2) ) {
  $node = node_load(arg(1));
  return $node->nid;
}';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
$handler->display->display_options['arguments']['nid']['not'] = TRUE;
$handler->display->display_options['block_description'] = 'Archivio Riviste';
$translatables['ultime_riviste'] = array(
  t('Master'),
  t('Ultime Riviste'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('term from field_rivista_realestate'),
  t('Nid'),
  t('ID Termine'),
  t('.'),
  t(','),
  t('Corpo'),
  t('Tutti'),
  t('Block Ultima Rivista'),
  t('In Allegato Archivio'),
  t('in archives'),
  t('Blocco Archivio Riviste'),
  t('Voci per pagina'),
  t('- Tutto -'),
  t('Slittamento'),
  t('« prima'),
  t('‹ precedente'),
  t('seguente ›'),
  t('ultima »'),
  t('Archivio Riviste'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;