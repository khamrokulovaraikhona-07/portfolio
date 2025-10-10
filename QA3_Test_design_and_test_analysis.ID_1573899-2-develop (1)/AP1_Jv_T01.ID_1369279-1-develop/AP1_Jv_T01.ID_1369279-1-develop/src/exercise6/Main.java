package exercise6;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // Method to perform selection sort on an array of doubles in ascending order
    public static void selectionSort(double[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            // Find the minimum element in the unsorted portion
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            // Swap the minimum element with the first element of the unsorted portion
            if (minIndex != i) {
                double temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            try {
                // Read size of array
                int size = scanner.nextInt();

                // Check for invalid size
                if (size <= 0) {
                    System.out.println("Input error. Size <= 0.");
                    return;
                }

                // Initialize ArrayList to collect numbers
                ArrayList<Double> numbersList = new ArrayList<>();

                // Read numbers into ArrayList
                for (int i = 0; i < size; i++) {
                    while (true) {
                        try {
                            double num = scanner.nextDouble();
                            numbersList.add(num);
                            break;
                        } catch (Exception e) {
                            System.out.println("Could not parse a number. Please try again");
                            scanner.nextLine(); // Clear invalid input
                        }
                    }
                }

                // Convert ArrayList to primitive double array
                double[] numbers = new double[size];
                for (int i = 0; i < size; i++) {
                    numbers[i] = numbersList.get(i);
                }

                // Sort the array
                selectionSort(numbers);

                // Print the sorted array
                for (int i = 0; i < numbers.length; i++) {
                    System.out.print(numbers[i]);
                    if (i < numbers.length - 1) {
                        System.out.print(" ");
                    }
                }
                System.out.println();
                break;

            } catch (Exception e) {
                System.out.println("Could not parse a number. Please try again");
                scanner.nextLine(); // Clear invalid input
            }
        }

        scanner.close();
    }
}