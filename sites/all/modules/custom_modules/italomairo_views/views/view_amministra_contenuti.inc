<?php

$view = new view();
$view->name = 'amministra_i_contenuti';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Amministra i contenuti (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Amministra contenuti Sito';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'leggi tutto';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'administer nodes';
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
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
$handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Slittamento';
$handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
$handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'views_bulk_operations' => 'views_bulk_operations',
  'title' => 'title',
  'title_field' => 'title_field',
  'type' => 'type',
  'created' => 'created',
  'changed' => 'changed',
  'name' => 'name',
  'edit_node' => 'edit_node',
);
$handler->display->display_options['style_options']['default'] = 'changed';
$handler->display->display_options['style_options']['info'] = array(
  'views_bulk_operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title_field' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'type' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'changed' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'edit_node' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Intestazione: Globale: PHP */
$handler->display->display_options['header']['php']['id'] = 'php';
$handler->display->display_options['header']['php']['table'] = 'views';
$handler->display->display_options['header']['php']['field'] = 'php';
$handler->display->display_options['header']['php']['php_output'] = '<?php
  $view = views_get_current_view();
  //dpm($view);
  echo \'<p>\'.t("Number of found results: "). count($view->result).\'</p>\'; 
?>';
/* Relazione: Contenuto: Autore */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
/* Campo: Operazioni sui contenuti: Contenuto */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
  'action::node_assign_owner_action' => array(
    'selected' => 1,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::views_bulk_operations_delete_item' => array(
    'selected' => 1,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::views_bulk_operations_script_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::system_send_email_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::node_make_sticky_action' => array(
    'selected' => 1,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::views_bulk_operations_modify_action' => array(
    'selected' => 1,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'show_all_tokens' => 1,
      'display_values' => array(
        '_all_' => '_all_',
      ),
    ),
    'postpone_processing' => 0,
  ),
  'action::system_message_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::views_bulk_operations_argument_selector_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'url' => '',
    ),
  ),
  'action::node_promote_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::node_publish_action' => array(
    'selected' => 1,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::system_goto_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::node_unpublish_by_keyword_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::node_make_unsticky_action' => array(
    'selected' => 1,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::node_unpromote_action' => array(
    'selected' => 1,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::node_unpublish_action' => array(
    'selected' => 1,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::node_save_action' => array(
    'selected' => 1,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::mimemail_send_email_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::languageassign_set_node_language_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
  'action::pathauto_node_update_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'postpone_processing' => 0,
  ),
);
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = 'Titolo (tradotto)';
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
/* Campo: Contenuto: Tipo */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Campo: Contenuto: Pubblicato */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Campo: Contenuto: In Slideshow Home Page */
$handler->display->display_options['fields']['field_in_home_page']['id'] = 'field_in_home_page';
$handler->display->display_options['fields']['field_in_home_page']['table'] = 'field_data_field_in_home_page';
$handler->display->display_options['fields']['field_in_home_page']['field'] = 'field_in_home_page';
/* Campo: Contenuto: In Evidenza Home Page */
$handler->display->display_options['fields']['field_in_slideshow']['id'] = 'field_in_slideshow';
$handler->display->display_options['fields']['field_in_slideshow']['table'] = 'field_data_field_in_slideshow';
$handler->display->display_options['fields']['field_in_slideshow']['field'] = 'field_in_slideshow';
$handler->display->display_options['fields']['field_in_slideshow']['label'] = 'In Evidenza Homepage';
/* Campo: Contenuto: In Blog */
$handler->display->display_options['fields']['field_in_blog']['id'] = 'field_in_blog';
$handler->display->display_options['fields']['field_in_blog']['table'] = 'field_data_field_in_blog';
$handler->display->display_options['fields']['field_in_blog']['field'] = 'field_in_blog';
/* Campo: Contenuto: Data di inserimento */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Inserimento';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
/* Campo: Contenuto: Data di aggiornamento */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['label'] = 'Aggiornato';
$handler->display->display_options['fields']['changed']['date_format'] = 'raw time ago';
/* Campo: Utente: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Autore';
/* Campo: Contenuto: Link modifica */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = 'Operazioni';
$handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node] <a href=\'/node/[nid]/translate\'>tranlslate</a>';
$handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
/* Criterio di ordinamento: Contenuto: Data di aggiornamento */
$handler->display->display_options['sorts']['changed']['id'] = 'changed';
$handler->display->display_options['sorts']['changed']['table'] = 'node';
$handler->display->display_options['sorts']['changed']['field'] = 'changed';
$handler->display->display_options['sorts']['changed']['order'] = 'DESC';
/* Criterio di ordinamento: Contenuto: Data di inserimento */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Contenuto: Pubblicato o in amministrazione */
$handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
$handler->display->display_options['filters']['status_extra']['table'] = 'node';
$handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
$handler->display->display_options['filters']['status_extra']['group'] = 1;
/* Filter criterion: Contenuto: Tipo */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'article' => 'article',
  'curriculum_vitae' => 'curriculum_vitae',
  'evento_gamba_destra' => 'evento_gamba_destra',
  'my_project' => 'my_project',
  'page' => 'page',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Contenuto: Tipo */
