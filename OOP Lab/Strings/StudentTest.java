//
//  StudentTest.c
//  Student, Students and StudentTest
//
//  Created by Avikant Saini on 8/31/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

import java.util.*;
import java.text.*;

class Student {
    
    int regNo;
    String fullName;
    GregorianCalendar dateJoined;
    short semester;
    float gpa;
    float cgpa;
    
    Student () {
        regNo = 0;
        fullName = "";
        dateJoined = new GregorianCalendar();
        semester = 0;
        gpa = 0.f;
        cgpa = 0.f;
    }
    
    Student (Student s) {
        this.regNo = s.regNo;
        this.fullName = s.fullName;
        this.dateJoined = s.dateJoined;
        this.semester = s.semester;
        this.gpa = s.gpa;
        this.cgpa = s.cgpa;
    }
    
    public void display () {
        SimpleDateFormat dateFormat = new SimpleDateFormat("MMM dd, yyyy"); 
        System.out.println("\n\t       Name | " + fullName + 
                           "\n\t     Reg No | " + regNo + 
                           "\n\tDate Joined | " + dateFormat.format(dateJoined.getTime()) +
                           "\n\t   Semester | " + semester + 
                           "\n\t        GPA | " + gpa + 
                           "\n\t       CGPA | " + cgpa + 
                           "\n");
    }
    
    public void input () {
        Scanner sc = new Scanner(System.in);
        System.out.print("\n\tEnter Name: ");
        fullName = sc.nextLine();
        System.out.print("\tEnter Date Joined (yyyy/mm/dd): ");
        dateJoined = new GregorianCalendar(sc.nextInt(), sc.nextInt() - 1, sc.nextInt());
        System.out.print("\tEnter Semester: ");
        semester = sc.nextShort();
        System.out.print("\tEnter GPA: ");
        gpa = sc.nextFloat();
        System.out.print("\tEnter CGPA: ");
        cgpa = sc.nextFloat();
        System.out.println();
    }
}

class Students {
    
    Student students[];
    int size;
    
    public Students (int size) {
        this.size = size;
        this.students = new Student[size];
    }
    
    public void inputAll () {
        for (int i = 0; i < size; ++i) {
            System.out.println("\t\tStudent " + (i+1) + " :");
            students[i] = new Student();
            students[i].input();
            SimpleDateFormat dateFormat = new SimpleDateFormat("yy");
            String regNo = dateFormat.format(students[i].dateJoined.getTime());
            regNo += String.format( "%02d", i+1);
            students[i].regNo = Integer.parseInt(regNo);
        }
    }
    
    public void displayAll () {
        for (Student stud: students)
            stud.display();
    }
    
    public void list (String str) {
        for (Student stud: students) {
            if (stud.fullName.contains(str))
                stud.display();
        }
    }
    
    public void list (char ch) {
        for (Student stud: students) {
            if (stud.fullName.indexOf(ch) == 0)
                stud.display();
        }
    }
    
    public void shortenName () {
        for (Student stud: students) {
            String newName = "";
            String lastName = "";
            StringTokenizer st = new StringTokenizer (stud.fullName);
            while (st.hasMoreTokens()) {
                lastName = st.nextToken();
                newName += lastName.charAt(0) + ". ";
            }
            newName = newName.substring(0, newName.length() - 3) + lastName;
            stud.fullName = newName;
        }
    }
    
    public void sort (String wrt) {
        for (int i = 0; i < size - 1; ++i) {
            int min = i;
            for (int j = i + 1; j < size; ++j) {
                if (wrt.equals("semester") && (students[j].semester > students[min].semester))
                    min = j;
                if (wrt.equals("cgpa") && (students[j].cgpa > students[min].cgpa))
                    min = j;
                if (wrt.equals("fullName") && (students[j].fullName.compareTo(students[min].fullName)) < 0)
                    min = j;
            }
            if (min != i) {
                Student temp = students[i];
                students[i] = students[min];
                students[min] = temp;
            }
        }
    }
}

public class StudentTest {
    
    public static void main (String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\n\tEnter the number of records: ");
        int size = sc.nextInt();
        
        Students students = new Students (size);
        students.inputAll();
		sc.nextLine();
        
        char choice;
        do {
            System.out.print("\n\t1. Display Records." + 
							"\n\t2. Sort wrt Name." +
							"\n\t3. Sort wrt Semester (Desceding)." +
							"\n\t4. Sort wrt CGPA (Descending)." +
							"\n\t5. List all Students whose name begins with a character." +
							"\n\t6. List all Students whose name contains a string." +
							"\n\t7. Change the names of all students to shortened form." +
							"\nAnything else for exit." +
							"\n\n\t Enter choice: ");
            choice = sc.next().charAt(0);
			sc.nextLine();
            
            switch (choice) {
                case '1': students.displayAll();
                    break;
                case '2': students.sort("fullName");
                        System.out.println("\nSotred wrt Name.\n");
                        students.displayAll();
                    break;
                case '3': students.sort("semester");
                        System.out.println("\nSotred wrt Semester.\n");
                        students.displayAll();
                    break;
                case '4': students.sort("cgpa");
                        System.out.println("\nSotred wrt CGPA.\n");
                        students.displayAll();
                    break;
                case '5': System.out.print("\n\tEnter the character: ");
                        char ch = sc.next().charAt(0);
                        students.list(ch);
						System.out.println("\n\tAll the student names starting with \' " + ch + "\' : \n");
						students.displayAll();
                    break;
                case '6': System.out.print("\n\tEnter the string: ");
                        String subs = sc.nextLine();
                        students.list(subs);
						System.out.println("\n\tAll the student names containing \' " + subs + "\' : \n");
						students.displayAll();
                    break;
                case '7': students.shortenName();
                        System.out.println("\n\tShortened Name.\n");
                        students.displayAll();
                    break;
                default: break;
            }
            
        } while ("1234567".indexOf(choice) != -1);
    }
}