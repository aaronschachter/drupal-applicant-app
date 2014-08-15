<div>
  <p><strong>Email: <?php print $account->mail; ?></strong></p>

  <p>Status: <?php print ucfirst($application->status); ?></p>

  <p>Created: <?php print format_date($application->created, 'short'); ?></p>

  <?php if ($application->submitted): ?>
  <p>Submitted: <?php print format_date($application->submitted, 'short'); ?></p>
  <?php endif; ?>

  <?php if ($application->completed): ?>
  <p>Completed: <?php print format_date($application->completed, 'short'); ?></p>
  <?php endif; ?>

  <?php print $application->submission; ?>
</div>

<?php /**** Reviewer details ****/ ?>

<h2>Recommendations</h2>
<?php if (isset($application->recommendations)): ?>
  <?php foreach ($application->recommendations as $rec): ?>
    <div><?php print $rec; ?></div>
  <?php endforeach; ?>
<?php else: ?>
  <p>No recommendations have been requested.</p>
<?php endif; ?>

<h2>Review</h2>
<?php // print render($review_form); ?>
