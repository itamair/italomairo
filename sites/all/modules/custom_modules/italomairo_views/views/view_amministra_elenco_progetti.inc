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
$handler->display->display_options['title'] = 'Elenco Progetti';
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
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
/* Campo: Contenuto: id_progetto */
$handler->display->display_options['fields']['field_id_progetto']['id'] = 'field_id_progetto';
$handler->display->display_options['fields']['field_id_progetto']['table'] = 'field_data_field_id_progetto';
$handler->display->display_options['fields']['field_id_progetto']['field'] = 'field_id_progetto';
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
$handler->display->display_options['fields']['field_cover_images']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_cover_images']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_cover_images']['separator'] = '';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = 'Titolo English';
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
/* Campo: Contenuto: Pubblicato */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['not'] = 0;
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
$handler->display->display_options['fields']['body']['label'] = 'Descrizione';
$handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['body']['type'] = 'text_plain';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '250',
);
/* Campo: Contenuto: Committenti */
$handler->display->display_options['fields']['field_committente']['id'] = 'field_committente';
$handler->display->display_options['fields']['field_committente']['table'] = 'field_data_field_committente';
$handler->display->display_options['fields']['field_committente']['field'] = 'field_committente';
$handler->display->display_options['fields']['field_committente']['label'] = 'committente';
$handler->display->display_options['fields']['field_committente']['delta_offset'] = '0';
/* Campo: Contenuto: Link modifica */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = '';
$handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['edit_node']['text'] = 'edit';
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
  'my_project' => 'my_project',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Contenuto: Mese di pubblicazione (field_mese_pubblicazione) */
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['id'] = 'field_mese_pubblicazione_value';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['table'] = 'field_data_field_mese_pubblicazione';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['field'] = 'field_mese_pubblicazione_value';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['operator'] = '>=';
$handler->display->display_options['filters']['field_mese_pubblicazione_value']['group'] = 1;
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
/* Campo: Contenuto: id_progetto */
$handler->display->display_options['fields']['field_id_progetto']['id'] = 'field_id_progetto';
$handler->display->display_options['fields']['field_id_progetto']['table'] = 'field_data_field_id_progetto';
$handler->display->display_options['fields']['field_id_progetto']['field'] = 'field_id_progetto';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'titolo';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_descrizione_breve']['id'] = 'field_descrizione_breve';
$handler->display->display_options['fields']['field_descrizione_breve']['table'] = 'field_data_field_descrizione_breve';
$handler->display->display_options['fields']['field_descrizione_breve']['field'] = 'field_descrizione_breve';
$handler->display->display_options['fields']['field_descrizione_breve']['label'] = 'descrizione_breve';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_anno_inizio']['id'] = 'field_anno_inizio';
$handler->display->display_options['fields']['field_anno_inizio']['table'] = 'field_data_field_anno_inizio';
$handler->display->display_options['fields']['field_anno_inizio']['field'] = 'field_anno_inizio';
$handler->display->display_options['fields']['field_anno_inizio']['label'] = 'anno_inizio';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_anno_fine']['id'] = 'field_anno_fine';
$handler->display->display_options['fields']['field_anno_fine']['table'] = 'field_data_field_anno_fine';
$handler->display->display_options['fields']['field_anno_fine']['field'] = 'field_anno_fine';
$handler->display->display_options['fields']['field_anno_fine']['label'] = 'anno_fine';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_in_corso']['id'] = 'field_in_corso';
$handler->display->display_options['fields']['field_in_corso']['table'] = 'field_data_field_in_corso';
$handler->display->display_options['fields']['field_in_corso']['field'] = 'field_in_corso';
$handler->display->display_options['fields']['field_in_corso']['label'] = 'in_corso';
/* Campo: Contenuto: Committenti */
$handler->display->display_options['fields']['field_committente']['id'] = 'field_committente';
$handler->display->display_options['fields']['field_committente']['table'] = 'field_data_field_committente';
$handler->display->display_options['fields']['field_committente']['field'] = 'field_committente';
$handler->display->display_options['fields']['field_committente']['label'] = 'committente';
$handler->display->display_options['fields']['field_committente']['delta_offset'] = '0';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_direzione_lavori']['id'] = 'field_direzione_lavori';
$handler->display->display_options['fields']['field_direzione_lavori']['table'] = 'field_data_field_direzione_lavori';
$handler->display->display_options['fields']['field_direzione_lavori']['field'] = 'field_direzione_lavori';
$handler->display->display_options['fields']['field_direzione_lavori']['label'] = 'direzione_lavori';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_progettazione_preliminare']['id'] = 'field_progettazione_preliminare';
$handler->display->display_options['fields']['field_progettazione_preliminare']['table'] = 'field_data_field_progettazione_preliminare';
$handler->display->display_options['fields']['field_progettazione_preliminare']['field'] = 'field_progettazione_preliminare';
$handler->display->display_options['fields']['field_progettazione_preliminare']['label'] = 'progettazione_preliminare';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_progettazione_definitiva']['id'] = 'field_progettazione_definitiva';
$handler->display->display_options['fields']['field_progettazione_definitiva']['table'] = 'field_data_field_progettazione_definitiva';
$handler->display->display_options['fields']['field_progettazione_definitiva']['field'] = 'field_progettazione_definitiva';
$handler->display->display_options['fields']['field_progettazione_definitiva']['label'] = 'progettazione_definitiva';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_progettazione_esecutiva']['id'] = 'field_progettazione_esecutiva';
$handler->display->display_options['fields']['field_progettazione_esecutiva']['table'] = 'field_data_field_progettazione_esecutiva';
$handler->display->display_options['fields']['field_progettazione_esecutiva']['field'] = 'field_progettazione_esecutiva';
$handler->display->display_options['fields']['field_progettazione_esecutiva']['label'] = 'progettazione_esecutiva';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_ia']['id'] = 'field_ia';
$handler->display->display_options['fields']['field_ia']['table'] = 'field_data_field_ia';
$handler->display->display_options['fields']['field_ia']['field'] = 'field_ia';
$handler->display->display_options['fields']['field_ia']['label'] = 'ia';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_ib']['id'] = 'field_ib';
$handler->display->display_options['fields']['field_ib']['table'] = 'field_data_field_ib';
$handler->display->display_options['fields']['field_ib']['field'] = 'field_ib';
$handler->display->display_options['fields']['field_ib']['label'] = 'ib';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_ic']['id'] = 'field_ic';
$handler->display->display_options['fields']['field_ic']['table'] = 'field_data_field_ic';
$handler->display->display_options['fields']['field_ic']['field'] = 'field_ic';
$handler->display->display_options['fields']['field_ic']['label'] = 'ic';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_id']['id'] = 'field_id';
$handler->display->display_options['fields']['field_id']['table'] = 'field_data_field_id';
$handler->display->display_options['fields']['field_id']['field'] = 'field_id';
$handler->display->display_options['fields']['field_id']['label'] = 'id';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_ie']['id'] = 'field_ie';
$handler->display->display_options['fields']['field_ie']['table'] = 'field_data_field_ie';
$handler->display->display_options['fields']['field_ie']['field'] = 'field_ie';
$handler->display->display_options['fields']['field_ie']['label'] = 'ie';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_if']['id'] = 'field_if';
$handler->display->display_options['fields']['field_if']['table'] = 'field_data_field_if';
$handler->display->display_options['fields']['field_if']['field'] = 'field_if';
$handler->display->display_options['fields']['field_if']['label'] = 'if';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_ig']['id'] = 'field_ig';
$handler->display->display_options['fields']['field_ig']['table'] = 'field_data_field_ig';
$handler->display->display_options['fields']['field_ig']['field'] = 'field_ig';
$handler->display->display_options['fields']['field_ig']['label'] = 'ig';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_iiia']['id'] = 'field_iiia';
$handler->display->display_options['fields']['field_iiia']['table'] = 'field_data_field_iiia';
$handler->display->display_options['fields']['field_iiia']['field'] = 'field_iiia';
$handler->display->display_options['fields']['field_iiia']['label'] = 'iiia';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_iiib']['id'] = 'field_iiib';
$handler->display->display_options['fields']['field_iiib']['table'] = 'field_data_field_iiib';
$handler->display->display_options['fields']['field_iiib']['field'] = 'field_iiib';
$handler->display->display_options['fields']['field_iiib']['label'] = 'iiib';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_iiic']['id'] = 'field_iiic';
$handler->display->display_options['fields']['field_iiic']['table'] = 'field_data_field_iiic';
$handler->display->display_options['fields']['field_iiic']['field'] = 'field_iiic';
$handler->display->display_options['fields']['field_iiic']['label'] = 'iiic';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_iva']['id'] = 'field_iva';
$handler->display->display_options['fields']['field_iva']['table'] = 'field_data_field_iva';
$handler->display->display_options['fields']['field_iva']['field'] = 'field_iva';
$handler->display->display_options['fields']['field_iva']['label'] = 'iva';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_vib']['id'] = 'field_vib';
$handler->display->display_options['fields']['field_vib']['table'] = 'field_data_field_vib';
$handler->display->display_options['fields']['field_vib']['field'] = 'field_vib';
$handler->display->display_options['fields']['field_vib']['label'] = 'vib';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_ixa']['id'] = 'field_ixa';
$handler->display->display_options['fields']['field_ixa']['table'] = 'field_data_field_ixa';
$handler->display->display_options['fields']['field_ixa']['field'] = 'field_ixa';
$handler->display->display_options['fields']['field_ixa']['label'] = 'ixa';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_ixb']['id'] = 'field_ixb';
$handler->display->display_options['fields']['field_ixb']['table'] = 'field_data_field_ixb';
$handler->display->display_options['fields']['field_ixb']['field'] = 'field_ixb';
$handler->display->display_options['fields']['field_ixb']['label'] = 'ixb';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_ixc']['id'] = 'field_ixc';
$handler->display->display_options['fields']['field_ixc']['table'] = 'field_data_field_ixc';
$handler->display->display_options['fields']['field_ixc']['field'] = 'field_ixc';
$handler->display->display_options['fields']['field_ixc']['label'] = 'ixc';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_sicurezza_coordinamento_pr']['id'] = 'field_sicurezza_coordinamento_pr';
$handler->display->display_options['fields']['field_sicurezza_coordinamento_pr']['table'] = 'field_data_field_sicurezza_coordinamento_pr';
$handler->display->display_options['fields']['field_sicurezza_coordinamento_pr']['field'] = 'field_sicurezza_coordinamento_pr';
$handler->display->display_options['fields']['field_sicurezza_coordinamento_pr']['label'] = 'sicurezza_coordinamento_progettazione';
/* Campo: Gestore rotto/mancante */
$handler->display->display_options['fields']['field_sicurezza_coordinamento_es']['id'] = 'field_sicurezza_coordinamento_es';
$handler->display->display_options['fields']['field_sicurezza_coordinamento_es']['table'] = 'field_data_field_sicurezza_coordinamento_es';
$handler->display->display_options['fields']['field_sicurezza_coordinamento_es']['field'] = 'field_sicurezza_coordinamento_es';
$handler->display->display_options['fields']['field_sicurezza_coordinamento_es']['label'] = 'sicurezza_coordinamento_esecuzione';
$handler->display->display_options['path'] = 'export-elenco-progetti';
$handler->display->display_options['displays'] = array(
  'page' => 'page',
  'default' => 0,
);

