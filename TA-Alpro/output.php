<?php
include 'db.php';
?>

<html>

<head>
    <link rel="stylesheet" href="style.css">
</head>

<body>
    <table style="width:100%">
        <?php
        echo "<tr>";
        echo "<th style='width:4%'>" . "ID" . "</td>";
        echo "<th>" . "Nama" . "</td>";
        echo "<th>" . "Harga" . "</td>";
        echo "<th style='width:6%'>" . "Stok" . "</td>";
        for($i = 0; $i < count($gudang); $i++){
            echo "<tr>";
            echo "<td>" . $gudang[$i]['id'] . "</td>";
            echo "<td>" . $gudang[$i]['nama'] . "</td>";
            echo "<td>" . $gudang[$i]['harga'] . "</td>";
            echo "<td>" . $gudang[$i]['stok'] . "</td>";
            echo "</tr>";
        }
    ?>
    </table>
</body>

</html>