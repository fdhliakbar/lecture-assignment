<!DOCTYPE html>
<html>

<head>
    <link rel="stylesheet" href="style.css">
    <link href="https://fonts.googleapis.com/css?family=Caesar+Dressing" rel="stylesheet">
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

    <div class="topnav"></div>

    <div class="row">
        <div class="leftcolumn">
            <div class="card">
                <h2>Data Barang</h2>
                <?php
        include 'ascending.php';
      ?>
            </div>
        </div>
        <div class="rightcolumn">
            <div class="card">
                <h2>Fitur</h2>
                <a href="kecil.php">Urutkan ID Kecil ke Besar</a>
                <a href="besar.php">Urutkan ID Besar ke Kecil</a>
                <a href="input.php" style='padding-bottom: 20px'>Tambah Data Barang</a>
                <form action="search1.php" method="get">
                    <input type="text" name="search" placeholder="Cari ID Barang">
                    <input type="submit" value="Cari" style="color: #fff; background-color: #5664E9">
                </form>
            </div>
        </div>
    </div>

    <div class="footer">
        <p>@Copyright <b>Meng-Alpro 2023</b></p>
    </div>

</body>

</html>