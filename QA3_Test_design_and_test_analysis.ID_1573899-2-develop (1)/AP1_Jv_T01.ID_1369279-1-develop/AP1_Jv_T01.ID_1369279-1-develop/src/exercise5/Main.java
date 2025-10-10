package exercise5;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // Method to check if first and last digits match
    public static boolean hasMatchingDigits(long num) {
        // Convert to positive number
        num = Math.abs(num);
        // Get last digit
        long lastDigit = num % 10;
        // Get first digit
        while (num >= 10) {
            num /= 10;
        }
        long firstDigit = num;
        return firstDigit == lastDigit;
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

                // Initialize arrays
                ArrayList<Long> numbers = new ArrayList<>();
                ArrayList<Long> matchingNumbers = new ArrayList<>();

                // Read numbers into array
                for (int i = 0; i < size; i++) {
                    while (true) {
                        try {
                            long num = scanner.nextLong();
                            numbers.add(num);
                            // Check if number has matching first and last digits
                            if (hasMatchingDigits(num)) {
                                matchingNumbers.add(num);
                            }
                            break;
                        } catch (Exception e) {
                            System.out.println("Could not parse a number. Please try again");
                            scanner.nextLine(); // Clear invalid input
                        }
                    }
                }

                // Print results
                if (matchingNumbers.isEmpty()) {
                    System.out.println("There are no such elements");
                } else {
                    for (int i = 0; i < matchingNumbers.size(); i++) {
                        System.out.print(matchingNumbers.get(i));
                        if (i < matchingNumbers.size() - 1) {
                            System.out.print(" ");
                        }
                    }
                    System.out.println();
                }
                break;

            } catch (Exception e) {
                System.out.println("Could not parse a number. Please try again");
                scanner.nextLine(); // Clear invalid input
            }
        }

        scanner.close();
    }
}