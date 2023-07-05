<!DOCTYPE html>
<html>

<head>
    <title>Registrasi Event</title>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>
    <div class="container">
        <h1>Registrasi Event Konser Musik</h1>
        <form action="ticket.php" method="post">
            <label for="email">Email:</label>
            <input type="email" name="email" required><br>

            <label for="nama">Nama:</label>
            <input type="text" name="nama" required><br>

            <label for="no_telp">No. Telp:</label>
            <input type="tel" name="no_telp" required><br>

            <label for="alamat">Alamat:</label>
            <textarea name="alamat" required></textarea><br>

            <label for="no_identitas">No. Identitas (SIM/KTP):</label>
            <input type="text" name="no_identitas" required><br>

            <input type="submit" value="Submit">
        </form>
    </div>
</body>

</html>