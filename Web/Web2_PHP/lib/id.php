<?php
function get_page_id()
{
	if (!isset($_GET['id']))
		$pageid = "WEB";
	else {
		$tmp = $_GET['id'];
		if ($tmp == basename($tmp))
			$pageid = $_GET['id'];
		else
			$pageid = NULL;
	}
	return $pageid;
}
function post_id($name)
{
	if (!isset($_POST[$name]))
		return (NULL);
	$id = $_POST[$name];
	return ($id);
}