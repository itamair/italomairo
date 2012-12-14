<?php

$view = new view();
$view->name = 'elenco_spazi_pubblicitari';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Elenco Spazi Pubblicitari (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Elenco Spazi Pubblicitari';
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
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['style_options']['columns'] = '2';
$handler->display->display_options['row_plugin'] = 'node';
$handler->display->display_options['row_options']['view_mode'] = 'full';
$handler->display->display_options['row_options']['links'] = FALSE;
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<h3>Real Estate</h3>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Criterio di ordinamento: Contenuto: Prezzo (field_prezzo) */
$handler->display->display_options['sorts']['field_prezzo_value']['id'] = 'field_prezzo_value';
$handler->display->display_options['sorts']['field_prezzo_value']['table'] = 'field_data_field_prezzo';
$handler->display->display_options['sorts']['field_prezzo_value']['field'] = 'field_prezzo_value';
$handler->display->display_options['sorts']['field_prezzo_value']['order'] = 'DESC';
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
  'spazio_pubblicitario' => 'spazio_pubblicitario',
);
/* Filter criterion: Contenuto: Rivista (field_rivista_realestate) */
$handler->display->display_options['filters']['field_rivista_realestate_tid']['id'] = 'field_rivista_realestate_tid';
$handler->display->display_options['filters']['field_rivista_realestate_tid']['table'] = 'field_data_field_rivista_realestate';
$handler->display->display_options['filters']['field_rivista_realestate_tid']['field'] = 'field_rivista_realestate_tid';
$handler->display->display_options['filters']['field_rivista_realestate_tid']['value'] = array(
  54 => '54',
);
$handler->display->display_options['filters']['field_rivista_realestate_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_rivista_realestate_tid']['vocabulary'] = 'riviste_realestate';

/* Display: Spazi Pubblicitari Realestate */
$handler = $view->new_display('block', 'Spazi Pubblicitari Realestate', 'block');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<h3>Real Estate</h3>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
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
  'spazio_pubblicitario' => 'spazio_pubblicitario',
);
/* Filter criterion: Contenuto: Rivista (field_rivista_realestate) */
$handler->display->display_options['filters']['field_rivista_realestate_tid']['id'] = 'field_rivista_realestate_tid';
$handler->display->display_options['filters']['field_rivista_realestate_tid']['table'] = 'field_data_field_rivista_realestate';
$handler->display->display_options['filters']['field_rivista_realestate_tid']['field'] = 'field_rivista_realestate_tid';
$handler->display->display_options['filters']['field_rivista_realestate_tid']['value'] = array(
  54 => '54',
);
$handler->display->display_options['filters']['field_rivista_realestate_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_rivista_realestate_tid']['vocabulary'] = 'riviste_realestate';
$handler->display->display_options['block_description'] = 'Spazi Pubblicitari Real Estate';

/* Display: Spazi Pubblicitari ReEurope */
$handler = $view->new_display('block', 'Spazi Pubblicitari ReEurope', 'block_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<h3>Re Europe</h3>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
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
  'spazio_pubblicitario' => 'spazio_pubblicitario',
);
/* Filter criterion: Contenuto: Rivista (field_rivista_realestate) */
$handler->display->display_options['filters']['field_rivista_realestate_tid']['id'] = 'field_rivista_realestate_tid';
$handler->display->display_options['filters']['field_rivista_realestate_tid']['table'] = 'field_data_field_rivista_realestate';
$handler->display->display_options['filters']['field_rivista_realestate_tid']['field'] = 'field_rivista_realestate_tid';
$handler->display->display_options['filters']['field_rivista_realestate_tid']['value'] = array(
  55 => '55',
);
$handler->display->display_options['filters']['field_rivista_realestate_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_rivista_realestate_tid']['vocabulary'] = 'riviste_realestate';
$handler->display->display_options['block_description'] = 'Spazi Pubblicitari Re Europe';
$translatables['elenco_spazi_pubblicitari'] = array(
  t('Master'),
  t('Elenco Spazi Pubblicitari'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('<h3>Real Estate</h3>'),
  t('Spazi Pubblicitari Realestate'),
  t('Spazi Pubblicitari Real Estate'),
  t('Spazi Pubblicitari ReEurope'),
  t('<h3>Re Europe</h3>'),
  t('Spazi Pubblicitari Re Europe'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;