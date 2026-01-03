import java.util.Scanner;

public class QuizGame{
    public static void main(String[] arg) {
        Scanner scanner = new Scanner(System.in);

        String[] question1 = {
                "Data Manipulation Language (DML)",
                "Data Definition Language (DDL)",
                "Data Control Language (DCL)",
                "Transaction Control Language (TCL)"
        };

        String[] question2 = {
                "Attribute",
                "Relation",
                "Tuple",
                "Entity"
        };

        String[] question3 = {
                "External Level",
                "Conceptual Level",
                "Internal Level",
                "Logical Level"
        };

        String[] question4 = {
                "Strong Entity Set",
                "Multivalued Attribute",
                "Identifying Relationship Set (for weak entities)",
                "Recursive Relationship"
        };

        String[] question5 = {
                "Atomicity",
                "Consistency",
                "Isolation",
                "Durability"
        };

        String[] question6 = {
                "Selection (σ)",
                "Projection (π)",
                "Join (⋈)",
                "Union (∪)"
        };

        String[] question7 = {
                "Data Encryption",
                "Referential Integrity",
                "Physical Data Independence",
                "Primary Key indexing"
        };

        String[] question8 = {
                "First Normal Form (1NF)",
                "Second Normal Form (2NF)",
                "Third Normal Form (3NF)",
                "Boyce-Codd Normal Form (BCNF)"
        };

        String[] question9 = {
                "UNIQUE",
                "CHECK",
                "PRIMARY KEY",
                "DEFAULT"
        };

        String[] question10 = {
                "Starvation",
                "Deadlock",
                "Cascading Abort",
                "Dirty Read"
        };

        String[][] allQuestions = {
                question1, question2,
                question3, question4,
                question5, question6,
                question7, question8,
                question9, question10,
        };

        String[] mainQuestion = {
                "Which component of SQL is responsible for defining the structure of the database, such as creating, altering, and dropping tables?",
                "In a relational database, what is the specific term used to describe a single row within a table?",
                "In the Three-Schema Architecture of a database system, which level describes how the data is actually stored on the physical storage media?",
                "In an ER Diagram, what does a double diamond symbol typically represent?",
                "Which property of a transaction ensures that all operations within the transaction are completed successfully, or none of them are applied at all?",
                "Which relational algebra operation is used to select a subset of columns from a relation while removing duplicate rows?",
                "A 'Foreign Key' in a relational database is primarily used to achieve which of the following?",
                "Which Normal Form (NF) is specifically concerned with removing 'transitive dependencies' from a relation?",
                "Which SQL constraint is used to ensure that all values in a column are different and do not contain NULL values?",
                "In a database, what occurs when two transactions are each waiting for the other to release a lock, resulting in a permanent stall?",
        };

        int[] answers = {2, 3, 3, 3, 1, 2, 2, 3, 3, 2};
        int score = 0;
        boolean gameActive = true;

        System.out.println("******************************");
        System.out.println("Welcome to the Java Quiz Game!");
        System.out.println("******************************");

        for (int i = 0; i < 10; i++) {
            if (!gameActive) {
                System.out.println("Total Score: " + score);
                break;
            }
            System.out.println(mainQuestion[i] + "\n");
            for (int j = 0; j < 4; j++) {
                System.out.println((j+1)+ ". " + allQuestions[i][j]);
            }
            System.out.print("Answer: ");
            int answer = scanner.nextInt();
            if (answer == 0) {
                gameActive = false;
                break;
            }
            if (answer == answers[i]) {
                System.out.println("*****");
                System.out.println("Right");
                System.out.println("*****");
                score++;
            }
            else {
                System.out.println("*****");
                System.out.println("Wrong");
                System.out.println("*****");
            }
        }

        System.out.println("Total Score: " + score);
    }
}
