import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class FindAdultUsers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<User> users = new ArrayList<>();

        int numberOfUsers = 0;
        while (true) {
            try {
                numberOfUsers = Integer.parseInt(scanner.nextLine());
                break;
            } catch (NumberFormatException e) {
                System.out.println("Could not parse a number. Please try again");
            }
        }

        for (int i = 0; i < numberOfUsers; i++) {
            String name = scanner.nextLine();

            Integer age = null;
            while (age == null) {
                String ageInput = scanner.nextLine();
                try {
                    age = Integer.parseInt(ageInput);
                    if (age <= 0) {
                        System.out.println("Incorrect input. Age <= 0");
                        age = null;
                        break; // Skip adding this user
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Could not parse a number. Please try again");
                }
            }

            if (age != null) {
                users.add(new User(name, age));
            }
        }

        List<String> adultNames = users.stream()
                .filter(user -> user.getAge() >= 18)
                .map(User::getName)
                .collect(Collectors.toList());

        if (!adultNames.isEmpty()) {
            System.out.println(String.join(", ", adultNames));
        }
    }
}
