package exercise7;

import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Fayl yo‘lini o‘qish
        String filePath = scanner.nextLine();

        try {
            // Faylni o‘qish uchun ochish
            File file = new File(filePath);
            Scanner fileScanner = new Scanner(file);

            // Fayldan massiv hajmini o‘qish
            int size;
            try {
                size = fileScanner.nextInt();
            } catch (Exception e) {
                System.out.println("Could not parse a number. Please try again");
                fileScanner.close();
                scanner.close();
                return;
            }

            // Noto‘g‘ri hajmni tekshirish
            if (size <= 0) {
                System.out.println("Input error. Size <= 0.");
                fileScanner.close();
                scanner.close();
                return;
            }

            // To‘g‘ri sonlarni yig‘ish uchun ArrayList
            ArrayList<Double> numbersList = new ArrayList<>();

            // Fayldan sonlarni o‘qish
            while (fileScanner.hasNext() && numbersList.size() < size) {
                try {
                    double num = fileScanner.nextDouble();
                    numbersList.add(num);
                } catch (Exception e) {
                    // Noto‘g‘ri kirishni o‘tkazib yuborish
                    fileScanner.next(); // Keyingi token’ga o‘tish
                }
            }

            // Agar yetarli son o‘qilmagan bo‘lsa
            if (numbersList.size() < size) {
                System.out.println("Input error. Insufficient number of elements");
                fileScanner.close();
                scanner.close();
                return;
            }

            // ArrayList’ni ibtidoiy double massivga aylantirish
            double[] numbers = new double[numbersList.size()];
            for (int i = 0; i < numbersList.size(); i++) {
                numbers[i] = numbersList.get(i);
            }

            // O‘qilgan sonlar sonini va sonlarni chop etish
            System.out.println(numbers.length);
            for (int i = 0; i < numbers.length; i++) {
                System.out.print(numbers[i]);
                if (i < numbers.length - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();

            // Minimal va maksimal qiymatlarni topish
            double min = numbers[0];
            double max = numbers[0];
            for (int i = 1; i < numbers.length; i++) {
                if (numbers[i] < min) {
                    min = numbers[i];
                }
                if (numbers[i] > max) {
                    max = numbers[i];
                }
            }

            // Minimal va maksimal qiymatlarni result.txt ga saqlash
            try {
                PrintWriter writer = new PrintWriter("result.txt");
                writer.println(min + " " + max);
                writer.close();
                System.out.println("Saving min and max values in file");
            } catch (FileNotFoundException e) {
                System.out.println("Could not write to result.txt");
            }

            fileScanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("Input error. File doesn't exist");
        }

        scanner.close();
    }
}