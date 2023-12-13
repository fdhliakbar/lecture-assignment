import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double panjang, lebar, tinggi;
        int i = 1;

        System.out.println("----- Program Handling -----\n");

        System.out.print("Masukkan jumlah balok kayu: ");
        int jumlahBalokKayu = input.nextInt();

        if (jumlahBalokKayu > 0) {
            BalokKayu balokKayu = new BalokKayu(); // Create instance outside the loop

            while (i <= jumlahBalokKayu) {
                System.out.println("Masukkan nilai balok kayu ke-" + i);
                System.out.print("Panjang: ");
                panjang = input.nextDouble();

                System.out.print("Lebar: ");  // Change this line to read lebar
                lebar = input.nextDouble();

                System.out.print("Tinggi: ");  // Change this line to read tinggi
                tinggi = input.nextDouble();

                if (balokKayu.isDimension(panjang, lebar, tinggi)) {
                    double volume = balokKayu.jumlahVolume(panjang, lebar, tinggi);

                    System.out.println("Hasil Volume ke-" + i + " : " + volume);
                } else {
                    System.out.println("Maaf, program yang anda masukkan sepertinya salah!");
                    --i;
                }

                i++;
            }
        }
        System.out.println("Program Berakhir");
    }
}
