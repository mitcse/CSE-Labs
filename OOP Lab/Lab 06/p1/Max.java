package p1;
import java.util.Scanner;
public class Max {
	int max(int a,int b,int c) {
		if (a>b && a>c)
			return a;
		else if (b>c && b>a)
			return b;
		else 
			return c;
		}
	float max (float a,float b ,float c) {
		if (a>b && a>c)
			return a;
		else if (b>c && b>a)
			return b;
		else 
			return c;
	}
	int max(int a[],int no) {
		int i,largest=a[0];
		for(i=0;i<no-1;i++) {
			if(a[i]<a[i+1]) {
				largest = a[i+1];
			}
		}
	return largest;
	}
	int max(int a[][],int noro,int noco) {
		int i,j,largest=a[0][0];
		for(i=0;i<noro;i++) 
			for(j=0;j<noco;j++) 
				if(largest < a[i][j]) 
					largest = a[i][j];
		return largest;
	}
}

