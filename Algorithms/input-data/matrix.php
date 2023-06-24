<?php
$matrix = array(
    array("Nama", "Usia", "Kota"),
    array("fdhli", 21, "jogja"),
    array("kamu", 15, "bantul"),
    array("dia", 35, "bali")
);

$newData = array("Mike", 28, "Bali");

array_push($matrix, $newData);
print_r($matrix);
?>