<?php

/**
 * @file
 * Provides classes for the Scholarship Application Entity.
 */

/**
 * Our Scholarship Application entity class.
 */
class ScholarshipApplicationEntity extends Entity {

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'application/' . $this->identifier());
  }
}

/**
 * Our custom controller for the Scholarship Application Entity type.
 */
class ScholarshipApplicationEntityController extends EntityAPIController {

  /**
   * Overrides save() method.
   *
   * Populates created and updated automatically.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);
  }
}
