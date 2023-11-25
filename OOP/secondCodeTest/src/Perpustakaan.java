public class Perpustakaan {
    String[] listBuku = new String[100];
    int N = 0;

    Perpustakaan(String[] listBuku, int N) {
        this.N = N;

        for (int i = 0; i < N; i++) {
            this.listBuku[i] = listBuku[i];
        }
    }

    void displayInfo() {
        System.out.println("\n--- Daftar Buku Perpustakaan ---");
        for (int i = 0; i < N; i++) {
            System.out.println(i + 1 + " " + listBuku[i]);
        }
        System.out.println("----------------------------------");
    }
}
