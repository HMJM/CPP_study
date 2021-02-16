<!DOCTYPE html>
<html>

<head>
	<title>WEB2</title>
	<meta charset="utf-8">
	<link rel="stylesheet" href="style.css">
	<?php
	function print_list()
	{
		$dataDir = 'data/';
		$arr = scandir($dataDir);
		foreach ($arr as $value) {
			if (($value == ".") || ($value == ".."))
				continue;
			$split = explode(".", $value);
			if ($split[0] == "WEB")
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
		if ($id == "create")
			echo file_get_contents("create.html");
		else
			echo file_get_contents("data/" . $id . ".html");
		echo "\n";
	}
	$pageid = get_page_id();
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
			<h2>
				<?php
				print_title($pageid);
				?>
			</h2>
			<?php
			print_content($pageid);
			?>
		</div>
	</div>
</body>

</html>