//
//	PersonTest.java
//	Created by Avikant Saini on 9/14/15.
//

import java.util.*;
import java.text.*;

public class PersonTest {
	
	public static void main (String [] args) {

		Scanner sc = new Scanner (System.in);
		
		int choice;
		
		System.out.println ("1. Person\n2. College Graduate : Person\nExit.\nChoice: ");
		choice = sc.nextInt();
		
		if (choice == 1) {
			Person person = new Person ();
			person.inputFields ();
			person.display ();
		}
		
		else if (choice == 2) {
			CollegeGraduate cg = new CollegeGraduate ();
			cg.inputFields ();
			cg.display ();
		}
		
		else {
			System.exit (0);
		}

	}
}
