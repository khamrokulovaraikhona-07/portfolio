package exercise8;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long previous = Long.MIN_VALUE; // Initialize to smallest possible long
        int ordinal = 0; // Track the position of the number in the sequence
        boolean hasInput = false; // Track if at least one number was entered

        while (scanner.hasNext()) {
            try {
                long current = scanner.nextLong();
                ordinal++;
                hasInput = true;

                // Check if current number breaks ascending order
                if (current <= previous) {
                    System.out.println("The sequence is not ordered from the ordinal number of the number " + ordinal);
                    scanner.close();
                    return;
                }

                previous = current; // Update previous for next comparison
            } catch (Exception e) {
                // Invalid input encountered (e.g., non-integer)
                if (hasInput) {
                    // If at least one number was entered, sequence is valid up to this point
                    System.out.println("The sequence is ordered in ascending order");
                } else {
                    // No numbers were entered before invalid input
                    System.out.println("Input error");
                }
                scanner.close();
                return;
            }
        }

        // If input ends and at least one number was entered
        if (hasInput) {
            System.out.println("The sequence is ordered in ascending order");
        } else {
            System.out.println("Input error");
        }

        scanner.close();
    }
}