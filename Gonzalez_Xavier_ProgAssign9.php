
<html>
	<head>
		<title> Applied Programming Languages: Assignment 9 - PHP Basics
	</head>
	<body>
		<?php
			/*
			Xavier Gonzalez
			PHP Basics
			Applied Programming Languages
			4/28/2020
			*/
			
			// Intialized Varible as a base
			$num = 0;
			// foreach is used to go through numbers consecutively
			foreach (range(3, 5) as $number) {
				$num += $number; // adds number value to num value
			}
			echo $num // echos num value
			?>
	</body>
</html>