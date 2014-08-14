<?php
/**
 * @file
 * tmi_scholarship.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tmi_scholarship_node_info() {
  $items = array(
    'scholarship' => array(
      'name' => t('Scholarship'),
      'base' => 'node_content',
      'description' => t('A Scholarship which Applicants can apply for.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
