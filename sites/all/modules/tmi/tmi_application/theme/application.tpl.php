<div>
  <p><strong><?php print $account->mail; ?></strong></p>

  <?php if ($is_admin): ?>
  <p>Application (aid: <?php print $application->aid; ?>) for <a href="/node/<?php print $application->nid_apply_for; ?>/applications">Node <?php print $application->nid_apply_for; ?></a> is <?php print $application->status; ?>.</p>
  <?php endif; ?>

  <p>Created <?php print format_date($application->created, 'short'); ?></p>

  <?php if ($application->submitted): ?>
    <div style="background: #eee;padding:20px">
      <p>Submitted <?php print format_date($application->submitted, 'short'); ?></p>
      <?php print $application->submission; ?>
    </div>
  <?php endif; ?>
</div>

<?php if ($is_admin): ?>

  <?php if ($application->submitted): ?>
    <h2>Recommendations</h2>
    <?php if (isset($application->recommendations)): ?>
      <?php foreach ($application->recommendations as $rec): ?>
        <div><?php print $rec; ?></div>
      <?php endforeach; ?>
    <?php else: ?>
      <p>No recommendations have been requested.</p>
    <?php endif; ?>
  <?php endif; ?>

  <?php if ($application->completed): ?>
    <h2>Review</h2>
    <?php // print render($review_form); ?>
  <?php endif; ?>

<?php endif; ?>
