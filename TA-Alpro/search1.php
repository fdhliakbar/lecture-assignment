<!DOCTYPE html>
<html>

<head>
    <link href="https://fonts.googleapis.com/css?family=Caesar+Dressing" rel="stylesheet">
    <link rel="stylesheet" href="style.css">
    <style>
    .header h1 {
        font-family: 'Caesar Dressing';
        letter-spacing: 5px;
    }
    </style>
</head>

<body>

    <div class="header">
        <a href="index.php">
            <h1>MENG-ALPRO</h1>
        </a>
        <p>Sistem Pengelolaan Gudang Demi Menyelesaikan Tugas UwU</p>
    </div>

    <div class="topnav">
        <a href="#">Input Data</a>
        </a>
    </div>

    <div class="row">
        <div class="leftcolumn">
            <div class="card">
                <h2>Data Barang</h2>
                <?php
            include 'search.php';
        ?>
            </div>
        </div>
        <div class="rightcolumn">
            <div class="card">
                <h2>Filter Data</h2>
                <a href="#">Urutkan ID Kecil ke Besar</a><br><br>
                <a href="#">Urutkan ID Besar ke Kecil</a><br><br>
                <form action="search1.php" method="get">
                    <input type="text" name="search" placeholder="Cari ID Barang">
                    <input type="submit" value="Cari">
                </form>
            </div>
        </div>
    </div>

    <div class="footer">
        <h2>@Copyright <b>Meng-Alpro 2023</b></h2>
    </div>

</body>

</html>