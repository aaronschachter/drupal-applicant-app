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
   * Sets the application's sid_webform to given webform submission $sid.
   */
  public function submitted($sid) {
    $this->sid_webform = $sid;
    $this->submitted = REQUEST_TIME;
    $this->save();
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
