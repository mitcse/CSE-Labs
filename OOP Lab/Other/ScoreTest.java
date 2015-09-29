//
//	ScoreTest.java
//	
//	Created by Avikant Saini on 9/25/15
//

import java.util.*;

class Student {
	
	String id;
	int score;

	public Student (String id) {
		this.id = id;
		score = 0;
	}
}

class ScoreException extends Exception {
	ScoreException (String errorMessage) {
		super(errorMessage);
	}
}

public class ScoreTest {

	public static void main (String [] args) {
		Scanner sc = new Scanner(System.in);

		Student students[] = new Student[3];

		for (int i = 0; i < 3; ++i) {
			
			String randomUUID = UUID.randomUUID().toString().replaceAll("-", "").substring(0, 10); // Random String...

			students[i] = new Student(randomUUID); // Create a new instance
			
			System.out.print("\n\tStudent " + (i+1) + ", id: " + students[i].id + "\n\tEnter score (0-100): ");
			
			int score = 0;

			try {
				score = sc.nextInt(); // Input the score
				if (score < 0 || score > 100) {
					score = 0;
					throw new ScoreException("Invalid Score. Using default 0 value."); // Throw the exception and set value to 0
				}
			}
			
			catch (ScoreException exception) {
				System.err.println("\n\tError: " + exception);
			}

			finally {
				students[i].score = score; // Finally set the score value to the inputted value or 0
			}
		
		}

		System.out.println("\n\tID\t\tScore");
		for (Student stud : students)
			System.out.println("\t" + stud.id + "\t" + stud.score);

	}
}