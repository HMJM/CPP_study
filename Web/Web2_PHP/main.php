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
	<?php $pageid = get_page_id(); ?>
</head>

<body>
	<? require("view/top.php"); ?>
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