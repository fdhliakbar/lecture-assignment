public class BalokKayu {
    public double jumlahVolume(double panjang, double lebar, double tinggi) {
        return panjang * lebar * tinggi;
    }

    public boolean isDimension(double panjang, double lebar, double tinggi) {
        return panjang < lebar && lebar > tinggi;
    }
}
