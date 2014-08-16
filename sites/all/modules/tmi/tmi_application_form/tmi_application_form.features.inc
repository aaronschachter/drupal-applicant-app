<?php
/**
 * @file
 * tmi_application_form.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tmi_application_form_node_info() {
  $items = array(
    'application_form' => array(
      'name' => t('Application Form'),
      'base' => 'node_content',
      'description' => t('The Webform the Applicant must submit to complete their Application.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
