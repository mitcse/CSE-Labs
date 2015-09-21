package p1;
import java.util.Scanner;
public class Max
{
	int max(int a,int b,int c)
	{
		if (a>b && a>c)
			return a;
		else if (b>c && b>a)
			return b;
		else 
			return c;
	}
	float max (float a,float b ,float c)
	{
		if (a>b && a>c)
			return a;
		else if (b>c && b>a)
			return b;
		else 
			return c;
	}
	int max(int a[],int no)
	{
		int i, largest = a[0];
		for(i=0;i<no;i++)
		{
			if(a[i]>largest)
			{
				largest = a[i];
			}
		}
		return largest;
	}
	int max(int a[][],int noro,int noco)
	{
		int i,j,largest=a[0][0];
		for(i=0;i<noro;i++)
		{
			for(j=0;j<noco;j++)
			{
				if(a[i][j] > largest) 
					largest = a[i][j];
			}
		}
		return largest;
	}
}

