<?php
/**
 * @file
 * tmi_recommend_form.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tmi_recommend_form_node_info() {
  $items = array(
    'recommend_form' => array(
      'name' => t('Recommendation Form'),
      'base' => 'node_content',
      'description' => t('The Recommendation Form sent to a Recommender to submit.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
