<div style="border-bottom: 1px solid #ccc;">
  <p><strong><?php print $recommendation->email; ?></strong></p>
  <p>Requested <?php print format_date($recommendation->created, 'short'); ?></p>
  <a href="/<?php print $recommendation->form_url; ?>"><?php print $recommendation->form_url; ?></a>

  <?php if ($recommendation->sid): ?>
    <div style="background: #eee;padding:20px">
      <?php print $recommendation->submission; ?>
    </div>
  <?php endif; ?>
</div>
