//
//	Max.java
//	Defined in package p1
//
//


package p1;

import java.util.Scanner;

public class Max {
	
	int max (int a, int b, int c) {
		return (a>b)?((a>c)?a:c):((b>c)?b:c);
	}

	float max (float a, float b, float c) {
		return (a>b)?((a>c)?a:c):((b>c)?b:c);
	}

	int max (int a[]) {
		int max = 0;
		for (int i : a)
			if (i > max)
				max = i;
		return max;
	}

	int max(int a[][]) {
		int max = 0;
		for (int b[] : a)
			for (int i : b)
				if (i > max)
					max = i;
		return max;
	}

}

