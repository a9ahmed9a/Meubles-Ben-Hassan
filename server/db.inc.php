<?php
$servername = "localhost"; // if MySQL is running on the same server
$username = "root"; // your MySQL username
$password = "root"; // your MySQL password
$dbname = "ichhari-ecom"; // your MySQL database name

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully";
?>
