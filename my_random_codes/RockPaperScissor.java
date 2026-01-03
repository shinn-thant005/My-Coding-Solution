import java.util.Scanner;
import java.util.Random;

public class RockPaperScissor {
    public static void main(String[] arg) {
        String isQuit = " ";
        Random rand = new Random();
        Scanner scanner = new Scanner(System.in);
        int score = 0;
        int comScore = 0;
        int attempt = 1;

        while(true) {
            int n = rand.nextInt(1, 4);
            int x = 0;
            System.out.print("Enter your move(rock, paper, scissor): ");
            String move = scanner.next().toLowerCase();
            if (move.equals("quit")) {
                break;
            }

            switch (move) {
                case "rock" -> x = 1;
                case "paper" -> x = 2;
                case "scissor" -> x = 3;
                default -> {
                    System.out.println("Wrong Move! Try Again!");
                    continue;
                }
            }

            System.out.print("Computer Choice: ");
            switch (n) {
                case 1 -> System.out.println("Rock");
                case 2 -> System.out.println("Paper");
                case 3 -> System.out.println("Scissor");
            }

            if (n == 1 && move.equals("paper")) {
                System.out.println("You Win!");
                score++;
            }
            else if (n == 2 && move.equals("scissor")) {
                System.out.println("You Win!");
                score++;
            }
            else if (n == 3 && move.equals("rock")) {
                System.out.println("You Win!");
                score++;
            }
            else if (n == x) {
                System.out.println("Draw!");
                score++;
                comScore++;
            }
            else {
                System.out.println("You Lose!");
                comScore++;
            }
            attempt++;
        }
        System.out.println("\n*** You got " + score + " out of " + attempt + " ***");
        System.out.println("*** Computer got " + comScore + " out of " + attempt + " ***");

        if (score > comScore) {
            System.out.println("***** You Win *****");
        }
        else if (score < comScore){
            System.out.println("***** Computer Win *****");
        }
        else {
            System.out.println("***** Draw *****");
        }
    }
}