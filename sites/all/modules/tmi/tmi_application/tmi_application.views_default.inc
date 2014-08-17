<?php
/**
 * @file
 * tmi_application.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tmi_application_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'applications';
  $view->description = 'Table view of all Applications.';
  $view->tag = 'default';
  $view->base_table = 'tmi_application';
  $view->human_name = 'Applications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Applications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'review applications';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'aid' => 'aid',
    'mail' => 'mail',
    'completed' => 'completed',
    'submitted' => 'submitted',
    'reviewed' => 'reviewed',
    'reviewer_rating' => 'reviewer_rating',
  );
  $handler->display->display_options['style_options']['default'] = 'completed';
  $handler->display->display_options['style_options']['info'] = array(
    'aid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'submitted' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'reviewed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'reviewer_rating' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total Applications';
  /* Relationship: Applications: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'tmi_application';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Applicant';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Applications: Applying for Node nid */
  $handler->display->display_options['relationships']['nid_apply_for']['id'] = 'nid_apply_for';
  $handler->display->display_options['relationships']['nid_apply_for']['table'] = 'tmi_application';
  $handler->display->display_options['relationships']['nid_apply_for']['field'] = 'nid_apply_for';
  $handler->display->display_options['relationships']['nid_apply_for']['required'] = TRUE;
  /* Field: Applications: Application aid */
  $handler->display->display_options['fields']['aid']['id'] = 'aid';
  $handler->display->display_options['fields']['aid']['table'] = 'tmi_application';
  $handler->display->display_options['fields']['aid']['field'] = 'aid';
  $handler->display->display_options['fields']['aid']['label'] = 'Aid';
  $handler->display->display_options['fields']['aid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['aid']['alter']['path'] = 'application/[aid]';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['label'] = 'Applicant Email';
  $handler->display->display_options['fields']['mail']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['path'] = 'application/[aid]';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Applications: Date completed */
  $handler->display->display_options['fields']['completed']['id'] = 'completed';
  $handler->display->display_options['fields']['completed']['table'] = 'tmi_application';
  $handler->display->display_options['fields']['completed']['field'] = 'completed';
  $handler->display->display_options['fields']['completed']['label'] = 'Application Completed';
  $handler->display->display_options['fields']['completed']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['completed']['alter']['path'] = 'application/[aid]';
  $handler->display->display_options['fields']['completed']['date_format'] = 'short';
  $handler->display->display_options['fields']['completed']['second_date_format'] = 'long';
  /* Field: Applications: Rating */
  $handler->display->display_options['fields']['reviewer_rating']['id'] = 'reviewer_rating';
  $handler->display->display_options['fields']['reviewer_rating']['table'] = 'tmi_application';
  $handler->display->display_options['fields']['reviewer_rating']['field'] = 'reviewer_rating';
  /* Field: Applications: Date reviewed */
  $handler->display->display_options['fields']['reviewed']['id'] = 'reviewed';
  $handler->display->display_options['fields']['reviewed']['table'] = 'tmi_application';
  $handler->display->display_options['fields']['reviewed']['field'] = 'reviewed';
  $handler->display->display_options['fields']['reviewed']['label'] = 'Reviewed';
  $handler->display->display_options['fields']['reviewed']['date_format'] = 'short';
  $handler->display->display_options['fields']['reviewed']['second_date_format'] = 'long';
  /* Field: Applications: Reviewer uid */
  $handler->display->display_options['fields']['reviewer_uid']['id'] = 'reviewer_uid';
  $handler->display->display_options['fields']['reviewer_uid']['table'] = 'tmi_application';
  $handler->display->display_options['fields']['reviewer_uid']['field'] = 'reviewer_uid';
  $handler->display->display_options['fields']['reviewer_uid']['label'] = 'Reviewer';
  $handler->display->display_options['fields']['reviewer_uid']['separator'] = '';
  /* Field: Applications: Date submitted */
  $handler->display->display_options['fields']['submitted']['id'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['table'] = 'tmi_application';
  $handler->display->display_options['fields']['submitted']['field'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['label'] = 'Applicant Submitted';
  $handler->display->display_options['fields']['submitted']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['submitted']['alter']['path'] = 'application/[aid]';
  $handler->display->display_options['fields']['submitted']['date_format'] = 'short';
  $handler->display->display_options['fields']['submitted']['second_date_format'] = 'long';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid_apply_for';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Applications: %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'scholarship' => 'scholarship',
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['relationship'] = 'uid';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'Applicant Email';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Applications: Rating */
  $handler->display->display_options['filters']['reviewer_rating']['id'] = 'reviewer_rating';
  $handler->display->display_options['filters']['reviewer_rating']['table'] = 'tmi_application';
  $handler->display->display_options['filters']['reviewer_rating']['field'] = 'reviewer_rating';
  $handler->display->display_options['filters']['reviewer_rating']['exposed'] = TRUE;
  $handler->display->display_options['filters']['reviewer_rating']['expose']['operator_id'] = 'reviewer_rating_op';
  $handler->display->display_options['filters']['reviewer_rating']['expose']['label'] = 'Rating';
  $handler->display->display_options['filters']['reviewer_rating']['expose']['operator'] = 'reviewer_rating_op';
  $handler->display->display_options['filters']['reviewer_rating']['expose']['identifier'] = 'reviewer_rating';
  $handler->display->display_options['filters']['reviewer_rating']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/applications';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Applications';
  $handler->display->display_options['menu']['weight'] = '100';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['applications'] = $view;

  return $export;
}
