<!DOCTYPE html>
<html>

<head>
    <title>Event Ticket</title>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>
    <?php
    // Mendapatkan data dari form registrasi
    $email = $_POST['email'];
    $nama = $_POST['nama'];
    $no_telp = $_POST['no_telp'];
    $alamat = $_POST['alamat'];
    $no_identitas = $_POST['no_identitas'];

    // Menghasilkan nomor ticket secara otomatis
    // Anda bisa menggunakan logika yang lebih kompleks untuk menghasilkan nomor
    // ticket berikutnya jika ada database yang menyimpan data tiket terakhir
    $nomor_ticket = 'PWEB-000000001';

    // Menampilkan e-ticket
    echo '<div class="container">';
    echo '<h1>E-Ticket</h1>';
    echo '<p>Nomor Ticket: ' . $nomor_ticket . '</p>';
    echo '<p>Nama: ' . $nama . '</p>';
    echo '<p>Email: ' . $email . '</p>';
    echo '</div>';
    ?>
</body>

</html>