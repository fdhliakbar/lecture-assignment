<?php
include 'db.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Retrieve the user input from the form
    $input_name = $_POST["name-product"];
    $input_id = $_POST["id-product"];
    $input_price = $_POST["price-product"];
    $input_stock = $_POST["stock-product"];

    $i = count($gudang);
    
    $gudang[$i]['nama'] = $input_name;
    $gudang[$i]['id'] = $input_id;
    $gudang[$i]['harga'] = $input_price;
    $gudang[$i]['stok'] = $input_stock;

    // Display the 2D array
    echo "<pre>";
    print_r($gudang);
    echo "</pre>";
}
?>