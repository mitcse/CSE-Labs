package buildings;
import java.util.*;

class TestBuild
{	
	public static void main(String[] args)
	{
		Scanner userEntry = new Scanner(System.in);
		
		Building b = new Building();
		House h = new House();
		School s = new School();

		System.out.print("Enter square footage of building: ");
		b.setFeet(userEntry.nextFloat());

		System.out.print("Enter stories in building: ");
		b.setStories(userEntry.nextInt());

		System.out.println("Building made with\nStories: "+b.getStories() + "\nSquare footage: "+b.getFeet());

		System.out.print("Enter number of bed rooms: ");
		h.setBed(userEntry.nextInt());

		System.out.print("Enter number of bath rooms: ");
		h.setBath(userEntry.nextInt());

		System.out.println("House made with\nRoom numbers: "+h.getBed()+"\nBath room numbers: "+h.getBath());

		System.out.print("Enter number of classrooms: ");
		s.setClass(userEntry.nextInt());

		System.out.print("Enter level of grade :");
		s.setGrade(userEntry.nextLine());
		s.setGrade(userEntry.nextLine());

		System.out.println("School made with\nGrade: "+s.getGrade()+"\nNumber of classrooms: "+s.getnClass());
	}

}

