<?php

$view = new view();
$view->name = 'aggregator_feeds';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'aggregator_item';
$view->human_name = 'Aggregator Feeds (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'News';
$handler->display->display_options['css_class'] = 'aggregator-feed';
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
$handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
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
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'timestamp',
    'rendered' => 1,
    'rendered_strip' => 1,
  ),
);
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'title' => 'title',
  'title_2' => 'title_2',
);
$handler->display->display_options['row_options']['separator'] = ' - ';
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'News from the world of construction and architecture';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Campo: Aggregator: Item ID */
$handler->display->display_options['fields']['iid']['id'] = 'iid';
$handler->display->display_options['fields']['iid']['table'] = 'aggregator_item';
$handler->display->display_options['fields']['iid']['field'] = 'iid';
$handler->display->display_options['fields']['iid']['exclude'] = TRUE;
/* Campo: Aggregator: Data e ora */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'aggregator_item';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = '';
$handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
$handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'd M Y';
/* Campo: Aggregator feed: Descrizione */
$handler->display->display_options['fields']['description_1']['id'] = 'description_1';
$handler->display->display_options['fields']['description_1']['table'] = 'aggregator_feed';
$handler->display->display_options['fields']['description_1']['field'] = 'description';
$handler->display->display_options['fields']['description_1']['label'] = '';
$handler->display->display_options['fields']['description_1']['element_label_colon'] = FALSE;
/* Campo: Aggregator category: Categoria */
$handler->display->display_options['fields']['title_1']['id'] = 'title_1';
$handler->display->display_options['fields']['title_1']['table'] = 'aggregator_category';
$handler->display->display_options['fields']['title_1']['field'] = 'title';
$handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
/* Campo: Aggregator: Link */
$handler->display->display_options['fields']['link_1']['id'] = 'link_1';
$handler->display->display_options['fields']['link_1']['table'] = 'aggregator_item';
$handler->display->display_options['fields']['link_1']['field'] = 'link';
$handler->display->display_options['fields']['link_1']['label'] = '';
$handler->display->display_options['fields']['link_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['link_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['link_1']['display_as_link'] = FALSE;
/* Campo: Aggregator feed: Titolo */
$handler->display->display_options['fields']['title_2']['id'] = 'title_2';
$handler->display->display_options['fields']['title_2']['table'] = 'aggregator_feed';
$handler->display->display_options['fields']['title_2']['field'] = 'title';
$handler->display->display_options['fields']['title_2']['label'] = '';
$handler->display->display_options['fields']['title_2']['exclude'] = TRUE;
$handler->display->display_options['fields']['title_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_2']['element_wrapper_type'] = 'h3';
$handler->display->display_options['fields']['title_2']['display_as_link'] = FALSE;
/* Campo: Aggregator: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'aggregator_item';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<a href=[link_1] target="blank">[title]</a> - [title_2]';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h4';
$handler->display->display_options['fields']['title']['display_as_link'] = FALSE;
/* Campo: Aggregator: Corpo */
$handler->display->display_options['fields']['description']['id'] = 'description';
$handler->display->display_options['fields']['description']['table'] = 'aggregator_item';
$handler->display->display_options['fields']['description']['field'] = 'description';
$handler->display->display_options['fields']['description']['label'] = '';
$handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
/* Criterio di ordinamento: Aggregator: Data e ora */
$handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['sorts']['timestamp']['table'] = 'aggregator_item';
$handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';

/* Display: Page News Feeds */
$handler = $view->new_display('page', 'Page News Feeds', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Globale: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['operator'] = 'contains';
$handler->display->display_options['filters']['combine']['exposed'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['label'] = 'cerca nel testo';
$handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
$handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
);
$handler->display->display_options['filters']['combine']['fields'] = array(
  'title' => 'title',
  'description' => 'description',
);
$handler->display->display_options['path'] = 'news';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'News';
$handler->display->display_options['menu']['weight'] = '17';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Blocco */
$handler = $view->new_display('block', 'Blocco', 'block_1');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'aggregator-feed aggregator-feed-block';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'mini';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
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
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Piè di pagina: Globale: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<?php 
global $base_url, $language;
$lng = $language->language;
echo \'<a class="other" href="\'.$base_url.\'/\'.$lng.\'/news">view all</a>\'
?>';
$handler->display->display_options['footer']['area']['format'] = 'php_code';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Aggregator: Item ID */
$handler->display->display_options['fields']['iid']['id'] = 'iid';
$handler->display->display_options['fields']['iid']['table'] = 'aggregator_item';
$handler->display->display_options['fields']['iid']['field'] = 'iid';
$handler->display->display_options['fields']['iid']['exclude'] = TRUE;
/* Campo: Aggregator: Data e ora */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'aggregator_item';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = '';
$handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
$handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'd M Y';
/* Campo: Aggregator: Link */
$handler->display->display_options['fields']['link_1']['id'] = 'link_1';
$handler->display->display_options['fields']['link_1']['table'] = 'aggregator_item';
$handler->display->display_options['fields']['link_1']['field'] = 'link';
$handler->display->display_options['fields']['link_1']['label'] = '';
$handler->display->display_options['fields']['link_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['link_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['link_1']['display_as_link'] = FALSE;
/* Campo: Aggregator feed: Titolo */
$handler->display->display_options['fields']['title_2']['id'] = 'title_2';
$handler->display->display_options['fields']['title_2']['table'] = 'aggregator_feed';
$handler->display->display_options['fields']['title_2']['field'] = 'title';
$handler->display->display_options['fields']['title_2']['label'] = '';
$handler->display->display_options['fields']['title_2']['exclude'] = TRUE;
$handler->display->display_options['fields']['title_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_2']['element_wrapper_type'] = 'h3';
$handler->display->display_options['fields']['title_2']['display_as_link'] = FALSE;
/* Campo: Aggregator: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'aggregator_item';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['display_as_link'] = FALSE;
/* Campo: Globale: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[link_1]" target="blank">[title]</a>  - [title_2]';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['block_description'] = 'News Feeds (last 5)';
$translatables['aggregator_feeds'] = array(
  t('Master'),
  t('News'),
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
  t('News from the world of construction and architecture'),
  t('Item ID'),
  t('.'),
  t(','),
  t('Categoria'),
  t('<a href=[link_1] target="blank">[title]</a> - [title_2]'),
  t('Page News Feeds'),
  t('cerca nel testo'),
  t('Blocco'),
  t('<?php 
global $base_url, $language;
$lng = $language->language;
echo \'<a class="other" href="\'.$base_url.\'/\'.$lng.\'/news">view all</a>\'
?>'),
  t('<a href="[link_1]" target="blank">[title]</a>  - [title_2]'),
  t('News Feeds (last 5)'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;