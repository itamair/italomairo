<?php

$view = new view();
$view->name = 'in_home_grid_content';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'In Home Grid Content (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Focuses & Highlights';
$handler->display->display_options['css_class'] = 'view-home-images-grid isotope-container';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'leggi tutto';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '6';
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
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'isotope-element';
$handler->display->display_options['row_plugin'] = 'fields';
/* Campo: Contenuto: Immagini */
$handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$handler->display->display_options['fields']['field_image']['label'] = '';
$handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => 'threshold-480',
  'image_link' => 'content',
);
$handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_image']['separator'] = '';
/* Campo: Contenuto: Immagini */
$handler->display->display_options['fields']['field_cover_images']['id'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['table'] = 'field_data_field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['field'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['label'] = '';
$handler->display->display_options['fields']['field_cover_images']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_cover_images']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_cover_images']['settings'] = array(
  'image_style' => 'threshold-480',
  'image_link' => 'content',
);
$handler->display->display_options['fields']['field_cover_images']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_cover_images']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_cover_images']['separator'] = '';
/* Campo: Contenuto: Data di Pubblicazione */
$handler->display->display_options['fields']['field_data_di_pubblicazione']['id'] = 'field_data_di_pubblicazione';
$handler->display->display_options['fields']['field_data_di_pubblicazione']['table'] = 'field_data_field_data_di_pubblicazione';
$handler->display->display_options['fields']['field_data_di_pubblicazione']['field'] = 'field_data_di_pubblicazione';
$handler->display->display_options['fields']['field_data_di_pubblicazione']['label'] = '';
$handler->display->display_options['fields']['field_data_di_pubblicazione']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_data_di_pubblicazione']['settings'] = array(
  'format_type' => 'mese_anno',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
/* Campo: Contenuto: Mese di pubblicazione */
$handler->display->display_options['fields']['field_mese_pubblicazione']['id'] = 'field_mese_pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['table'] = 'field_data_field_mese_pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['field'] = 'field_mese_pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['label'] = '';
$handler->display->display_options['fields']['field_mese_pubblicazione']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_mese_pubblicazione']['settings'] = array(
  'format_type' => 'mese_anno',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
/* Campo: Contenuto: Categoria */
$handler->display->display_options['fields']['field_category']['id'] = 'field_category';
$handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
$handler->display->display_options['fields']['field_category']['field'] = 'field_category';
$handler->display->display_options['fields']['field_category']['label'] = '';
$handler->display->display_options['fields']['field_category']['element_class'] = 'category';
$handler->display->display_options['fields']['field_category']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_category']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_category']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_category']['separator'] = '';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h4';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Sottotitolo in Home Page */
$handler->display->display_options['fields']['field_sottottolo']['id'] = 'field_sottottolo';
$handler->display->display_options['fields']['field_sottottolo']['table'] = 'field_data_field_sottottolo';
$handler->display->display_options['fields']['field_sottottolo']['field'] = 'field_sottottolo';
$handler->display->display_options['fields']['field_sottottolo']['label'] = '';
$handler->display->display_options['fields']['field_sottottolo']['element_label_colon'] = FALSE;
/* Campo: Contenuto: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['text'] = '<div>[body]</div>';
$handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
$handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['body']['element_type'] = 'div';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '300',
);
/* Campo: Contenuto: Fonte */
$handler->display->display_options['fields']['field_fonte']['id'] = 'field_fonte';
$handler->display->display_options['fields']['field_fonte']['table'] = 'field_data_field_fonte';
$handler->display->display_options['fields']['field_fonte']['field'] = 'field_fonte';
$handler->display->display_options['fields']['field_fonte']['label'] = 'Source';
$handler->display->display_options['fields']['field_fonte']['element_type'] = 'span';
$handler->display->display_options['fields']['field_fonte']['element_label_type'] = 'span';
$handler->display->display_options['fields']['field_fonte']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_fonte']['click_sort_column'] = 'url';
/* Campo: Contenuto: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['label'] = '';
$handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_node']['text'] = 'Read More';
/* Criterio di ordinamento: Contenuto: Data di Pubblicazione (field_data_di_pubblicazione) */
$handler->display->display_options['sorts']['field_data_di_pubblicazione_value']['id'] = 'field_data_di_pubblicazione_value';
$handler->display->display_options['sorts']['field_data_di_pubblicazione_value']['table'] = 'field_data_field_data_di_pubblicazione';
$handler->display->display_options['sorts']['field_data_di_pubblicazione_value']['field'] = 'field_data_di_pubblicazione_value';
$handler->display->display_options['sorts']['field_data_di_pubblicazione_value']['order'] = 'DESC';
/* Criterio di ordinamento: Contenuto: Mese di pubblicazione (field_mese_pubblicazione) */
$handler->display->display_options['sorts']['field_mese_pubblicazione_value']['id'] = 'field_mese_pubblicazione_value';
$handler->display->display_options['sorts']['field_mese_pubblicazione_value']['table'] = 'field_data_field_mese_pubblicazione';
$handler->display->display_options['sorts']['field_mese_pubblicazione_value']['field'] = 'field_mese_pubblicazione_value';
$handler->display->display_options['sorts']['field_mese_pubblicazione_value']['order'] = 'DESC';
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
/* Filter criterion: Contenuto: In Evidenza Home Page (field_in_slideshow) */
$handler->display->display_options['filters']['field_in_slideshow_value']['id'] = 'field_in_slideshow_value';
$handler->display->display_options['filters']['field_in_slideshow_value']['table'] = 'field_data_field_in_slideshow';
$handler->display->display_options['filters']['field_in_slideshow_value']['field'] = 'field_in_slideshow_value';
$handler->display->display_options['filters']['field_in_slideshow_value']['value'] = array(
  1 => '1',
);
$handler->display->display_options['filters']['field_in_slideshow_value']['group'] = 1;

/* Display: Blocco */
$handler = $view->new_display('block', 'Blocco', 'block_1');
$handler->display->display_options['block_description'] = 'in Home Content Grid';
$translatables['in_home_grid_content'] = array(
  t('Master'),
  t('Focuses & Highlights'),
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
  t('<div>[body]</div>'),
  t('Source'),
  t('Read More'),
  t('Blocco'),
  t('in Home Content Grid'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;