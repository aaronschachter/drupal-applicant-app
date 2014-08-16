<?php
/**
 * @file
 * tmi_application.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tmi_application_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'review applications'.
  $permissions['review applications'] = array(
    'name' => 'review applications',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'reviewer' => 'reviewer',
    ),
    'module' => 'tmi_application',
  );

  return $permissions;
}
