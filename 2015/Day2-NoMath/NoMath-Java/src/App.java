import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;

public class App {
    private static int ribbon = 0;
    private static int area = 0;

    public static void main(String[] args) throws FileNotFoundException {
        var fileName = "./lib/input.txt";

        try (var scanner = new Scanner(new File(fileName))) {
            while (scanner.hasNext()) {
                String line = scanner.nextLine();

                // Part 1
                int[] numbers = parseLine(line);
                int side1 = numbers[0] * numbers[1];
                int side2 = numbers[0] * numbers[2];
                int side3 = numbers[1] * numbers[2];
                area += 2 * (side1 + side2 + side3) + side1;

                // Part 2
                ribbon += (numbers[0] + numbers[1]) * 2;
                ribbon += numbers[0] * numbers[1] * numbers[2];
            }
        }
        
        System.out.println("The area of wrapping paper is " + area);
        System.out.println("The length of ribon is " + ribbon);
    }

    public static int[] parseLine(String line) {
        String[] parsedLine = line.split("x");
        int[] numbers = new int[3];
        for (int i = 0; i < parsedLine.length; i++) {
            numbers[i] = Integer.parseInt(parsedLine[i]);
        }
        Arrays.sort(numbers);
        return numbers;
    }
}
