<?php

$view = new view();
$view->name = 'popular';
$view->description = 'Shows the most-viewed nodes on the site. This requires the statistics to be enabled at administer >> reports >> access log settings.';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Popular content (in code)';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Popular content';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'type' => 'type',
  'title' => 'title',
  'name' => 'name',
  'timestamp' => 'title',
  'totalcount' => 'totalcount',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'type' => array(
    'sortable' => 0,
    'separator' => '',
  ),
  'title' => array(
    'sortable' => 0,
    'separator' => '',
  ),
  'name' => array(
    'sortable' => 0,
    'separator' => '',
  ),
  'timestamp' => array(
    'separator' => '',
  ),
  'totalcount' => array(
    'sortable' => 0,
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['override'] = FALSE;
$handler->display->display_options['style_options']['order'] = 'desc';
/* Relazione: Contenuto: Autore */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Campo: Contenuto: Tipo */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
/* Campo: Utente: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Author';
/* Campo: Contenuto: Ha nuovo contenuto */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'history';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = '';
$handler->display->display_options['fields']['timestamp']['comments'] = TRUE;
/* Criterio di ordinamento: Content statistics: Visualizzazioni totali */
$handler->display->display_options['sorts']['totalcount']['id'] = 'totalcount';
$handler->display->display_options['sorts']['totalcount']['table'] = 'node_counter';
$handler->display->display_options['sorts']['totalcount']['field'] = 'totalcount';
$handler->display->display_options['sorts']['totalcount']['order'] = 'DESC';
/* Filter criterion: Contenuto: Pubblicato */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content statistics: Visualizzazioni totali */
$handler->display->display_options['filters']['totalcount']['id'] = 'totalcount';
$handler->display->display_options['filters']['totalcount']['table'] = 'node_counter';
$handler->display->display_options['filters']['totalcount']['field'] = 'totalcount';
$handler->display->display_options['filters']['totalcount']['operator'] = '>';
$handler->display->display_options['filters']['totalcount']['value']['value'] = '0';
$handler->display->display_options['filters']['totalcount']['group'] = 0;
$handler->display->display_options['filters']['totalcount']['expose']['operator'] = FALSE;

/* Display: Popular (page) */
$handler = $view->new_display('page', 'Popular (page)', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'popular/all';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Popular content';
$handler->display->display_options['menu']['weight'] = '-1';
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Popular content';
$handler->display->display_options['tab_options']['weight'] = '';

/* Display: Today (page) */
$handler = $view->new_display('page', 'Today (page)', 'page_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenuto: Tipo */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
/* Campo: Utente: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = 'Author';
/* Campo: Contenuto: Ha nuovo contenuto */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'history';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = '';
$handler->display->display_options['fields']['timestamp']['comments'] = TRUE;
/* Campo: Content statistics: Visualizzazioni oggi */
$handler->display->display_options['fields']['daycount']['id'] = 'daycount';
$handler->display->display_options['fields']['daycount']['table'] = 'node_counter';
$handler->display->display_options['fields']['daycount']['field'] = 'daycount';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Criterio di ordinamento: Content statistics: Visualizzazioni oggi */
$handler->display->display_options['sorts']['daycount']['id'] = 'daycount';
$handler->display->display_options['sorts']['daycount']['table'] = 'node_counter';
$handler->display->display_options['sorts']['daycount']['field'] = 'daycount';
$handler->display->display_options['sorts']['daycount']['order'] = 'DESC';
$handler->display->display_options['path'] = 'popular/today';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Today\'s popular content';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Popular content';
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Popular (block) */
$handler = $view->new_display('block', 'Popular (block)', 'block');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'title' => 'title',
  'totalcount' => 'totalcount',
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
/* Campo: Content statistics: Visualizzazioni totali */
$handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
$handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
$handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
$handler->display->display_options['fields']['totalcount']['label'] = '';
$handler->display->display_options['fields']['totalcount']['prefix'] = ' (';
$handler->display->display_options['fields']['totalcount']['suffix'] = ')';

/* Display: Today (block) */
$handler = $view->new_display('block', 'Today (block)', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Today\'s popular content';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['link_display'] = FALSE;
$handler->display->display_options['link_display'] = 'page_1';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'title' => 'title',
  'daycount' => 'daycount',
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
/* Campo: Content statistics: Visualizzazioni oggi */
$handler->display->display_options['fields']['daycount']['id'] = 'daycount';
$handler->display->display_options['fields']['daycount']['table'] = 'node_counter';
$handler->display->display_options['fields']['daycount']['field'] = 'daycount';
$handler->display->display_options['fields']['daycount']['label'] = '';
$handler->display->display_options['fields']['daycount']['prefix'] = ' (';
$handler->display->display_options['fields']['daycount']['suffix'] = ')';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Criterio di ordinamento: Content statistics: Visualizzazioni oggi */
$handler->display->display_options['sorts']['daycount']['id'] = 'daycount';
$handler->display->display_options['sorts']['daycount']['table'] = 'node_counter';
$handler->display->display_options['sorts']['daycount']['field'] = 'daycount';
$handler->display->display_options['sorts']['daycount']['order'] = 'DESC';
$translatables['popular'] = array(
  t('Master'),
  t('Popular content'),
  t('more'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('author'),
  t('Tipo'),
  t('Titolo'),
  t('Author'),
  t('Popular (page)'),
  t('leggi tutto'),
  t('Today (page)'),
  t('Visualizzazioni oggi'),
  t('.'),
  t(','),
  t('Popular (block)'),
  t(' ('),
  t(')'),
  t('Today (block)'),
  t('Today\'s popular content'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;