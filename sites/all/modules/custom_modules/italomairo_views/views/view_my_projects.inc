<?php

$view = new view();
$view->name = 'my_projects_views';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'My Projects (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Projects';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'leggi tutto';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
$handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Slittamento';
$handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
$handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'node';
$handler->display->display_options['row_options']['view_mode'] = 'anteprima_my_project';
$handler->display->display_options['row_options']['links'] = FALSE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Criterio di ordinamento: Contenuto: In corso (field_in_corso) */
$handler->display->display_options['sorts']['field_in_corso_value']['id'] = 'field_in_corso_value';
$handler->display->display_options['sorts']['field_in_corso_value']['table'] = 'field_data_field_in_corso';
$handler->display->display_options['sorts']['field_in_corso_value']['field'] = 'field_in_corso_value';
$handler->display->display_options['sorts']['field_in_corso_value']['order'] = 'DESC';
/* Criterio di ordinamento: Contenuto: Anno fine (field_anno_fine) */
$handler->display->display_options['sorts']['field_anno_fine_value']['id'] = 'field_anno_fine_value';
$handler->display->display_options['sorts']['field_anno_fine_value']['table'] = 'field_data_field_anno_fine';
$handler->display->display_options['sorts']['field_anno_fine_value']['field'] = 'field_anno_fine_value';
$handler->display->display_options['sorts']['field_anno_fine_value']['order'] = 'DESC';
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
/* Filter criterion: Contenuto: Tipo */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'my_project' => 'my_project',
);
$handler->display->display_options['filters']['type']['group'] = 1;

/* Display: Projects Main Page */
$handler = $view->new_display('page', 'Projects Main Page', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'my-projects';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Projects List';
$handler->display->display_options['menu']['weight'] = '10';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: All Projects Page */
$handler = $view->new_display('page', 'All Projects Page', 'page_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'my-projects/all';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'All Projects';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Gis & Web Gis Projects Page */
$handler = $view->new_display('page', 'Gis & Web Gis Projects Page', 'page_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Gis & Web Gis 2.0 Projects';
$handler->display->display_options['enabled'] = FALSE;
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
  'my_project' => 'my_project',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Contenuto: Lingua */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
);
$handler->display->display_options['filters']['language']['group'] = 1;
/* Filter criterion: Contenuto: Has taxonomy terms (with depth) */
$handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
$handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
$handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
$handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
  1 => '1',
  2 => '2',
);
$handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
$handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
$handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'category';
$handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
$handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
$handler->display->display_options['path'] = 'my-projects/gis_webgis';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Gis & Web Gis 2.0';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$translatables['my_projects_views'] = array(
  t('Master'),
  t('Projects'),
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
  t('Projects Main Page'),
  t('All Projects Page'),
  t('Gis & Web Gis Projects Page'),
  t('Gis & Web Gis 2.0 Projects'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;