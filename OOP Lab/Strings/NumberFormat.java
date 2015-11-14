//
//  NumberFormat.c
//  Number Formatter
//
//  Created by Avikant Saini on 8/31/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

import java.util.*;
public class NumberFormat {
	static String addCommas (String string) {
		int k = 0;
		String newString = "";
		for (int i = string.length() - 1; i >= 0; --i) {
			char z = string.charAt(i);
			if ( (++k) % 3 == 0 && i > 0)
				newString = "," + z + newString;
			else
				newString = z + newString;
		}
		return newString;
	}
	public static void main (String args[]) {
		Scanner sc = new Scanner (System.in);
		System.out.print("\n\tEnter a number: ");
		String string = sc.nextLine();
		System.out.println("\n\tOriginal: " + string + "\n\tModified: " + addCommas(string));
	}
}