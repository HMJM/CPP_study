<?php
require("lib/print.php");
require("lib/id.php");

define("EMPTY_INPUT", 0);
define("DUPLICATE_INPUT", -1);
define("FILEPATH_NOT_ALLOWED", -2);
define("FILEEXTENSION_NOT_ALLOWED", -2);

$pageid = get_page_id();

function is_valid_title()
{
	$dir = "data";
	$id = post_id("title");
	if (strlen($id) == 0)
		return (EMPTY_INPUT);
	if ($id != basename($id))
		return (FILEPATH_NOT_ALLOWED);
	if (count(explode(".", $id)) > 1)
		return (FILEEXTENSION_NOT_ALLOWED);
	$arr = scandir($dir);
	foreach ($arr as $val) {
		$split = explode(".", $val);
		if (!strcasecmp($split[0], $id))
			return ($val);
	}
	return (1);
}
?>
<!DOCTYPE html>
<html>

<head>
	<title>Submitted</title>
	<meta charset="utf-8">
	<link rel="stylesheet" href="style.css">

</head>

<body>
	<? require("view/top.php"); ?>
	<div class="content">
		<h3>
			<?php
			$validity = is_valid_title();
			if ($validity > 0) {
				unlink("data/" . $validity);
				header("Location: main.php");
			} else
				echo "Error";
			?>
		</h3>
		<p>
			<?php
			if ($validity == EMPTY_INPUT)
				echo "Title is empty";
			else if ($validity == FILEPATH_NOT_ALLOWED)
				echo "Title including filepath is not allowed";
			else if ($validity == FILEEXTENSION_NOT_ALLOWED)
				echo "Title including file extension is not allowed";
			?>
		</p>
	</div>
	</div>
</body>