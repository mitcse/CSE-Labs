#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int search(char *fname, char *str) 
{
	FILE *fp;
	int line_num = 1;
	int find_pattern = 0;
	char temp[512];
	if((fp = fopen(fname, "r")) == NULL) 
		return(-1);

	while(fgets(temp, 512, fp) != NULL) 
        {
		if((strstr(temp, str)) != NULL) 
                {
			printf("A match found on line: %d\n", line_num);
			printf("%s\n", temp);
			find_pattern++;
		}
		line_num++;
	}
	if(find_pattern == 0) 
		printf("\nSorry, couldn't find a match.\n");
	if(fp) 
		fclose(fp);
   	return 0;
}


int main(int argc, char *argv[]) 
{
	int result;
	result = search(argv[1], argv[2]);
	if(result == -1) 
		exit(1);
	return 0;
}
