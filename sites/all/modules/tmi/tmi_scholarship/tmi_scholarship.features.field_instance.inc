<?php
/**
 * @file
 * tmi_scholarship.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function tmi_scholarship_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-scholarship-field_date_application'
  $field_instances['node-scholarship-field_date_application'] = array(
    'bundle' => 'scholarship',
    'deleted' => 0,
    'description' => 'Set when the Scholarship Application process begins and ends.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_date_application',
    'label' => 'Application Dates',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'node-scholarship-field_webform_applicant'
  $field_instances['node-scholarship-field_webform_applicant'] = array(
    'bundle' => 'scholarship',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the webform which should be filled out by the Applicant.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_webform_applicant',
    'label' => 'Applicant Webform',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => -2,
    ),
  );

  // Exported field_instance: 'node-scholarship-field_webform_recommend'
  $field_instances['node-scholarship-field_webform_recommend'] = array(
    'bundle' => 'scholarship',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the webform to use as an Optional Recommendation, if applicable.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_webform_recommend',
    'label' => 'Optional Recommendation Webform',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-scholarship-field_webform_recommend_required'
  $field_instances['node-scholarship-field_webform_recommend_required'] = array(
    'bundle' => 'scholarship',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the webform to be used for the Required Recommendation.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_webform_recommend_required',
    'label' => 'Required Recommendation Webform',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => -1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Applicant Webform');
  t('Application Dates');
  t('Optional Recommendation Webform');
  t('Required Recommendation Webform');
  t('Select the webform to be used for the Required Recommendation.');
  t('Select the webform to use as an Optional Recommendation, if applicable.');
  t('Select the webform which should be filled out by the Applicant.');
  t('Set when the Scholarship Application process begins and ends.');

  return $field_instances;
}
