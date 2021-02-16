<!DOCTYPE html>
<html>

<head>
	<title>Submitted</title>
	<meta charset="utf-8">
	<link rel="stylesheet" href="style.css">
	<?php
	define("EMPTYINPUT", 0);
	define("DUPLICATEINPUT", -1);

	function print_list()
	{
		$dataDir = 'data/';
		$arr = scandir($dataDir);
		foreach ($arr as $value) {
			if (($value == ".") || ($value == ".."))
				continue;
			$split = explode(".", $value);
			if ($split[0] == "WEB" || $split[0] == "create")
				continue;
			echo "<li><a href=\"main.php?id=$split[0]\">$split[0]</a></li>";
			echo "\n";
		}
	}
	function get_page_id()
	{
		if (isset($_GET['id']))
			$pageid = $_GET['id'];
		else
			$pageid = "WEB";
		return $pageid;
	}
	function print_title($id)
	{
		echo $id;
		echo "\n";
	}
	function print_content($id)
	{
		echo file_get_contents("data/" . $id . ".html");
		echo "\n";
	}
	$pageid = get_page_id();
	function post_id($name)
	{
		$id = $_POST[$name];
		if (!isset($id))
			$id = NULL;
		return ($id);
	}
	function is_valid_title()
	{
		$dir = "data";
		$id = post_id("title");
		if (strlen($id) == 0)
			return (EMPTYINPUT);
		$arr = scandir($dir);
		foreach ($arr as $val) {
			$split = explode(".", $val);
			if (!strcasecmp($split[0], $id))
				return (DUPLICATEINPUT);
		}
		return (1);
	}
	?>
</head>

<body>
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
			<p><a href="main.php?id=create">CREATE</a>
		</ol>
		<div class="content">
			<h3>
				<?php
				$validity = is_valid_title();
				if ($validity == 1) {
					echo "Successfully submitted";
					file_put_contents(
						"data/" . htmlspecialchars(post_id("title")) . ".html",
						htmlspecialchars(post_id("content"))
					);
					header("Location: main.php?id=" . post_id("title"));
				} else
					echo "Error";
				?>
			</h3>
			<?php
			if ($validity == EMPTYINPUT)
				echo "Title is empty";
			else if ($validity == DUPLICATEINPUT)
				echo "Title is duplicated with existing document";
			?>
		</div>
	</div>
</body>