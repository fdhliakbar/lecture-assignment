public abstract class Pegawai {
    protected String nama, jabatan;

    public Pegawai(String nama, String jabatan) {
        this.nama = nama;
        this.jabatan = jabatan;
    }
    protected abstract double totalGaji();
}
