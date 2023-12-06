import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Calculator calculator = new Calculator();

        boolean programIteration = true;

        System.out.println("~~~ Kalkulator Sederhana ~~~");

        while (programIteration) {
            System.out.println("1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n4. Pembagian\n5. Sisa Bagi\n");
            System.out.println("========================");
            System.out.println("Pilih Operasi Perhitungan (1/2/3/4/5): ");

            if (input.hasNextInt()) {
                int choose = input.nextInt();

                if (choose >= 1 && choose <= 5) {
                    System.out.print("Masukkan nilai pertama: ");
                    double firstValue = input.nextDouble();

                    System.out.print("Masukkan nilai kedua: ");
                    double secondValue = input.nextDouble();

                    switch (choose) {
                        case 1:
                            System.out.println("Result : " + calculator.summation(firstValue, secondValue));
                            break;
                        case 2:
                            System.out.println("Result : " + calculator.subtraction(firstValue, secondValue));
                            break;
                        case 3:
                            System.out.println("Result : " + calculator.multiplication(firstValue, secondValue));
                            break;
                        case 4:
                            System.out.println("Result : " + calculator.division(firstValue, secondValue));
                            break;
                        case 5:
                            System.out.println("Result : " + calculator.remainder(firstValue, secondValue));
                            break;
                    }

                    System.out.println("========================");
                } else {
                    System.out.println("Sorry: the choice you entered is wrong.");
                    System.out.println("========================");
                }
            } else {
                System.out.println("Invalid input. Please enter a valid integer.");
                input.next(); // Consume the invalid input
            }

            System.out.print("Apakah anda ingin melanjutkan program (y/n): ");
            char continueTheProgram = input.next().charAt(0);

            if (continueTheProgram == 'n' || continueTheProgram == 'N') {
                System.out.println("Progam telah berakhir.");
                System.out.println("========================");
                programIteration = false;
            }
        }

        input.close();
    }
}
