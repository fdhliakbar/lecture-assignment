public class PegawaiTetap extends Pegawai{
    protected double gajiPokok;

    public PegawaiTetap(String nama, String jabatan, double gajiPokok) {
        super(nama, jabatan);
        this.gajiPokok = gajiPokok;
    }

    @Override
    protected double totalGaji() {
        return gajiPokok;
    }
}
