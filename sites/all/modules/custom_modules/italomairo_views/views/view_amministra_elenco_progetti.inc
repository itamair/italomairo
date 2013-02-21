<?php

$view = new view();
$view->name = 'amministra_elenco_progetti';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Amministra Elenco Progetti (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Amministra Elenco Progetti';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'leggi tutto';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'administer nodes';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<div class=\'add-project\' style=\'float: right; margin-right: 20px\'><a href=\'/node/add/my-project\'>Aggiungi un progetto</a></div>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Campo: Operazioni sui contenuti: Contenuto */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
  'action::node_assign_owner_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_delete_item' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_script_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::system_send_email_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_make_sticky_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_modify_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'show_all_tokens' => 1,
      'display_values' => array(
        '_all_' => '_all_',
      ),
    ),
  ),
  'action::system_message_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
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
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_publish_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::system_goto_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_unpublish_by_keyword_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_make_unsticky_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_unpromote_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_unpublish_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::node_save_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::languageassign_set_node_language_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::pathauto_node_update_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
);
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
/* Campo: Contenuto: Immagine di copertina */
$handler->display->display_options['fields']['field_cover_images']['id'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['table'] = 'field_data_field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['field'] = 'field_cover_images';
$handler->display->display_options['fields']['field_cover_images']['label'] = '';
$handler->display->display_options['fields']['field_cover_images']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_cover_images']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_cover_images']['settings'] = array(
  'image_style' => 'square_thumbnail',
  'image_link' => '',
);
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Campo: Contenuto: Mese di pubblicazione */
$handler->display->display_options['fields']['field_mese_pubblicazione']['id'] = 'field_mese_pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['table'] = 'field_data_field_mese_pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['field'] = 'field_mese_pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['label'] = 'Mese di Pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['settings'] = array(
  'format_type' => 'mese_anno',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
/* Campo: Contenuto: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = 'Corpo';
$handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['body']['type'] = 'text_plain';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '250',
);
/* Criterio di ordinamento: Contenuto: Mese di pubblicazione (field_mese_pubblicazione) */
$handler->display->display_options['sorts']['field_mese_pubblicazione_value']['id'] = 'field_mese_pubblicazione_value';
$handler->display->display_options['sorts']['field_mese_pubblicazione_value']['table'] = 'field_data_field_mese_pubblicazione';
$handler->display->display_options['sorts']['field_mese_pubblicazione_value']['field'] = 'field_mese_pubblicazione_value';
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
/* Filter criterion: Contenuto: Mese di pubblicazione (field_mese_pubblicazione) */
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['id'] = 'field_mese_pubblicazione_value';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['table'] = 'field_data_field_mese_pubblicazione';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['field'] = 'field_mese_pubblicazione_value';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['operator'] = '>=';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['expose']['operator_id'] = 'field_mese_pubblicazione_value_op';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['expose']['label'] = 'Mese di pubblicazione';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['expose']['operator'] = 'field_mese_pubblicazione_value_op';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['expose']['identifier'] = 'field_mese_pubblicazione_value';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['granularity'] = 'month';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['year_range'] = '-3:+1';

/* Display: Page Elenco Progetti */
$handler = $view->new_display('page', 'Page Elenco Progetti', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'amministra-elenco-progetti';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Amministra Elenco Progetti';
$handler->display->display_options['menu']['weight'] = '50';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Feed Export to Excel */
$handler = $view->new_display('feed', 'Feed Export to Excel', 'feed_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'xls';
$handler->display->display_options['defaults']['footer'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Campo: Contenuto: Mese di pubblicazione */
$handler->display->display_options['fields']['field_mese_pubblicazione']['id'] = 'field_mese_pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['table'] = 'field_data_field_mese_pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['field'] = 'field_mese_pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['label'] = 'Mese di Pubblicazione';
$handler->display->display_options['fields']['field_mese_pubblicazione']['settings'] = array(
  'format_type' => 'mese_anno',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
/* Campo: Contenuto: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = 'Corpo';
$handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['body']['type'] = 'text_plain';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '250',
);
$handler->display->display_options['path'] = 'export-elenco-progetti';
$handler->display->display_options['displays'] = array(
  'page' => 'page',
  'default' => 0,
);
$translatables['amministra_elenco_progetti'] = array(
  t('Master'),
  t('Amministra Elenco Progetti'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('<div class=\'add-project\' style=\'float: right; margin-right: 20px\'><a href=\'/node/add/my-project\'>Aggiungi un progetto</a></div>'),
  t('Contenuto'),
  t('Nid'),
  t('Titolo'),
  t('Mese di Pubblicazione'),
  t('Corpo'),
  t('Mese di pubblicazione'),
  t('Page Elenco Progetti'),
  t('Feed Export to Excel'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;