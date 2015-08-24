// Student.c
// Created by @avikantz on 08/11/15

#include <stdio.h>

typedef struct Student {
	int rollNumber;
	char name[50];
	float cgpa;
} STUDENT_t;

void input(int count, STUDENT_t *s) {
	printf("\n\t%4d. Enter Roll Number: ", count);
	scanf("%d", &s->rollNumber);
	printf("\t%4d. Enter Name: ", count);
	scanf("%s", &s->name);
	printf("\t%4d. Enter CGPA!: ", count);
	scanf("%f", &s->cgpa);
	printf("\n");
}

void print(STUDENT_t *s) {
	printf("\n\t%s\t\t%d\t\t%.1f", s->name, s->rollNumber, s->cgpa);
}

void swap(STUDENT_t *a, STUDENT_t *b) {
	STUDENT_t c = *a;
	*a = *b;
	*b = c;
}

void sort(STUDENT_t a[100], int n) {
	int i, j, min;
	for (i = 0; i < n - 1; ++i) {
		min = i;
		for (j = i + 1; j < n; ++j)
			if (a[j].rollNumber < a[min].rollNumber)
				min = j;
		if (min != i)
			swap(&a[i], &a[min]);
	}
}

int main(int argc, const char *argv[]) {
	int n, i;
	STUDENT_t arr[100];
	printf("\n\tEnter the number of students: ");
	scanf("%d", &n);
	printf("\n");
	for (i = 0; i < n; ++i) {
		printf("Enter Student %d's details:", i+1);
		input(i+1, &arr[i]);
	}
	sort(arr, n);
	printf("\n\tNAME\t\tROLL NO\t\tCGPA\n");
	for (i = 0; i < n; ++i)
		print(&arr[i]);
	printf("\n");
	return 0;
}