$handler->display->display_options['filters']['type_1']['id'] = 'type_1';
$handler->display->display_options['filters']['type_1']['table'] = 'node';
$handler->display->display_options['filters']['type_1']['field'] = 'type';
$handler->display->display_options['filters']['type_1']['value'] = array(
  'article' => 'article',
  'curriculum_vitae' => 'curriculum_vitae',
  'my_project' => 'my_project',
  'page' => 'page',
);
$handler->display->display_options['filters']['type_1']['group'] = 1;
$handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
$handler->display->display_options['filters']['type_1']['expose']['label'] = 'Tipo';
$handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
$handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
$handler->display->display_options['filters']['type_1']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
  2 => 0,
  3 => '3',
  1 => 0,
);
$handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;
/* Filter criterion: Utente: Name (raw) */
$handler->display->display_options['filters']['name']['id'] = 'name';
$handler->display->display_options['filters']['name']['table'] = 'users';
$handler->display->display_options['filters']['name']['field'] = 'name';
$handler->display->display_options['filters']['name']['relationship'] = 'uid';
$handler->display->display_options['filters']['name']['operator'] = 'contains';
$handler->display->display_options['filters']['name']['group'] = 1;
$handler->display->display_options['filters']['name']['exposed'] = TRUE;
$handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
$handler->display->display_options['filters']['name']['expose']['label'] = 'Autore';
$handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
$handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
$handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  5 => 0,
  4 => 0,
  6 => 0,
  7 => 0,
  8 => 0,
);
/* Filter criterion: Contenuto: In Evidenza Home Page (field_in_slideshow) */
$handler->display->display_options['filters']['field_in_slideshow_value']['id'] = 'field_in_slideshow_value';
$handler->display->display_options['filters']['field_in_slideshow_value']['table'] = 'field_data_field_in_slideshow';
$handler->display->display_options['filters']['field_in_slideshow_value']['field'] = 'field_in_slideshow_value';
$handler->display->display_options['filters']['field_in_slideshow_value']['group'] = 1;
$handler->display->display_options['filters']['field_in_slideshow_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_in_slideshow_value']['expose']['operator_id'] = 'field_in_slideshow_value_op';
$handler->display->display_options['filters']['field_in_slideshow_value']['expose']['label'] = 'In Slideshow';
$handler->display->display_options['filters']['field_in_slideshow_value']['expose']['operator'] = 'field_in_slideshow_value_op';
$handler->display->display_options['filters']['field_in_slideshow_value']['expose']['identifier'] = 'field_in_slideshow_value';
$handler->display->display_options['filters']['field_in_slideshow_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
);
/* Filter criterion: Contenuto: In Slideshow Home Page (field_in_home_page) */
$handler->display->display_options['filters']['field_in_home_page_value']['id'] = 'field_in_home_page_value';
$handler->display->display_options['filters']['field_in_home_page_value']['table'] = 'field_data_field_in_home_page';
$handler->display->display_options['filters']['field_in_home_page_value']['field'] = 'field_in_home_page_value';
$handler->display->display_options['filters']['field_in_home_page_value']['group'] = 1;
$handler->display->display_options['filters']['field_in_home_page_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_in_home_page_value']['expose']['operator_id'] = 'field_in_home_page_value_op';
$handler->display->display_options['filters']['field_in_home_page_value']['expose']['label'] = 'In Home Page';
$handler->display->display_options['filters']['field_in_home_page_value']['expose']['operator'] = 'field_in_home_page_value_op';
$handler->display->display_options['filters']['field_in_home_page_value']['expose']['identifier'] = 'field_in_home_page_value';
$handler->display->display_options['filters']['field_in_home_page_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
/* Filter criterion: Contenuto: In Blog (field_in_blog) */
$handler->display->display_options['filters']['field_in_blog_value']['id'] = 'field_in_blog_value';
$handler->display->display_options['filters']['field_in_blog_value']['table'] = 'field_data_field_in_blog';
$handler->display->display_options['filters']['field_in_blog_value']['field'] = 'field_in_blog_value';
$handler->display->display_options['filters']['field_in_blog_value']['group'] = 1;
$handler->display->display_options['filters']['field_in_blog_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_in_blog_value']['expose']['operator_id'] = 'field_in_blog_value_op';
$handler->display->display_options['filters']['field_in_blog_value']['expose']['label'] = 'In Blog';
$handler->display->display_options['filters']['field_in_blog_value']['expose']['operator'] = 'field_in_blog_value_op';
$handler->display->display_options['filters']['field_in_blog_value']['expose']['identifier'] = 'field_in_blog_value';
$handler->display->display_options['filters']['field_in_blog_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'manage_site_content';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Amministra contenuti Sito';
$handler->display->display_options['menu']['weight'] = '15';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'manage_content';
$handler->display->display_options['tab_options']['weight'] = '0';
$handler->display->display_options['tab_options']['name'] = 'main-menu';
$translatables['amministra_i_contenuti'] = array(
  t('Master'),
  t('Amministra contenuti Sito'),
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
  t('author'),
  t('Nid'),
  t('Contenuto'),
  t('scegli un operazione'),
  t('Titolo (tradotto)'),
  t('Tipo'),
  t('Pubblicato'),
  t('In Slideshow Home Page'),
  t('In Evidenza Homepage'),
  t('In Blog'),
  t('Inserimento'),
  t('Aggiornato'),
  t('Autore'),
  t('Operazioni'),
  t('[edit_node] <a href=\'/node/[nid]/translate\'>tranlslate</a>'),
  t('In Slideshow'),
  t('In Home Page'),
  t('Page'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;