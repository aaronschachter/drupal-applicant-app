<?php
/**
 * @file
 * tmi_recommend_form.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tmi_recommend_form_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tmi_recommend_form_node_info() {
  $items = array(
    'recommend_form' => array(
      'name' => t('Recommendation Form'),
      'base' => 'node_content',
      'description' => t('The Webform a Recommender must submit in order to complete a Recommendation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
