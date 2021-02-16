<?php
require_once("lib/print.php");
require_once("lib/id.php");
?>

<!DOCTYPE html>
<html>

<head>
	<title>WEB2</title>
	<meta charset="utf-8">
	<link rel="stylesheet" href="style.css">
</head>

<body>
	<? require("view/top.php"); ?>
	<div class="content">
		<h2>
			<?php
			print_title($pageid);
			?>
		</h2>
		<form action="modify_process.php" method="POST">
			<input type="hidden" name="old_title" value=<?= get_page_id() ?>>
			<p><input type="text" name="title" placeholder="title" value=<? print_title($pageid); ?>></p>
			<p><textarea name="content" placeholder="content"><? print_content($pageid); ?></textarea></p>
			<p><input type="submit"></p>
		</form>
	</div>
	</div>
</body>

</html>