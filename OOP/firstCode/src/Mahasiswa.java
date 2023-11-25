public class Mahasiswa {
    String nama;
    String nim;

    Mahasiswa(String nama, String nim) {
        this.nama = nama;
        this.nim = nim;
    }

    void displayInfo() {
        System.out.println("Mahasiswa : " + nama);
        System.out.println("NIM : " + nim);
    }
}
