<?php

$view = new view();
$view->name = 'immagini_aggiuntive';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Immagini Progetto (in code)';
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
/* Campo: Contenuto: Immagine di copertina */
$handler->display->display_options['fields']['field_cover_images']['id'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['table'] = 'field_data_field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['field'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['label'] = '';
$handler->display->display_options['fields']['field_cover_images']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_cover_images']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_cover_images']['type'] = 'colorbox';
$handler->display->display_options['fields']['field_cover_images']['settings'] = array(
  'colorbox_node_style' => 'minithumbnail-progetti',
  'colorbox_image_style' => '',
  'colorbox_gallery' => 'post',
  'colorbox_gallery_custom' => '',
  'colorbox_caption' => 'auto',
  'colorbox_caption_custom' => '',
);
$handler->display->display_options['fields']['field_cover_images']['delta_limit'] = '5';
$handler->display->display_options['fields']['field_cover_images']['delta_offset'] = '1';
$handler->display->display_options['fields']['field_cover_images']['separator'] = '';
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
  'my_project' => 'my_project',
);

/* Display: EVA Altre Immagini Progetto */
$handler = $view->new_display('entity_view', 'EVA Altre Immagini Progetto', 'entity_view_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['entity_type'] = 'node';
$handler->display->display_options['bundles'] = array(
  0 => 'my_project',
);

/* Display: EVA Immagini Progetto */
$handler = $view->new_display('entity_view', 'EVA Immagini Progetto', 'entity_view_2');
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
/* Campo: Contenuto: Immagine di copertina */
$handler->display->display_options['fields']['field_cover_images']['id'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['table'] = 'field_data_field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['field'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['label'] = '';
$handler->display->display_options['fields']['field_cover_images']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_cover_images']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_cover_images']['type'] = 'colorbox';
$handler->display->display_options['fields']['field_cover_images']['settings'] = array(
  'colorbox_node_style' => 'thumbnail',
  'colorbox_image_style' => '',
  'colorbox_gallery' => 'post',
  'colorbox_gallery_custom' => '',
  'colorbox_caption' => 'auto',
  'colorbox_caption_custom' => '',
);
$handler->display->display_options['fields']['field_cover_images']['delta_limit'] = 'All';
$handler->display->display_options['fields']['field_cover_images']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_cover_images']['separator'] = '';
$handler->display->display_options['entity_type'] = 'node';
$handler->display->display_options['bundles'] = array(
  0 => 'my_project',
);
$translatables['immagini_aggiuntive'] = array(
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
  t('Tutti'),
  t('EVA Altre Immagini Progetto'),
  t('EVA Immagini Progetto'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;