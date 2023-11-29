import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("~~~ Data Pegawai Tetap ~~~");
        System.out.print("Masukkan Nama : ");
        String namaPegawaiTetap = input.next();
        System.out.print("Masukkan Jabatan : ");
        String jabatanPegawaiTetap = input.next();
        System.out.print("Masukkan Gaji Pokok : ");
        double gajiPokok = input.nextDouble();

        System.out.print("\n~~~ Data Pegawai Kontrak ~~~\n");
        System.out.print("Masukkan nama : ");
        String namaPegawaiKontrak = input.next();
        System.out.print("Masukkan Jabatan : ");
        String jabatanPegawaiKontrak = input.next();
        System.out.print("Masukkan Jumlah Jam Kerja : ");
        double jamKerja = input.nextDouble();
        System.out.print("Masukkan Gaji Kontrak : ");
        double gajiKontrak = input.nextDouble();

        System.out.println(" ");

        PegawaiTetap pegawaiTetap = new PegawaiTetap(namaPegawaiTetap, jabatanPegawaiTetap, gajiPokok);
        PegawaiKontrak pegawaiKontrak = new PegawaiKontrak(namaPegawaiKontrak, jabatanPegawaiKontrak, jamKerja, gajiKontrak);

        System.out.println("Total Gaji " + namaPegawaiTetap + " : " + pegawaiTetap.totalGaji());
        System.out.println("Total Gaji " + namaPegawaiKontrak + " : " + pegawaiKontrak.totalGaji());
    }
}