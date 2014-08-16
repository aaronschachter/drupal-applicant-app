<?php

/**
 * @file
 * Provides classes for the Recommendation Entity.
 */

/**
 * Our Recommendation entity class.
 */
class RecommendationEntity extends Entity {

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'recommendation/' . $this->identifier());
  }

  /**
   * Override construct to set status property.
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, $entityType);
    if (isset($this->rid)) {
      $this->form_url = $this->get_form_url();
    }
  }

  /**
   * Sets the recommendation's sid_webform to given webform submission $sid.
   */
  public function submitted($sid) {
    $this->submitted = REQUEST_TIME;
    $this->sid_webform = $sid;
    if (TMI_DEBUG) {
      watchdog('tmi_recommendation', '$this->submitted: ' . json_encode($this));
    }
    try {
      $this->save();
    }
    catch (Exception $e) {
      watchdog('tmi_recommendation', $e, NULL, 'error');
    }
    
    // If this was a required recommendation:
    if ($this->required) {
      // Set the application as completed.
      $application = entity_load_single('application', $this->aid);
      if (TMI_DEBUG) {
        watchdog('tmi_recommendation', 'Application: ' . json_encode($application));
      }
      $application->completed();
    }
    // @todo: Send MBP requests: 1) To Recommender and 2) To Applicant.
  }

  /**
   * Loads the Recommendation webform submission.
   */
  public function get_submission($rendered = TRUE) {
    if (!$this->sid) {
      return NULL;
    }
    $nid = $this->nid_recommend_form;
    return tmi_webform_get_submission_html($nid, $this->sid);
  }
  
  public function get_form_url() {
    $recommend_form_path = 'node/' . $this->nid_recommend_form;
    return $recommend_form_path . '?rid=' . $this->rid;
  }
  /**
   * Returns rendered entity HTML.
   */
  public function view() {
    // Load the rendered webform submission.
    $this->submission = $this->get_submission();
    return theme('recommendation', array(
      'recommendation' => $this,
    ));
  }
}

/**
 * Our custom controller for the Recommendation Entity type.
 */
class RecommendationEntityController extends EntityAPIController {

  /**
   * Overrides save() method.
   *
   * Populates created and updated automatically.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $op = NULL;
    if (isset($entity->is_new)) {
      $op = 'insert';
      $entity->created = REQUEST_TIME;
    }
    parent::save($entity, $transaction);
    if ($op == 'insert') {
      // @todo: Send email with link to form_url to the Recommender.
      $form_url = $this->get_form_url();
      if (TMI_DEBUG) {
        watchdog('tmi_recommendation', 'form_url: ' . $form_url);
      }
    }
  }
}
