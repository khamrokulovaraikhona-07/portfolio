package exercise1;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double[] coordinates = new double[6];
        for (int i = 0; i < 6; i++) {
            while (!scanner.hasNextDouble()) {
                System.out.println("Could not parse a number. Please try again");
                scanner.next();
            }
            coordinates[i] = scanner.nextDouble();
        }
        double a = calculateDistance(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
        double b = calculateDistance(coordinates[2], coordinates[3], coordinates[4], coordinates[5]);
        double c = calculateDistance(coordinates[4], coordinates[5], coordinates[0], coordinates[1]);
        if (isTriangle(a, b, c)) {
            double perimeter = a + b + c;
            System.out.printf("Perimeter: %.3f\n", perimeter);
        } else {
            System.out.println("It's not a triangle");
        }
    }

    private static double calculateDistance(double x1, double y1, double x2, double y2) {
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    }

    private static boolean isTriangle(double a, double b, double c) {
        return (a + b > c) && (b + c > a) && (a + c > b) && a > 0 && b > 0 && c > 0;
    }
}