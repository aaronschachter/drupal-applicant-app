<?php
/**
 * @file
 * tmi_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tmi_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'reviewer' => 'reviewer',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'reviewer' => 'reviewer',
    ),
    'module' => 'system',
  );


  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'reviewer' => 'reviewer',
    ),
    'module' => 'system',
  );

  return $permissions;
}
