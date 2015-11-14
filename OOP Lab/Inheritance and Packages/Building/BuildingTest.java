//
// BuildingTest.java
//
//
//

package com.course.buildings;

import java.util.*;

public class BuildingTest {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		Building building = new Building();
		House house = new House();
		School school = new School();

		System.out.print("Enter square footage of building: ");
		building.setFeet(sc.nextFloat());

		System.out.print("Enter stories in building: ");
		building.setStories(sc.nextInt());

		System.out.println("Building made with\nStories: " + building.getStories()  +  "\nSquare footage: " + building.getFeet());

		System.out.print("Enter number of bed rooms: ");
		house.setBed(sc.nextInt());

		System.out.print("Enter number of bath rooms: ");
		house.setBath(sc.nextInt());

		System.out.println("House made with\nRoom numbers: " + house.getBed() + "\nBath room numbers: " + house.getBath());

		System.out.print("Enter number of classrooms: ");
		school.setClass(sc.nextInt());

		System.out.print("Enter level of grade :");
		sc.nextLine();
		school.setGrade(sc.nextLine());

		System.out.println("School made with\nGrade: " + school.getGrade() + "\nNumber of classrooms: " + school.getnClass());
	}

}

