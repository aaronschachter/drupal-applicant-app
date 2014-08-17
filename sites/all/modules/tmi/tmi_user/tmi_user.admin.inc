<?php
/**
 * @file
 * Admin config form settings.
 */

/**
 * System settings form for TMI variables.
 */
function tmi_user_admin_config_form($form, &$form_state) {
  $var_name = 'tmi_user_insert_apply_for';
  $form[$var_name] = array(
    '#type' => 'entityreference',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('scholarship'),
    '#title' => t('Select the node which new Users are applying for.'),
    '#default_value' => variable_get($var_name),
    '#description' => t("When a user registers for the site, an Application will be created for this node."),
    '#required' => TRUE,
  );
  $var_name = 'tmi_debug';
  $form[$var_name] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable debug mode.'),
    '#default_value' => variable_get($var_name, FALSE),
    '#description' => t("Logs activity. This should be disabled on production."),
  );
  return system_settings_form($form);
}
