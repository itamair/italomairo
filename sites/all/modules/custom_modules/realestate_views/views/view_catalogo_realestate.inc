<?php

$view = new view();
$view->name = 'catalogo_realestate';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'taxonomy_term_data';
$view->human_name = 'Catalogo Real Estate';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Real Estate Catalog';
$handler->display->display_options['css_class'] = 'view-catalogo-realestate';
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
$handler->display->display_options['pager']['options']['items_per_page'] = '2';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'name' => 'name',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Campo: Termine della tassonomia: Nome */
$handler->display->display_options['fields']['name_1']['id'] = 'name_1';
$handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name_1']['field'] = 'name';
$handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
$handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = TRUE;
/* Campo: Termine della tassonomia: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_class'] = 'title';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
/* Campo: Termine della tassonomia: Term edit link */
$handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['label'] = '';
$handler->display->display_options['fields']['edit_term']['element_label_colon'] = FALSE;
/* Campo: Operazioni sui contenuti: Termine della tassonomia */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
  'action::views_bulk_operations_delete_item' => array(
    'selected' => 0,
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
  'action::views_bulk_operations_modify_action' => array(
    'selected' => 0,
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
  'action::system_goto_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::pathauto_taxonomy_term_update_action' => array(
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
/* Campo: Operazioni sui contenuti: Termine della tassonomia */
$handler->display->display_options['fields']['views_bulk_operations_1']['id'] = 'views_bulk_operations_1';
$handler->display->display_options['fields']['views_bulk_operations_1']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['views_bulk_operations_1']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['operations'] = array(
  'action::views_bulk_operations_delete_item' => array(
    'selected' => 0,
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
  'action::views_bulk_operations_modify_action' => array(
    'selected' => 0,
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
  'action::system_goto_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::pathauto_taxonomy_term_update_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
);
$handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['display_result'] = 1;
$handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['merge_single_action'] = 0;
$handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['force_single'] = 0;
/* Criterio di ordinamento: Campo: Ordine di Visualizzazione (field_ordine) */
$handler->display->display_options['sorts']['field_ordine_value']['id'] = 'field_ordine_value';
$handler->display->display_options['sorts']['field_ordine_value']['table'] = 'field_data_field_ordine';
$handler->display->display_options['sorts']['field_ordine_value']['field'] = 'field_ordine_value';
/* Filter criterion: Vocabolario della tassonomia: Nome ad uso interno */
$handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
$handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['value'] = array(
  'riviste_realestate' => 'riviste_realestate',
);

/* Display: Page Gestione Catalogo */
$handler = $view->new_display('page', 'Page Gestione Catalogo', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'administer nodes';
$handler->display->display_options['defaults']['header'] = FALSE;
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'Possibile da qui gestire le caratteristiche generali delle Pubblicazioni del Catalogo Real Estate';
$handler->display->display_options['header']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Termine della tassonomia: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_class'] = 'title';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
/* Campo: Termine della tassonomia: Term edit link */
$handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['label'] = '';
$handler->display->display_options['fields']['edit_term']['element_label_colon'] = FALSE;
$handler->display->display_options['path'] = 'catalogo-real-estate';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Gestione Catalogo Realestate';
$handler->display->display_options['menu']['weight'] = '20';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Blocco Catalogo Riviste */
$handler = $view->new_display('block', 'Blocco Catalogo Riviste', 'block_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['style_options']['columns'] = '2';
$handler->display->display_options['style_options']['summary'] = 'Riviste RealEstate';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'entity';
$handler->display->display_options['row_options']['view_mode'] = 'ultima_copertina';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Termine della tassonomia: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_class'] = 'title';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
/* Campo: Termine della tassonomia: Term edit link */
$handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['label'] = '';
$handler->display->display_options['fields']['edit_term']['element_label_colon'] = FALSE;
$handler->display->display_options['block_description'] = 'Catalogo Realestate';

/* Display: Blocco Ultime Riviste Slideshow */
$handler = $view->new_display('block', 'Blocco Ultime Riviste Slideshow', 'block_2');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'view-catalogo-realestate-slideshow';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
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
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
$handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
$handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
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
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'entity';
$handler->display->display_options['row_options']['view_mode'] = 'ultima_rvista';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Termine della tassonomia: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_class'] = 'title';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;

/* Display: Page Gestione Sezioni News */
$handler = $view->new_display('page', 'Page Gestione Sezioni News', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Sezioni Notizie Real Estate';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'administer nodes';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'name_1' => 'name_1',
  'name' => 'name',
  'edit_term' => 'edit_term',
  'views_bulk_operations' => 'views_bulk_operations',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'name_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
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
  'edit_term' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'views_bulk_operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'Possibile da qui gestire le Sezioni delle Notizie di Real Estate';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Intestazione: Globale: Text area */
$handler->display->display_options['header']['area_1']['id'] = 'area_1';
$handler->display->display_options['header']['area_1']['table'] = 'views';
$handler->display->display_options['header']['area_1']['field'] = 'area';
$handler->display->display_options['header']['area_1']['content'] = '<a href="/admin/structure/taxonomy/section/add">Aggiungi un termine nelle Sezioni</a>';
$handler->display->display_options['header']['area_1']['format'] = 'full_html';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relazione: Termine della tassonomia: Termine padre */
$handler->display->display_options['relationships']['parent']['id'] = 'parent';
$handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
$handler->display->display_options['relationships']['parent']['field'] = 'parent';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Operazioni sui contenuti: Termine della tassonomia */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Taxonomy term';
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
  'action::views_bulk_operations_delete_item' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::system_message_action' => array(
    'selected' => 0,
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
  'action::views_bulk_operations_modify_action' => array(
    'selected' => 0,
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
  'action::views_bulk_operations_argument_selector_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'url' => '',
    ),
  ),
  'action::system_goto_action' => array(
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
  'action::pathauto_taxonomy_term_update_action' => array(
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
/* Campo: Termine della tassonomia: Nome */
$handler->display->display_options['fields']['name_1']['id'] = 'name_1';
$handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name_1']['field'] = 'name';
$handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
$handler->display->display_options['fields']['name_1']['label'] = 'Termine Padre';
$handler->display->display_options['fields']['name_1']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['name_1']['alter']['text'] = '<b>[name_1]</b> ->';
/* Campo: Termine della tassonomia: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_class'] = 'title';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
/* Campo: Termine della tassonomia: Term edit link */
$handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['label'] = '';
$handler->display->display_options['fields']['edit_term']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Criterio di ordinamento: Termine della tassonomia: Nome */
$handler->display->display_options['sorts']['name']['id'] = 'name';
$handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['sorts']['name']['field'] = 'name';
$handler->display->display_options['sorts']['name']['relationship'] = 'parent';
/* Criterio di ordinamento: Campo: Ordine di Visualizzazione (field_ordine) */
$handler->display->display_options['sorts']['field_ordine_value']['id'] = 'field_ordine_value';
$handler->display->display_options['sorts']['field_ordine_value']['table'] = 'field_data_field_ordine';
$handler->display->display_options['sorts']['field_ordine_value']['field'] = 'field_ordine_value';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Vocabolario della tassonomia: Nome ad uso interno */
$handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
$handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['value'] = array(
  'section' => 'section',
);
$handler->display->display_options['path'] = 'sezioni-real-estate';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Gestione Sezioni News';
$handler->display->display_options['menu']['weight'] = '30';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Blocco Ultime Riviste */
$handler = $view->new_display('block', 'Blocco Ultime Riviste', 'block_3');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'view-ultime-riviste-realestate';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['style_options']['columns'] = '2';
$handler->display->display_options['style_options']['summary'] = 'Riviste RealEstate';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'entity';
$handler->display->display_options['row_options']['view_mode'] = 'ultima_rivista_blocco';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Campo: Termine della tassonomia: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_class'] = 'title';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
/* Campo: Termine della tassonomia: Term edit link */
$handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
$handler->display->display_options['fields']['edit_term']['label'] = '';
$handler->display->display_options['fields']['edit_term']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'AND',
  2 => 'OR',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Vocabolario della tassonomia: Nome ad uso interno */
$handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
$handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['value'] = array(
  'riviste_realestate' => 'riviste_realestate',
);
$handler->display->display_options['filters']['machine_name']['group'] = 1;
/* Filter criterion: Termine della tassonomia: ID Termine */
$handler->display->display_options['filters']['tid_raw']['id'] = 'tid_raw';
$handler->display->display_options['filters']['tid_raw']['table'] = 'taxonomy_term_data';
$handler->display->display_options['filters']['tid_raw']['field'] = 'tid_raw';
$handler->display->display_options['filters']['tid_raw']['value']['value'] = '54';
$handler->display->display_options['filters']['tid_raw']['group'] = 2;
/* Filter criterion: Termine della tassonomia: ID Termine */
$handler->display->display_options['filters']['tid_raw_1']['id'] = 'tid_raw_1';
$handler->display->display_options['filters']['tid_raw_1']['table'] = 'taxonomy_term_data';
$handler->display->display_options['filters']['tid_raw_1']['field'] = 'tid_raw';
$handler->display->display_options['filters']['tid_raw_1']['value']['value'] = '55';
$handler->display->display_options['filters']['tid_raw_1']['group'] = 2;
$handler->display->display_options['block_description'] = 'Blocco Ultime Riviste';
$translatables['catalogo_realestate'] = array(
  t('Master'),
  t('Real Estate Catalog'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('Nome'),
  t('Termine della tassonomia'),
  t('Page Gestione Catalogo'),
  t('Possibile da qui gestire le caratteristiche generali delle Pubblicazioni del Catalogo Real Estate'),
  t('Blocco Catalogo Riviste'),
  t('Catalogo Realestate'),
  t('Blocco Ultime Riviste Slideshow'),
  t('Page Gestione Sezioni News'),
  t('Sezioni Notizie Real Estate'),
  t('Possibile da qui gestire le Sezioni delle Notizie di Real Estate'),
  t('<a href="/admin/structure/taxonomy/section/add">Aggiungi un termine nelle Sezioni</a>'),
  t('Genitore'),
  t('Taxonomy term'),
  t('Termine Padre'),
  t('<b>[name_1]</b> ->'),
  t('Blocco Ultime Riviste'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;