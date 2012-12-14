<?php

$view = new view();
$view->name = 'contatti_riviste_realestate';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'taxonomy_term_data';
$view->human_name = 'Contatti Riviste Realestate (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Contatti Riviste Realestate';
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
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'name',
    'rendered' => 1,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['style_options']['row_class'] = 'rivista';
$handler->display->display_options['row_plugin'] = 'fields';
/* Campo: Termine della tassonomia: Nome */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['exclude'] = TRUE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
/* Campo: Termine della tassonomia: Contatti */
$handler->display->display_options['fields']['field_contatti']['id'] = 'field_contatti';
$handler->display->display_options['fields']['field_contatti']['table'] = 'field_data_field_contatti';
$handler->display->display_options['fields']['field_contatti']['field'] = 'field_contatti';
$handler->display->display_options['fields']['field_contatti']['label'] = '';
$handler->display->display_options['fields']['field_contatti']['element_label_colon'] = FALSE;
/* Criterio di ordinamento: Campo: Ordine di Visualizzazione (field_ordine) */
$handler->display->display_options['sorts']['field_ordine_value']['id'] = 'field_ordine_value';
$handler->display->display_options['sorts']['field_ordine_value']['table'] = 'field_data_field_ordine';
$handler->display->display_options['sorts']['field_ordine_value']['field'] = 'field_ordine_value';
/* Criterio di ordinamento: Termine della tassonomia: Nome */
$handler->display->display_options['sorts']['name']['id'] = 'name';
$handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['sorts']['name']['field'] = 'name';
/* Filter criterion: Vocabolario della tassonomia: Nome ad uso interno */
$handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
$handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['value'] = array(
  'riviste_realestate' => 'riviste_realestate',
);

/* Display: Block Contatti Riviste Realestate */
$handler = $view->new_display('block', 'Block Contatti Riviste Realestate', 'block');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$translatables['contatti_riviste_realestate'] = array(
  t('Master'),
  t('Contatti Riviste Realestate'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('Block Contatti Riviste Realestate'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;