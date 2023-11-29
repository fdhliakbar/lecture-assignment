public class PegawaiKontrak extends Pegawai {
    protected double jamKerja, gajiKontrak;

    public PegawaiKontrak(String nama, String jabatan, double jamKerja, double gajiKontrak) {
        super(nama, jabatan);
        this.jamKerja = jamKerja;
        this.gajiKontrak = gajiKontrak;
    }

    @Override
    protected double totalGaji() {
        return jamKerja * gajiKontrak;
    }
}
