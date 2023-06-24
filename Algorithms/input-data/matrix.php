<?php
// Step 1: Tentukan array 2 dimensi yang ingin ditambahkan data baru
$myArray = array(
    array("Nama", "Usia", "Kota"),
    array("John", 25, "Jakarta"),
    array("Jane", 30, "Surabaya"),
    array("Bob", 35, "Bandung")
);

// Step 2: Buat variabel untuk menyimpan data baru yang ingin ditambahkan ke dalam array
$newData = array("Mike", 28, "Bali");

// Step 3: Tambahkan data baru ke dalam variabel menggunakan sintaksis array_push()
array_push($myArray, $newData);

// Step 4: Tambahkan variabel dengan data baru ke dalam array menggunakan sintaksis array_push() lagi
print_r($myArray);
?>