public interface MathFormula {
     double PI = 3.14;

    // Perhitungan
    double summation(double x, double y);
    double subtraction(double x, double y);
    double multiplication(double x, double y);
    double division(double x, double y);
    double remainder(double x, double y);


    // Rumus Luas Permukaan
    double areaOfCircle(double r, double PI);
    double areaOfSquare(double s);
}
