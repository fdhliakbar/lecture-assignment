import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("===== POSTEST 8 =====");

        // INPUT DATA DIRI
        String nama, nim, alamat;
        int usia;

        System.out.print("Masukkan Nama: ");
        nama = input.nextLine();

        System.out.print("Masukkan Alamat: ");
        alamat = input.nextLine();

        System.out.print("Masukkan Usia: ");
        usia = input.nextInt();

        // OUTPUT DATA DIRI
        System.out.println("=================");
        System.out.println("Nama: " + nama);
        System.out.println("Alamat: " + alamat);
        System.out.println("Usia: " + usia);
        System.out.println("=================");
    }
}
