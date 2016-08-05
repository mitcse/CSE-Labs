// Simulate ls

#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <dirent.h>   // for directory commands 

void lsperdir(); 
int main() 
{ 
    char *current_direct = NULL; 
    DIR *dp = NULL; 
    struct dirent *dptr = NULL; 
    unsigned int count = 0; 
  
    current_direct = getenv("PWD"); 
    if(NULL == current_direct) 
    { 
        printf("Cannot get working directory\n"); 
        return -1; 
    } 
  
    dp = opendir((const char*)current_direct); 
    if(NULL == dp) 
    { 
        printf("Cannot open working directory\n"); 
        return -1; 
    } 
 
    printf("\n");
    // print files but not ones starting with '.' 
    for(count = 0; NULL != (dptr = readdir(dp)); count++) 
    { 
        if(dptr->d_name[0] != '.') 
            printf("%s\n",dptr->d_name); 
    } 
    lsperdir();
    return 0; 
}

// ls for particular entered directory
void lsperdir()
{
    char dirname[100];
    DIR *p;
    struct dirent *d;
    printf("Enter path of directory\n");
    scanf(" %s", dirname);
    p=opendir(dirname);
    if (p==NULL)
    {
        printf("Cannot find directory\n");
        exit(0);
    }
    while (d=readdir(p))
        printf("%s\n", d->d_name);
}
