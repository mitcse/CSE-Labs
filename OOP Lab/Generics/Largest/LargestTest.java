//
//	LargestTest.java
//
//	Created by Avikant Saini on 10/17/15
//


class Largest {

	public static <Type extends Comparable<Type>> Type largest (Type a, Type b, Type c) {
		
		Type max = a;
		
		if (b.compareTo(max) > 0)
			max = b; 

		if (c.compareTo(max) > 0)
			max = c; 

		return max; 
	}
	
}

class Boo implements Comparable<Boo> {

	String booLevel;
	int booRank;
	
	public Boo (String bl, int br) {
		booLevel = bl;
		booRank = br;
	}
	
	@Override
	public int compareTo (Boo otherBoo) {
		if (this.booRank == otherBoo.booRank)
			return this.booLevel.compareTo(otherBoo.booLevel);
		return this.booRank - otherBoo.booRank;
	}
	
	@Override
	public String toString () {
		return "Boo (\"" + this.booLevel + "\", " + this.booRank + ")";
	}

}

public class LargestTest {

	public static void main(String args[]) {
	
		System.out.println("\n\tLargest (12, 31, 23) = " + Largest.largest(12, 31, 23));
		System.out.println("\n\tLargest (4.5, 6.4, 5.6) = " + Largest.largest(4.5, 6.4, 5.6));
		System.out.println("\n\tLargest (\"Milky Way\", \"Observable Universe\", \"Your Mom\") = \"" + Largest.largest("Milky Way", "Observable Universe", "Your Mom") + "\"");
		System.out.println("\n\tLargest (Boo(\"BOO!\", 12), Boo(\"Boo!\", 12), Boo(\"BOO!\", 16)) = " + Largest.largest(new Boo("BOO!", 12), new Boo("Boo!", 12), new Boo("BOO!", 16)));
		System.out.println();
		
	}

}
