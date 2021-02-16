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