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
    }
    parent::save($entity, $transaction);
    if ($op == 'insert') {
      // @todo: Send MBP request with Recommendation details.
    }
  }
}
