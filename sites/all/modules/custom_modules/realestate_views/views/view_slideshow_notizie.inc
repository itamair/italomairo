<?php

$view = new view();
$view->name = 'slideshow_notizie';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Slideshow Notizie (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Slideshow';
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
$handler->display->display_options['pager']['options']['items_per_page'] = '4';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'slideshow';
$handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
$handler->display->display_options['style_options']['slideshow_skin'] = 'default';
$handler->display->display_options['style_options']['skin_info'] = array(
  'class' => 'default',
  'name' => 'Predefinito',
  'module' => 'views_slideshow',
  'path' => '',
  'stylesheets' => array(),
);
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
  'field_video' => 0,
  'field_image' => 0,
  'field_immagini' => 0,
  'created' => 0,
  'title' => 0,
  'body' => 0,
  'counter' => 0,
);
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
  'counter' => 'counter',
  'field_video' => 0,
  'field_image' => 0,
  'field_immagini' => 0,
  'created' => 0,
  'title' => 0,
  'body' => 0,
);
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
$handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
$handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
$handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
$handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
$handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
$handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
$handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
$handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
$handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
$handler->display->display_options['row_plugin'] = 'fields';
/* Campo: Contenuto: Immagine */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => 'slideshow',
  'image_link' => 'content',
);
/* Campo: Contenuto: Immagine Spazio Pubblicitario */
$handler->display->display_options['fields']['field_immagini']['id'] = 'field_immagini';
$handler->display->display_options['fields']['field_immagini']['table'] = 'field_data_field_immagini';
$handler->display->display_options['fields']['field_immagini']['field'] = 'field_immagini';
$handler->display->display_options['fields']['field_immagini']['label'] = '';
$handler->display->display_options['fields']['field_immagini']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_immagini']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_immagini']['settings'] = array(
  'image_style' => 'slideshow',
  'image_link' => '',
);
/* Campo: Contenuto: Copertina */
$handler->display->display_options['fields']['field_imm_copertine']['id'] = 'field_imm_copertine';
$handler->display->display_options['fields']['field_imm_copertine']['table'] = 'field_data_field_imm_copertine';
$handler->display->display_options['fields']['field_imm_copertine']['field'] = 'field_imm_copertine';
$handler->display->display_options['fields']['field_imm_copertine']['label'] = '';
$handler->display->display_options['fields']['field_imm_copertine']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_imm_copertine']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_imm_copertine']['settings'] = array(
  'image_style' => 'slideshow',
  'image_link' => '',
);
/* Campo: Contenuto: Data di inserimento */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'medium';
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
/* Campo: Contenuto: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '350',
);
/* Campo: Globale: View result counter */
$handler->display->display_options['fields']['counter']['id'] = 'counter';
$handler->display->display_options['fields']['counter']['table'] = 'views';
$handler->display->display_options['fields']['counter']['field'] = 'counter';
$handler->display->display_options['fields']['counter']['label'] = '';
$handler->display->display_options['fields']['counter']['exclude'] = TRUE;
$handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['counter']['counter_start'] = '1';
/* Criterio di ordinamento: Contenuto: Data di pubblicazione della Notizia (field_data) */
$handler->display->display_options['sorts']['field_data_value']['id'] = 'field_data_value';
$handler->display->display_options['sorts']['field_data_value']['table'] = 'field_data_field_data';
$handler->display->display_options['sorts']['field_data_value']['field'] = 'field_data_value';
$handler->display->display_options['sorts']['field_data_value']['order'] = 'DESC';
/* Criterio di ordinamento: Contenuto: Data di inserimento */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
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
  'notizia' => 'notizia',
);
/* Filter criterion: Contenuto: In evidenza/slideshow home (field_in_evidenza) */
$handler->display->display_options['filters']['field_in_evidenza_value']['id'] = 'field_in_evidenza_value';
$handler->display->display_options['filters']['field_in_evidenza_value']['table'] = 'field_data_field_in_evidenza';
$handler->display->display_options['filters']['field_in_evidenza_value']['field'] = 'field_in_evidenza_value';
$handler->display->display_options['filters']['field_in_evidenza_value']['value'] = array(
  1 => '1',
);

/* Display: Slideshow Notizie */
$handler = $view->new_display('block', 'Slideshow Notizie', 'block');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$translatables['slideshow_notizie'] = array(
  t('Master'),
  t('Slideshow'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('Slideshow Notizie'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;