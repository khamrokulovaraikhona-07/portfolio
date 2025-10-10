package exercise2;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int seconds = inputSeconds(scanner);
        if (seconds >= 0) {
            String time = calculateTime(seconds);
            outputTime(time);
        } else {
            System.out.println("Incorrect time");
        }
    }

    // Kiritma metodi
    private static int inputSeconds(Scanner scanner) {
        while (!scanner.hasNextInt()) {
            System.out.println("Could not parse a number. Please try again");
            scanner.next(); // Noto‘g‘ri kiritmani tozalash
        }
        return scanner.nextInt();
    }

    // Soat, daqiqa, soniyalarni hisoblash
    private static String calculateTime(int totalSeconds) {
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;
        return String.format("%02d:%02d:%02d", hours, minutes, seconds);
    }

    // Chiqish metodi
    private static void outputTime(String time) {
        System.out.println(time);
    }
}