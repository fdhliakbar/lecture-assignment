import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Masukkan nama penulis : ");
        String penulis = input.nextLine();

        Penulis penulis1 = new Penulis(penulis);

        System.out.print("Berapa banyak " + penulis + " ingin menulis Buku : ");
        int N = input.nextInt();
        input.nextLine(); // Membersihkan newline di buffer

        String[] books = new String[100];

        if (N > 0) {
            for (int i = 0; i < N; i++) {
                System.out.print("Nama Buku : ");
                books[i] = input.nextLine();
            }
        }

        Perpustakaan perpustakaan = new Perpustakaan(books, N);

        perpustakaan.displayInfo();
    }
}
