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
			CREATE
		</h2>
		<form action="create_process.php" method="POST">
			<p><input type="text" name="title" placeholder="title"></p>
			<p><textarea name="content" placeholder="content"></textarea></p>
			<p><input type="submit"></p>
	</div>
	</div>
</body>

</html>