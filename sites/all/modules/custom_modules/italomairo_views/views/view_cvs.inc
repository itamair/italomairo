<?php

$view = new view();
$view->name = 'cvs';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'CVs (in code)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Download my Cvs';
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
$handler->display->display_options['row_plugin'] = 'fields';
/* Campo: Contenuto: Titolo */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Campo: Contenuto: CV */
$handler->display->display_options['fields']['field_cv']['id'] = 'field_cv';
$handler->display->display_options['fields']['field_cv']['table'] = 'field_data_field_cv';
$handler->display->display_options['fields']['field_cv']['field'] = 'field_cv';
$handler->display->display_options['fields']['field_cv']['label'] = '';
$handler->display->display_options['fields']['field_cv']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_cv']['alter']['text'] = '[field_cv-display]';
$handler->display->display_options['fields']['field_cv']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_cv']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_cv']['type'] = 'file_force_file_default';
/* Campo: Contenuto: Lingua CV */
$handler->display->display_options['fields']['field_lingua_cv']['id'] = 'field_lingua_cv';
$handler->display->display_options['fields']['field_lingua_cv']['table'] = 'field_data_field_lingua_cv';
$handler->display->display_options['fields']['field_lingua_cv']['field'] = 'field_lingua_cv';
$handler->display->display_options['fields']['field_lingua_cv']['label'] = '';
$handler->display->display_options['fields']['field_lingua_cv']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_lingua_cv']['element_type'] = 'strong';
$handler->display->display_options['fields']['field_lingua_cv']['element_label_colon'] = FALSE;
/* Campo: Globale: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = '';
$handler->display->display_options['fields']['php']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['text'] = '<span class="file">[php] <div class="file_text_url">[field_cv]</div></span>';
$handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php
$file = $data->field_field_cv[0][\'rendered\'][\'#file\'];
$url = (module_exists(\'file_force\')) ? file_force_create_url($file->uri) : file_create_url($file->uri);
$icon_directory = drupal_get_path(\'module\', \'italomairo_views\') . \'/images\';
$mime = check_plain($file->filemime);
$icon_url = file_icon_url($file, $icon_directory);
$value_php = \'<div class="file-icon-big-wrapper"><a href="\'.$url.\'" ><img class="file-icon-big" alt="" title="\' . $mime . \'" src="\' . $icon_url . \'" width="50px" /></a></div>\';
print $value_php;
?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
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
  'curriculum_vitae' => 'curriculum_vitae',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['block_description'] = 'CVS Block';
$translatables['cvs'] = array(
  t('Master'),
  t('Download my Cvs'),
  t('leggi tutto'),
  t('Applica'),
  t('Ripristina'),
  t('Ordina per'),
  t('Asc'),
  t('Disc'),
  t('[field_cv-display]'),
  t('<span class="file">[php] <div class="file_text_url">[field_cv]</div></span>'),
  t('Block'),
  t('CVS Block'),
);


/* Define this new view from code in views list */
$views[$view->name] = $view;