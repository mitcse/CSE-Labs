#include<stdio.h>
#include<string.h>

typedef struct
{
	char name[20];
	int rollNo;
} STUDENT;

int main()
{
	STUDENT s[100];
	int i, n;
	printf("Enter number of student details you want\n");
	scanf("%d", &n);
	STUDENT temp;
	printf("Enter student names and their respective roll numbers\n");
	for (i=0; i<n; i++)
	{
		scanf("%s",&s[i].name);
		scanf("%d", &s[i].rollNo);
	}
	for (i=0; i<n-1; i++)
	{
		int j;
		for (j=i+1; j<n; j++)
		{
			if (s[i].rollNo > s[j].rollNo)
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
	printf("Students in ascending order of their roll numbers are\n");
	for (i=0; i<n; i++)
	{
		printf("Roll : %d ", s[i].rollNo);
		printf("Name : %s\n", s[i].name);
	}
	return 0;
}
