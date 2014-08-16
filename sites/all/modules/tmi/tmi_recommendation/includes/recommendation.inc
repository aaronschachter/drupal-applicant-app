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
   * Sets the recommendation's sid_webform to given webform submission $sid.
   */
  public function submitted($sid) {
    $time = REQUEST_TIME;
    $this->sid_webform = $sid;
    $this->submitted = $time;
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
    if (!$this->sid_webform) {
      return NULL;
    }
    module_load_include('inc', 'webform', 'includes/webform.submissions');
    $submission = webform_get_submission(TMI_RECOMMEND_FORM_NID, $this->sid_webform);
    if ($rendered) {
      $recommend_form = node_load(TMI_RECOMMEND_FORM_NID);
      return webform_submission_render($recommend_form, $submission, NULL, 'html');
    }
    return $submission;
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
      // @todo: Send MBP request with Recommendation details.
      $form_url = tmi_recommendation_get_recommend_form_url($entity->rid);
      if (TMI_DEBUG) {
        watchdog('tmi_recommendation', 'form_url: ' . $form_url);
      }
    }
  }
}
