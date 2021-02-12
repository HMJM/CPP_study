<!DOCTYPE html>
<html>

<head>
	<title>WEB1</title>
	<meta charset="utf-8">
	<link rel="stylesheet" href="style.css">
</head>

<body>
	<h1>
		<p class="title"><a href="main.php?id=WEB">WEB</a></p>
	</h1>
	<div class="menuAndContent">
		<ol>
			<li><a href="main.php?id=HTML">HTML</a></li>
			<li><a href="main.php?id=CSS">CSS</a></li>
			<li><a href="main.php?id=JavaScript">JavaScript</a></li>
		</ol>
		<div class="content">
	<?php
		if (empty($_GET['id']))
			$pageid = "WEB";
		else
			$pageid = $_GET['id'];
	?>
			<h2><?php echo $pageid; ?>이란 무엇인가?</h2>
			<?php
				echo file_get_contents("data/".$pageid.".html");
			?>
			
		</div>
	</div>
</body>

</html>
