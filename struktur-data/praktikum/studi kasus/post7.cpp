#include <iostream>
#include <queue>

// Struktur untuk menyimpan informasi transaksi
struct Transaction {
    std::string customerName;
    double amount;
    bool success; // Status keberhasilan pembayaran
};

// Fungsi untuk memproses transaksi pembayaran
void processPayment(Transaction& transaction) {
    // Logika pemrosesan pembayaran (contoh: selalu berhasil)
    transaction.success = true;
}

int main() {
    std::queue<Transaction> paymentQueue;

    // Menambahkan beberapa transaksi ke antrian
    paymentQueue.push({"Customer1", 100.0, false});
    paymentQueue.push({"Customer2", 150.0, false});
    paymentQueue.push({"Customer3", 200.0, false});

    // Memproses transaksi dalam antrian
    while (!paymentQueue.empty()) {
        Transaction currentTransaction = paymentQueue.front();
        paymentQueue.pop();

        // Memproses pembayaran
        processPayment(currentTransaction);

        // Menangani kesalahan atau kegagalan pembayaran
        if (!currentTransaction.success) {
            std::cout << "Error processing payment for customer: " << currentTransaction.customerName << std::endl;
            // Logika untuk menangani ulang atau memberikan pesan kesalahan
        } else {
            std::cout << "Payment successful for customer: " << currentTransaction.customerName << std::endl;
        }
    }

    return 0;
}
