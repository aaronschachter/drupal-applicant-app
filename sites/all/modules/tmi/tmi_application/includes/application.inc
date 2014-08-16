<?php

/**
 * @file
 * Provides classes for the Application Entity.
 */

/**
 * Our Application entity class.
 */
class ApplicationEntity extends Entity {

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'application/' . $this->identifier());
  }

  /**
   * Override construct to set status property.
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, $entityType);
    $this->fids = array();
    $status = 'draft';
    if ($this->completed) {
      $status = 'completed';
    }
    elseif ($this->submitted) {
      $status = 'submitted';
    }
    $this->status = $status;
  }

  /**
   * Sets the application's sid to given webform submission $sid.
   */
  public function submitted($sid) {
    $this->sid = $sid;
    $this->submitted = REQUEST_TIME;
   if (TMI_DEBUG) {
      watchdog('tmi_application', '$this->submitted: ' . json_encode($this));
    }
    $this->save();
  }

  /**
   * Sets the application's completed timestamp.
   */
  public function completed($time = NULL) {
    if (!$time) {
      $time = REQUEST_TIME;
    }
    $this->completed = $time;
    if (TMI_DEBUG) {
      watchdog('tmi_application', '$this->completed: ' . json_encode($this));
    }
    $this->save();
    // @todo: Send email to Applicant informing them Application is completed.
  }

  /**
   * Loads the Application Scholarship webform submission.
   */
  public function get_submission() {
    $nid = $this->nid_application_form;
    return tmi_webform_get_submission_html($nid, $this->sid);
  }

  public function get_recommendations() {
    return db_select("tmi_recommendation", "r")
      ->fields("r")
      ->condition("aid", $this->aid)
      ->execute()
      ->fetchAll();
  }

  /**
   * Returns rendered entity HTML.
   */
  public function view() {
    // Add themed webform submission.
    $this->submission = $this->get_submission();
    $is_admin = FALSE;

    if (user_access('review applications')) {
      $is_admin = TRUE;
      // Add Recommendation views.
      $recommendations = $this->get_recommendations();
      foreach ($recommendations as $rec) {
        $recommendation = entity_load_single('recommendation', $rec->rid);
        $this->recommendations[] = $recommendation->view();
      }
    }

    return theme('application', array(
      // Load Applicant details.
      'account' => user_load($this->uid),
      'application' => $this,
      'is_admin' => $is_admin,
    ));
  }

}

/**
 * Our custom controller for the Scholarship Application Entity type.
 */
class ApplicationEntityController extends EntityAPIController {

  /**
   * Overrides save() method.
   *
   * Populates created and updated automatically.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (isset($entity->is_new)) {
      $entity->created = REQUEST_TIME;
    }
    parent::save($entity, $transaction);
  }
}