/* Display: Blocco Altri Progetti */
$handler = $view->new_display('block', 'Blocco Altri Progetti', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Other Projects';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'mini';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '3';
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
$handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Slittamento';
$handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
$handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'title' => 'title',
  'field_mese_pubblicazione' => 'field_mese_pubblicazione',
);
$handler->display->display_options['row_options']['separator'] = ' - ';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Contenuto: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['nid']['exception']['title'] = 'Tutti';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['nid']['not'] = TRUE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Contenuto: Pubblicato */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
/* Filter criterion: Contenuto: Tipo */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'my_project' => 'my_project',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['block_description'] = 'Altri Progetti';

/* Display: Blocco Elenco Progetti con Mappa Grande */
$handler = $view->new_display('block', 'Blocco Elenco Progetti con Mappa Grande', 'block_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Projects';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'mini';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '3';
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
$handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Slittamento';
$handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
$handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'title' => 'title',
  'field_mese_pubblicazione' => 'field_mese_pubblicazione',
  'nid' => 'nid',
);
$handler->display->display_options['row_options']['separator'] = ' - ';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
/* Campo: Contenuto: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = '<a href="/node/[nid]" nid="[nid]" class="map-zoom">zoom in map</a>';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Contenuto: Pubblicato */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
/* Filter criterion: Contenuto: Tipo */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'my_project' => 'my_project',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['block_description'] = 'Elenco Progetti con Mappa';
$translatables['amministra_elenco_progetti'] = array(
  t('Master'),
  t('Elenco Progetti'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('<div class=\'add-project\' style=\'float: right; margin-right: 20px\'><a href=\'/node/add/my-project\'>Aggiungi un progetto</a></div>'),
  t('Contenuto'),
  t('Nid'),
  t('id_progetto'),
  t('Titolo'),
  t('Titolo English'),
  t('Pubblicato'),
  t('Mese di Pubblicazione'),
  t('Descrizione'),
  t('committente'),
  t('edit'),
  t('Mese di pubblicazione'),
  t('Page Elenco Progetti'),
  t('Feed Export to Excel'),
  t('titolo'),
  t('descrizione_breve'),
  t('anno_inizio'),
  t('anno_fine'),
  t('in_corso'),
  t('direzione_lavori'),
  t('progettazione_preliminare'),
  t('progettazione_definitiva'),
  t('progettazione_esecutiva'),
  t('ia'),
  t('ib'),
  t('ic'),
  t('id'),
  t('ie'),
  t('if'),
  t('ig'),
  t('iiia'),
  t('iiib'),
  t('iiic'),
  t('iva'),
  t('vib'),
  t('ixa'),
  t('ixb'),
  t('ixc'),
  t('sicurezza_coordinamento_progettazione'),
  t('sicurezza_coordinamento_esecuzione'),
  t('Blocco Altri Progetti'),
  t('Other Projects'),
  t('Voci per pagina'),
  t('- Tutto -'),
  t('Slittamento'),
  t('« prima'),
  t('‹ precedente'),
  t('seguente ›'),
  t('ultima »'),
  t('Tutti'),
  t('Altri Progetti'),
  t('Blocco Elenco Progetti con Mappa Grande'),
  t('Projects'),
  t('<a href="/node/[nid]" nid="[nid]" class="map-zoom">zoom in map</a>'),
  t('Elenco Progetti con Mappa'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;