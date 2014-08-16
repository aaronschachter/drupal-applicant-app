<div style="border-bottom: 1px solid #ccc;">
  <p><strong><?php print $recommendation->email; ?></strong></p>
  <p><?php print $recommendation->rid; ?></p>
  <p>Requested <?php print format_date($recommendation->created, 'short'); ?></p>

  <?php if ($recommendation->submitted): ?>
    <div style="background: #eee;padding:20px">
      <p>Submitted <?php print format_date($recommendation->submitted, 'short'); ?></p>
      <?php print $recommendation->submission; ?>
    </div>
  <?php endif; ?>
</div>
