<?php
include 'db.php';

if (isset($_GET['search'])) {
    $search = $_GET['search'];
    $ada = false;
    $indeks = 0;

    for($i = 0; $i < count($gudang); $i++){
        if($gudang[$i]['id'] == $search){
                $hasilPencarian[$indeks]['id'] = $gudang[$i]['id'];
                $hasilPencarian[$indeks]['nama'] = $gudang[$i]['nama'];
                $hasilPencarian[$indeks]['harga'] = $gudang[$i]['harga'];
                $hasilPencarian[$indeks]['stok'] = $gudang[$i]['stok'];
                $indeks++;
                $ada = true;
        }
    }

    if ($ada) {
        echo "<table style='width:100%'>";
        echo "<tr>";
        echo "<th style='width:4%'>" . "ID" . "</td>";
        echo "<th>" . "Nama" . "</td>";
        echo "<th>" . "Harga" . "</td>";
        echo "<th style='width:6%'>" . "Stok" . "</td>";
        for($i = 0; $i < count($hasilPencarian); $i++){
            echo "<tr>";
            echo "<td>" . $hasilPencarian[$i]['id'] . "</td>";
            echo "<td>" . $hasilPencarian[$i]['nama'] . "</td>";
            echo "<td>" . $hasilPencarian[$i]['harga'] . "</td>";
            echo "<td>" . $hasilPencarian[$i]['stok'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
    } else {
        echo "ID Tidak Ditemukan ditemukan";
    }

    
}
?>