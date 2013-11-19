<?php

$view = new view();
$view->name = 'slideshow_progetti';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Slideshow Progetti (in code)';
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
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
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
  'field_category' => 0,
  'field_mese_pubblicazione' => 0,
  'title' => 0,
  'field_cover_images' => 0,
  'body' => 0,
  'field_tags' => 0,
  'counter' => 0,
  'nothing' => 0,
);
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
  'counter' => 'counter',
  'field_category' => 0,
  'field_mese_pubblicazione' => 0,
  'title' => 0,
  'field_cover_images' => 0,
  'body' => 0,
  'field_tags' => 0,
  'nothing' => 0,
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
/* Campo: Contenuto: Categoria */
$handler->display->display_options['fields']['field_category']['id'] = 'field_category';
$handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
$handler->display->display_options['fields']['field_category']['field'] = 'field_category';
$handler->display->display_options['fields']['field_category']['label'] = '';
$handler->display->display_options['fields']['field_category']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_category']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_category']['type'] = 'taxonomy_term_reference_csv';
$handler->display->display_options['fields']['field_category']['settings'] = array(
  'links_option' => 0,
  'separator_option' => ' - ',
  'element_option' => 'span',
  'element_class' => '',
  'wrapper_option' => '- None -',
  'wrapper_class' => '',
);
$handler->display->display_options['fields']['field_category']['delta_offset'] = '0';
/* Campo: Contenuto: Mese di pubblicazione */
$handler->display->display_options['fields']['field_mese_pubblicazione']['id'] = 'field_mese_pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['table'] = 'field_data_field_mese_pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['field'] = 'field_mese_pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['label'] = '';
$handler->display->display_options['fields']['field_mese_pubblicazione']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_mese_pubblicazione']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mese_pubblicazione']['settings'] = array(
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
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h3';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
/* Campo: Contenuto: Sottotitolo in Home Page */
$handler->display->display_options['fields']['field_sottottolo']['id'] = 'field_sottottolo';
$handler->display->display_options['fields']['field_sottottolo']['table'] = 'field_data_field_sottottolo';
$handler->display->display_options['fields']['field_sottottolo']['field'] = 'field_sottottolo';
$handler->display->display_options['fields']['field_sottottolo']['label'] = '';
$handler->display->display_options['fields']['field_sottottolo']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_sottottolo']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '200',
);
/* Campo: Contenuto: Data di Pubblicazione */
$handler->display->display_options['fields']['field_data_di_pubblicazione']['id'] = 'field_data_di_pubblicazione';
$handler->display->display_options['fields']['field_data_di_pubblicazione']['table'] = 'field_data_field_data_di_pubblicazione';
$handler->display->display_options['fields']['field_data_di_pubblicazione']['field'] = 'field_data_di_pubblicazione';
$handler->display->display_options['fields']['field_data_di_pubblicazione']['label'] = '';
$handler->display->display_options['fields']['field_data_di_pubblicazione']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_data_di_pubblicazione']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_data_di_pubblicazione']['settings'] = array(
  'format_type' => 'mese_anno',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
/* Campo: Contenuto: Immagini */
$handler->display->display_options['fields']['field_cover_images']['id'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['table'] = 'field_data_field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['field'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['label'] = '';
$handler->display->display_options['fields']['field_cover_images']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_cover_images']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_cover_images']['settings'] = array(
  'image_style' => 'nivo-home',
  'image_link' => 'content',
);
$handler->display->display_options['fields']['field_cover_images']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_cover_images']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_cover_images']['separator'] = '';
/* Campo: Contenuto: Immagini */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => 'nivo-home',
  'image_link' => 'content',
);
$handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
/* Campo: Contenuto: Tags */
$handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
$handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
$handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
$handler->display->display_options['fields']['field_tags']['label'] = '';
$handler->display->display_options['fields']['field_tags']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_tags']['separator'] = '';
/* Campo: Globale: View result counter */
$handler->display->display_options['fields']['counter']['id'] = 'counter';
$handler->display->display_options['fields']['counter']['table'] = 'views';
$handler->display->display_options['fields']['counter']['field'] = 'counter';
$handler->display->display_options['fields']['counter']['label'] = '';
$handler->display->display_options['fields']['counter']['exclude'] = TRUE;
$handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['counter']['counter_start'] = '1';
/* Campo: Globale: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="text-container">
<div class="category">[field_category]</div>
<div class="title">[title_field]</div>
<div class="subtitle">[field_sottottolo]</div>
<div class="data">[field_data_di_pubblicazione]</div>
</div>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'slide-text-container';
$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
/* Criterio di ordinamento: Globale: Casuale */
$handler->display->display_options['sorts']['random']['id'] = 'random';
$handler->display->display_options['sorts']['random']['table'] = 'views';
$handler->display->display_options['sorts']['random']['field'] = 'random';
/* Criterio di ordinamento: Contenuto: Data di inserimento */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'AND',
  2 => 'OR',
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
  'article' => 'article',
  'my_project' => 'my_project',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Contenuto: In Slideshow Home Page (field_in_home_page) */
$handler->display->display_options['filters']['field_in_home_page_value']['id'] = 'field_in_home_page_value';
$handler->display->display_options['filters']['field_in_home_page_value']['table'] = 'field_data_field_in_home_page';
$handler->display->display_options['filters']['field_in_home_page_value']['field'] = 'field_in_home_page_value';
$handler->display->display_options['filters']['field_in_home_page_value']['value'] = array(
  1 => '1',
);
$handler->display->display_options['filters']['field_in_home_page_value']['group'] = 1;
/* Filter criterion: Contenuto: Immagini (field_image:fid) */
$handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
$handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
$handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
$handler->display->display_options['filters']['field_image_fid']['operator'] = '>=';
$handler->display->display_options['filters']['field_image_fid']['value']['value'] = '1';
$handler->display->display_options['filters']['field_image_fid']['group'] = 2;
/* Filter criterion: Contenuto: Immagini (field_cover_images:fid) */
$handler->display->display_options['filters']['field_cover_images_fid']['id'] = 'field_cover_images_fid';
$handler->display->display_options['filters']['field_cover_images_fid']['table'] = 'field_data_field_cover_images';
$handler->display->display_options['filters']['field_cover_images_fid']['field'] = 'field_cover_images_fid';
$handler->display->display_options['filters']['field_cover_images_fid']['operator'] = '>=';
$handler->display->display_options['filters']['field_cover_images_fid']['value']['value'] = '1';
$handler->display->display_options['filters']['field_cover_images_fid']['group'] = 2;

/* Display: Page Slideshow Progetti */
$handler = $view->new_display('page', 'Page Slideshow Progetti', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'slideshow-progetti';

/* Display: Blocco */
$handler = $view->new_display('block', 'Blocco', 'block_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['block_description'] = 'Blocco Slideshow Progetti';
$translatables['slideshow_progetti'] = array(
  t('Master'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('Titolo'),
  t('<div class="text-container">
<div class="category">[field_category]</div>
<div class="title">[title_field]</div>
<div class="subtitle">[field_sottottolo]</div>
<div class="data">[field_data_di_pubblicazione]</div>
</div>'),
  t('Page Slideshow Progetti'),
  t('Blocco'),
  t('Blocco Slideshow Progetti'),
);



/* Define this new view from code in views list */
$views[$view->name] = $view;