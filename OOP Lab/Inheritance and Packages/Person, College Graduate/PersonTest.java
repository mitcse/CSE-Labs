//
//	PersonTest.java
//	Created by Avikant Saini on 9/14/15.
//

import java.util.*;
import java.text.*;

public class PersonTest {
	
	public static void main (String [] args) {

		Scanner sc = new Scanner (System.in);
		
		char choice;
		
		System.out.print ("1. Person\n2. College Graduate : Person\nQ. Quit.\nChoice: ");
		choice = sc.next().charAt(0);
		
		if (choice == '1') {
			Person person = new Person ();
			person.inputFields ();
			person.display ();
		}
		
		else if (choice == '2') {
			CollegeGraduate cg = new CollegeGraduate ();
			cg.inputFields ();
			cg.display ();
		}
		
		else {
			System.exit (0);
		}

	}
}
