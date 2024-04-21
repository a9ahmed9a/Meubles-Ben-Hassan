<?php 
    include 'db.inc.php';
    if(empty($_GET))
        header('location:../index.html');
    
    $product = $_GET['prodName'];
    $client = $_GET['name'];
    $tele = $_GET['tele'];
    $ville = $_GET['ville'];
    $variant = $_GET['prodvar'];

    $sql = "INSERT INTO commandes (product, name, tele, ville, prod ) VALUES ('$product', '$client', '$tele', '$ville', '$variant')";
    $conn->query($sql);

    header('location:../thankyou.html');
?>
