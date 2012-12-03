<?php

$view = new view();
$view->name = 'banner_zona_top';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Banner Zona Top (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Banner Zona Top';
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
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
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
/* Campo: Contenuto: Link Banner */
$handler->display->display_options['fields']['field_link_banner']['id'] = 'field_link_banner';
$handler->display->display_options['fields']['field_link_banner']['table'] = 'field_data_field_link_banner';
$handler->display->display_options['fields']['field_link_banner']['field'] = 'field_link_banner';
$handler->display->display_options['fields']['field_link_banner']['label'] = '';
$handler->display->display_options['fields']['field_link_banner']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_link_banner']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_link_banner']['click_sort_column'] = 'url';
/* Campo: Contenuto: Immagine */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_image']['alter']['path'] = '[field_link_banner]';
$handler->display->display_options['fields']['field_image']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Criterio di ordinamento: Contenuto: Data di inserimento */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Criterio di ordinamento: Campo: Ordine di Visualizzazione (field_ordine) */
$handler->display->display_options['sorts']['field_ordine_value']['id'] = 'field_ordine_value';
$handler->display->display_options['sorts']['field_ordine_value']['table'] = 'field_data_field_ordine';
$handler->display->display_options['sorts']['field_ordine_value']['field'] = 'field_ordine_value';
/* Filter criterion: Contenuto: Pubblicato */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Contenuto: Zona Banner (field_zona_banner) */
$handler->display->display_options['filters']['field_zona_banner_tid']['id'] = 'field_zona_banner_tid';
$handler->display->display_options['filters']['field_zona_banner_tid']['table'] = 'field_data_field_zona_banner';
$handler->display->display_options['filters']['field_zona_banner_tid']['field'] = 'field_zona_banner_tid';
$handler->display->display_options['filters']['field_zona_banner_tid']['value'] = array(
  58 => '58',
);
$handler->display->display_options['filters']['field_zona_banner_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_zona_banner_tid']['vocabulary'] = 'zone_banners';

/* Display: Block Banners Zona Top */
$handler = $view->new_display('block', 'Block Banners Zona Top', 'block');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$translatables['banner_zona_top'] = array(
  t('Master'),
  t('Banner Zona Top'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('_blank'),
  t('Block Banners Zona Top'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;