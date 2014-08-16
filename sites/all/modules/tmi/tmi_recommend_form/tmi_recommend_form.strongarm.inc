<?php
/**
 * @file
 * tmi_recommend_form.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function tmi_recommend_form_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_recommend_form';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_recommend_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_recommend_form';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_recommend_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_recommend_form';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_recommend_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_recommend_form';
  $strongarm->value = '0';
  $export['node_preview_recommend_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_recommend_form';
  $strongarm->value = 0;
  $export['node_submitted_recommend_form'] = $strongarm;

  return $export;
}
