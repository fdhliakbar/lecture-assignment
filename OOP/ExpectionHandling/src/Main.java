import java.util.Scanner;

class MathFormula extends Exception {
    public MathFormula(String message) {
        super(message);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        try {
            int result = divide(10, 2);
            System.out.println("Hasil: " + result);
        } catch (MathFormula e) {
            System.out.println("Terjadi kesalahan " + e.getMessage());
        } finally {
            System.out.println("Blok finally akan selalu dijalankan.");
        }
    }

    public static int divide(int firstNumber, int secondNumber) throws MathFormula {
        if (secondNumber == 0) {
            throw new MathFormula("Tidak bisa melakukan pembagian oleh nol(0).");
        }
        return firstNumber / secondNumber;
    }
}
