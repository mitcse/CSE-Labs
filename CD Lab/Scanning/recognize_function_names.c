#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

	char filename1[100], filename2[100], c1, c2;

	char *keywords[8] = {"double", "int", "long", "char", "float", "short", "unsigned", "void"};

 	printf("Enter the first filename:\n> ");
 	scanf("%s",filename1);
	FILE *fp1 = fopen(filename1, "r");

	if (fp1 == NULL) {
	 	printf("File cant be open %s\n", filename1);
	 	exit(0);
	}

	int i = 0, k = 0, j = 0;
	char return_type[50];
	char temp[50];

	// Recognize: "return_type function_name (" for successful parsing of function name.

	for (c1 = fgetc(fp1) ;c1 != EOF;c1 = fgetc(fp1)) {
		memset(return_type, '\0', sizeof(char)*50);
		memset(temp, '\0', sizeof(char)*50);
		k = 0;
		j = 0;
		while((c1 >= 'A' && c1 <= 'Z') || ( c1 >= 'a' && c1 <= 'z')) {
			return_type[j++] = c1;
			c1 = fgetc(fp1);
		}
		
		if(c1 == ' ') {
			
			int flag = 0;
			for (i = 0; i < 8; i++) {
				if (strcmp(return_type, keywords[i]) == 0) {
					flag = 1;
					break;
				}
			}
			if(flag == 1) {
		
				c1 = fgetc(fp1);
				while((c1 >= 'A' && c1 <= 'Z') || ( c1 >= 'a' && c1 <= 'z')) {
					temp[k++] = c1;
					c1 = fgetc(fp1);
				}
				while(c1 == ' ') {
					c1 = fgetc(fp1);
				}

				if(c1 == '(') {
					for(i = 0; i < k; i++) {
						printf("%c", temp[i]);
					} printf("\n");
				}

			}
		}
	}

	

	return 0;
}
