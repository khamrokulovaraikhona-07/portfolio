package exercise4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = inputNumber(scanner);
        if (n <= 0) {
            System.out.println("Input error. Size <= 0");
            return;
        }

        int[] numbers = inputArray(scanner, n);
        double average = calculateNegativeAverage(numbers);
        if (Double.isNaN(average)) {
            System.out.println("There are no negative elements");
        } else {
            System.out.println((int) average);
        }
    }

    // Kiritma: n ni o‘qish
    private static int inputNumber(Scanner scanner) {
        while (!scanner.hasNextInt()) {
            System.out.println("Could not parse a number. Please try again");
            scanner.next();
        }
        return scanner.nextInt();
    }

    // Kiritma: n ta sonni o‘qish
    private static int[] inputArray(Scanner scanner, int n) {
        int[] numbers = new int[n];
        for (int i = 0; i < n; i++) {
            while (!scanner.hasNextInt()) {
                System.out.println("Could not parse a number. Please try again");
                scanner.next();
            }
            numbers[i] = scanner.nextInt();
        }
        return numbers;
    }

    // Manfiy sonlarning o‘rta arifmetigini hisoblash
    private static double calculateNegativeAverage(int[] numbers) {
        int sum = 0;
        int count = 0;
        for (int num : numbers) {
            if (num < 0) {
                sum += num;
                count++;
            }
        }
        if (count == 0) {
            return Double.NaN; // Manfiy sonlar yo‘q
        }
        return (double) sum / count;
    }
}