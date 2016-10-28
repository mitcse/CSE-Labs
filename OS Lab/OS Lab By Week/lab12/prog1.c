#include <stdio.h>

int check(int mem[], int s, int end)
{
	int i = 0;
	for(i = s; i < end; i++)
	{
		if(mem[i] != -1)
			return 0;
	}
	return 1;
}

void compaction(int *mem, int no_blocks)
{
	int cpy[no_blocks], i, counter = 0;
	
	for(i = 0; i < no_blocks; i++)
		cpy[i] = -1;
	
	for(i = 0; i < no_blocks; i++)
		if(mem[i] != -1)
			cpy[counter++] = mem[i];

	for(i = 0; i < counter; i++)
		mem[i] = cpy[i];
}

void assign(int * mem, int s, int end, int val, int no_blocks)
{
	int i;
	for(i = s; i < end; i++)
		mem[i] = val;
	compaction(mem, no_blocks);
}

void delete(int *mem, int val, int no_blocks)
{
	int i;
	for(i = 0; i < no_blocks; i++)
		if(mem[i] == val)
			mem[i] = -1;
	compaction(mem, no_blocks);
}

int main()
{
	int no_blocks;
	
	printf("Enter the number of blocks: ");
	scanf("%d", &no_blocks);
	
	int mem[no_blocks];
	
	int i;
	for(i = 0; i < no_blocks; i++)
		mem[i] = -1;
	
	int counter = 1;
	while(1)
	{
		int x, flag = 1;
		int s, len;
		int no;
		printf("What would you like to do?\n1.Insert\n2.Delete\n3.Display\n4.Exit\n-");
		scanf("%d", &x);
		
		switch(x)
		{
			case 1:
					printf("Enter the start and the length for %d: ", counter);
					scanf("%d %d", &s, &len);
					s--;
					if(check(mem, s, s + len) && s + len < no_blocks)
						assign(mem, s, s + len, counter, no_blocks);
					else
						printf("Clash! %d not assigned.\n", counter);
					counter++;
					break;
			case 2:
					printf("Enter the file you want to delete: ");
					scanf("%d", &no);
					delete(mem, no, no_blocks);
			case 3:
					printf("The memory looks like:\n");
					for(i = 0; ; i++)
					{
						if(mem[i] == -1)
							break;
						printf("%d ", mem[i]);
					}
					printf("\n");
					break;
			default:
					flag = 0;
					break;
		}
		if(!flag)
			break;
	}
	return 0;
}
