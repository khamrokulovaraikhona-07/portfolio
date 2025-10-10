package exercise9;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Custom method to filter strings containing the given substring
    public static List<String> filterStrings(List<String> strings, String substring) {
        List<String> result = new ArrayList<>();
        for (String str : strings) {
            if (str.contains(substring)) {
                result.add(str);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of strings
        int size;
        while (true) {
            try {
                size = scanner.nextInt();
                if (size < 0) {
                    System.out.println("Input error. Size < 0.");
                    scanner.close();
                    return;
                }
                scanner.nextLine(); // Clear newline
                break;
            } catch (Exception e) {
                System.out.println("Could not parse a number. Please try again");
                scanner.nextLine(); // Clear invalid input
            }
        }

        // Read strings into a list
        List<String> strings = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            strings.add(scanner.nextLine());
        }

        // Read the substring for filtering
        String substring = scanner.nextLine();

        // Filter strings using custom method
        List<String> filteredStrings = filterStrings(strings, substring);

        // Print filtered strings
        if (filteredStrings.isEmpty()) {
            System.out.println();
        } else {
            for (int i = 0; i < filteredStrings.size(); i++) {
                System.out.print(filteredStrings.get(i));
                if (i < filteredStrings.size() - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println();
        }

        scanner.close();
    }
}