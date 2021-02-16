<?php
require_once("lib/print.php");
require_once("lib/id.php");
$pageid = get_page_id();
?>
<h1>
	<p class="title">
		<a href="main.php?id=WEB">WEB</a>
	</p>
</h1>
<div class="menuAndContent">
	<ol>
		<?php
		print_list();
		?>
		<p><a href="create.php">CREATE</a></p>
		<?php if ($pageid != NULL && $pageid != "WEB") { ?>
		<p><a href="modify.php?id=<?= get_page_id(); ?>">MODIFY</a></p>
		<p><a href="delete.php?id=<?= get_page_id(); ?>">DELETE</a></p>
		<?php } ?>
	</ol>