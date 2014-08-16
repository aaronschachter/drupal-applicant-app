<div style="border-bottom: 1px solid #ccc;padding-top:20px;">
  <ul>
    <li><strong>Email: <?php print $recommendation->email; ?></strong></li>
  </ul>
  <p>Requested: <?php print format_date($recommendation->created, 'short'); ?></p>
  <?php if ($recommendation->submitted): ?>
    <p>Submitted: <?php print format_date($recommendation->submitted, 'short'); ?></p>
    <?php print $recommendation->submission; ?>
  <?php endif; ?>
</div>
