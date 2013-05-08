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
$handler->display->display_options['title'] = 'Storia della mia gamba';
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
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'node';
/* Intestazione: Globale: PHP */
$handler->display->display_options['header']['php']['id'] = 'php';
$handler->display->display_options['header']['php']['table'] = 'views';
$handler->display->display_options['header']['php']['field'] = 'php';
$handler->display->display_options['header']['php']['php_output'] = '<? if (user_is_logged_in()) { 
print \'<div style="position: absolute; right: 10px; top: 10px; z-index: 100;"><a href="node/add/evento-gamba-destra">Aggiungi un evento</a></div>\';
 } ?>';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
$translatables['storia_della_mia_gamba'] = array(
  t('Master'),
  t('Storia della mia gamba'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('Page'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;