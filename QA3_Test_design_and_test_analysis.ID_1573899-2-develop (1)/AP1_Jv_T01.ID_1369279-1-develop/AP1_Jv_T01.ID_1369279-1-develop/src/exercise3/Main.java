package exercise3;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = inputNumber(scanner);
        if (n > 90) {
            System.out.println("Too large n");
        } else if (n >= 0) {
            long fib = fibonacci(n);
            System.out.println(fib);
        } else {
            System.out.println("Incorrect input");
        }
    }

    // Kiritma metodi
    private static int inputNumber(Scanner scanner) {
        while (!scanner.hasNextInt()) {
            System.out.println("Could not parse a number. Please try again");
            scanner.next(); // Noto‘g‘ri kiritmani tozalash
        }
        return scanner.nextInt();
    }

    // Fibonachchi sonini hisoblash
    private static long fibonacci(int n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}