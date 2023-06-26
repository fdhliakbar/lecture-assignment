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
        function swap(&$a, &$b){
            $temp = $b;
            $b = $a;
            $a = $temp;
        }

        // sorting
        $n = count($gudang);
        for ($i = 0; $i < $n-1; $i++) {
            for ($j = 0; $j < $n-$i-1; $j++) {
                if ($gudang[$j] > $gudang[$j+1]) {
                    swap($gudang[$j]['id'], $gudang[$j+1]['id']);
                    swap($gudang[$j]['nama'], $gudang[$j+1]['nama']);
                    swap($gudang[$j]['harga'], $gudang[$j+1]['harga']);
                    swap($gudang[$j]['stok'], $gudang[$j+1]['stok']);
                }
            }
        }

        // function test($arr){
        //     $size = count($arr) - 1;
        //     for($i=0;$i<$size;$i++){

        //     }
        // }

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