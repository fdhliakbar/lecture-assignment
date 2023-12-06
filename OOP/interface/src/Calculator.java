public class Calculator implements MathFormula{
    @Override
    public double summation(double x, double y) {
        return x + y;
    }

    @Override
    public double subtraction(double x, double y) {
        return x - y;
    }

    @Override
    public double multiplication(double x, double y) {
        return x * y;
    }

    @Override
    public double division(double x, double y) {
        return x / y;
    }

    @Override
    public double remainder(double x, double y) {
        return x % y;
    }

    @Override
    public double areaOfCircle(double r, double PI) {
        return 2 * PI * r;
    }

    @Override
    public double areaOfSquare(double s) {
        return s * 2;
    }
}
