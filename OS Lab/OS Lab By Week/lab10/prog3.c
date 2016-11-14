#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	long total_mem, page_size;
	int tot_pages, i, j;

	printf("Enter memory size: ");
	scanf("%ld", &total_mem);

	printf("Enter page size: ");
	scanf("%ld", &page_size);

	tot_pages = total_mem / page_size;

	printf("There are %d pages\n", tot_pages);

	int n_pro;
	printf("Enter number of processes: ");
	scanf("%d", &n_pro);

	int **page_tables = calloc(n_pro, sizeof(int *));
	int assigned = 0;
	for(i = 0; i<n_pro; i++) {
		printf("Enter number of pages for process %d: ", i+1);
		int n_pages;
		
		scanf("%d", &n_pages);
		if(assigned + n_pages > tot_pages) {
			printf("Memory is full!\n");
			break;
		} 
		page_tables[i] = calloc(n_pages, sizeof(int));
		printf("Enter the page numbers: ");
		for(j = 0; j<n_pages; j++) {
			scanf("%d", &page_tables[i][j]);
		}
		assigned += n_pages;
	}

	int ch, phy;
	while(1) {
		printf("1. Get physical memory\n2. Exit\nEnter: ");
		scanf("%d", &ch);
		int pr_no, pg_no, offset;
		switch(ch) {
			case 1:
				
				printf("Enter process no., page no., offset: \n");
				scanf("%d %d %d", &pr_no, &pg_no, &offset);
				phy = page_tables[pr_no - 1][pg_no] * page_size + offset;
				printf("physical address is: %d\n", phy);
				break;
			case 2:
				exit(1);
		}
	}

	return 0;
}
