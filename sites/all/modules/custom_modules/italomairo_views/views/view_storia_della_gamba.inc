<?php

$view = new view();
$view->name = 'storia_della_mia_gamba';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Storia della mia gamba (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Storia complessiva della mia gamba destra';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'leggi tutto';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'node';
/* Intestazione: Globale: PHP */
$handler->display->display_options['header']['php']['id'] = 'php';
$handler->display->display_options['header']['php']['table'] = 'views';
$handler->display->display_options['header']['php']['field'] = 'php';
$handler->display->display_options['header']['php']['empty'] = TRUE;
$handler->display->display_options['header']['php']['php_output'] = '<? if (user_is_logged_in()) { 
print \'<div style="position: absolute; right: 20px; top: 30px;"><a href="node/add/evento-gamba-destra">Aggiungi un evento</a></div>\';
 } ?>';
/* Campo: Contenuto: Periodo */
$handler->display->display_options['fields']['field_periodo']['id'] = 'field_periodo';
$handler->display->display_options['fields']['field_periodo']['table'] = 'field_data_field_periodo';
$handler->display->display_options['fields']['field_periodo']['field'] = 'field_periodo';
$handler->display->display_options['fields']['field_periodo']['element_type'] = 'span';
$handler->display->display_options['fields']['field_periodo']['element_label_type'] = 'span';
$handler->display->display_options['fields']['field_periodo']['settings'] = array(
  'format_type' => 'mese_anno',
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
$handler->display->display_options['fields']['title']['element_type'] = 'h3';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Campo: Contenuto: Tipo di Esame */
$handler->display->display_options['fields']['field_tipo_di_esame']['id'] = 'field_tipo_di_esame';
$handler->display->display_options['fields']['field_tipo_di_esame']['table'] = 'field_data_field_tipo_di_esame';
$handler->display->display_options['fields']['field_tipo_di_esame']['field'] = 'field_tipo_di_esame';
$handler->display->display_options['fields']['field_tipo_di_esame']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_tipo_di_esame']['element_type'] = 'span';
$handler->display->display_options['fields']['field_tipo_di_esame']['element_label_type'] = 'span';
$handler->display->display_options['fields']['field_tipo_di_esame']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_tipo_di_esame']['delta_offset'] = '0';
/* Campo: Contenuto: Immagini */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['type'] = 'colorbox';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'colorbox_node_style' => 'thumbnail2',
  'colorbox_image_style' => '',
  'colorbox_gallery' => 'post',
  'colorbox_gallery_custom' => '',
  'colorbox_caption' => 'auto',
  'colorbox_caption_custom' => '',
);
$handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
/* Campo: Contenuto: Allegati */
$handler->display->display_options['fields']['field_allegati']['id'] = 'field_allegati';
$handler->display->display_options['fields']['field_allegati']['table'] = 'field_data_field_allegati';
$handler->display->display_options['fields']['field_allegati']['field'] = 'field_allegati';
$handler->display->display_options['fields']['field_allegati']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_allegati']['type'] = 'file_force_file_default';
$handler->display->display_options['fields']['field_allegati']['delta_offset'] = '0';
/* Criterio di ordinamento: Contenuto: Periodo -  start date (field_periodo) */
$handler->display->display_options['sorts']['field_periodo_value']['id'] = 'field_periodo_value';
$handler->display->display_options['sorts']['field_periodo_value']['table'] = 'field_data_field_periodo';
$handler->display->display_options['sorts']['field_periodo_value']['field'] = 'field_periodo_value';
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
  'evento_gamba_destra' => 'evento_gamba_destra',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'storia-della-mia-gamba';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Storia della mia gamba';
$handler->display->display_options['menu']['weight'] = '20';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Pagina */
$handler = $view->new_display('page', 'Pagina', 'page_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'storia-della-mia-gamba/tutto';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Storia Complessiva';
$handler->display->display_options['menu']['weight'] = '3';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Pagina 2 */
$handler = $view->new_display('page', 'Pagina 2', 'page_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Storia esami ed interventi gamba destra (gonartrosi)';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
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
  'evento_gamba_destra' => 'evento_gamba_destra',
);
/* Filter criterion: Contenuto: Has taxonomy term */
$handler->display->display_options['filters']['tid']['id'] = 'tid';
$handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
$handler->display->display_options['filters']['tid']['field'] = 'tid';
$handler->display->display_options['filters']['tid']['operator'] = 'not empty';
$handler->display->display_options['filters']['tid']['value'] = '';
$handler->display->display_options['filters']['tid']['vocabulary'] = 'tipologia_di_esame';
$handler->display->display_options['path'] = 'storia-della-mia-gamba/esami_e_interventi';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Esami ed Interventi';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Pagina 3 */
$handler = $view->new_display('page', 'Pagina 3', 'page_3');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Immagini esami strumentali svolti';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'node';
$handler->display->display_options['row_options']['view_mode'] = 'immagini_esami_strumentali';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'AND',
  2 => 'OR',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
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
  'evento_gamba_destra' => 'evento_gamba_destra',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Contenuto: Immagini (field_image:fid) */
$handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
$handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
$handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
$handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';
$handler->display->display_options['filters']['field_image_fid']['group'] = 2;
/* Filter criterion: Contenuto: Allegati (field_allegati:fid) */
$handler->display->display_options['filters']['field_allegati_fid']['id'] = 'field_allegati_fid';
$handler->display->display_options['filters']['field_allegati_fid']['table'] = 'field_data_field_allegati';
$handler->display->display_options['filters']['field_allegati_fid']['field'] = 'field_allegati_fid';
$handler->display->display_options['filters']['field_allegati_fid']['operator'] = 'not empty';
$handler->display->display_options['filters']['field_allegati_fid']['group'] = 2;
$handler->display->display_options['path'] = 'storia-della-mia-gamba/immagini_esami';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Immagini Esami';
$handler->display->display_options['menu']['weight'] = '1';
$handler->display->display_options['menu']['context'] = 0;
$translatables['storia_della_mia_gamba'] = array(
  t('Master'),
  t('Storia complessiva della mia gamba destra'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('Periodo'),
  t('Tipo di Esame'),
  t('Allegati'),
  t('Page'),
  t('Pagina'),
  t('Pagina 2'),
  t('Storia esami ed interventi gamba destra (gonartrosi)'),
  t('Pagina 3'),
  t('Immagini esami strumentali svolti'),
);

/* Define this new view from code in views list */
$views[$view->name] = $view;