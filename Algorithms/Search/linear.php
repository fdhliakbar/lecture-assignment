<?php
// Menerima input keyword
$keyword = $_POST['keyword'];

// Sanitasi keyword
$keyword = htmlspecialchars($keyword);

// Data yang akan dicari
$data = array(
    array(
        'id' => 1,
        'judul' => 'Lorem Ipsum Dolor Sit Amet',
        'isi' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit.'
    ),
    array(
        'id' => 2,
        'judul' => 'Sed Do Eiusmod Tempor Incididunt',
        'isi' => 'Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'
    ),
    array(
        'id' => 3,
        'judul' => 'Ut Enim Ad Minim Veniam',
        'isi' => 'Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.'
    )
);

// Array untuk menampung hasil pencarian
$hasil = array();

// Perulangan untuk mencari data
foreach ($data as $item) {
    if (stristr($item['judul'], $keyword) || stristr($item['isi'], $keyword)) {
        $hasil[] = $item;
    }
}

// Looping untuk menampilkan hasil
foreach ($hasil as $item) {
    echo "ID: ".$item['id']."<br>";
    echo "Judul: ".$item['judul']."<br>";
    echo "Isi: ".$item['isi']."<br><br>";
}
?>