// NestStrUnion.c
// Created by @avikantz on 08/11/15

#include <stdio.h>

int main(int argc, const char * argv[]) {
	printf("This program will convert a decimal number into any base from 2-32 using a gorram array.\n");
	
	const char baseDigits[32] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
	int convertedNumber[128];
	long int numberToConvert, numberToConvertCopy;
	int nextDigit, base, index = 0;
	
	printf ("\tNumber to be converted: ");
	scanf ("%ld", &numberToConvert);
	printf ("\tBase (2-32): ");
	scanf ("%i", &base);
	
	numberToConvertCopy = numberToConvert;
	
	if (base < 2 || base > 32) {
		printf ("Error, invalid base.\n\n");
		return 6;
	}
	
	do {
		convertedNumber[index] = numberToConvert % base; ++index;
		numberToConvert = numberToConvert / base;
	}
	while ( numberToConvert != 0 );
	
	printf ("\n\t %ld|10 = ", numberToConvertCopy);
	for (--index; index >= 0; --index ) {
		nextDigit = convertedNumber[index];
		printf ("%c", baseDigits[nextDigit]);
	}
	printf ("|%d\n\n", base); return 0;
}
