import java.util.Scanner;
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Input mahasiswa
        System.out.println("Masukkan nama mahasiswa : ");
        String namaMhs = input.nextLine();
        System.out.println("Masukkan nama NIM : ");
        String nim = input.nextLine();

        Mahasiswa mahasiswa = new Mahasiswa(namaMhs, nim);

        // Tampilkan Informasi Mahasiswa
        System.out.println("Informasi Mahasiswa:");
        mahasiswa.displayInfo();

    }
}