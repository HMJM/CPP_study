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
			DELETE PAGE: <?= $pageid ?>
		</h2>
		<p>Page will be deleted. OK?</p>
		<form action="delete_process.php" method="POST">
			<p><input type="hidden" name="title" value=<?= $pageid ?>></p>
			<p><input type="submit" value="Confirm"></p>
		</form>
	</div>
	</div>
</body>

</html>