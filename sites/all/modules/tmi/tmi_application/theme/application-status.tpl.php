<h2>Your application has been <?php print $application->status; ?>.</h2>

<?php if ($recommendations): ?>
  <h2>Recommendations</h2>
  <?php print $recommendations; ?>
<?php endif; ?>

<h2>Request Recommendation</h2>
<?php print render($request_form); ?>

<hr />
<?php print $application->view(); ?>
