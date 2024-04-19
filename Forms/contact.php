<?php
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $name = $_POST["nom"];
    $adress = $_POST["adrss"];
    $prod = $_POST["produit"];
    $tele = $_POST["tel"];
    $qte = $_POST["qte"];


    echo "hello";

    echo $name;
    echo $adress;
    echo $prod;
    echo $tele;
    echo $qte;

    // Customize the following variables with your email details
    // $receiver_email = "mman7895@gmail.com";
    // $subject = "New command";
    // $body = "Name: $name\nEmail: $email\nMessage: $message";

    // if (mail($receiver_email, $subject, $body)) {
        header("location:../thankyou.html");
    // } else {
    //     echo "Failed to submit the form. Please try again.";
    // }
}
?>
