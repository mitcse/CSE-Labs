#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int fibo(int num)
{
	if(num == 0)
		return 0;
	if(num == 1)
		return 1;
	return fibo(num-1) + fibo(num-2);
}

int prime(int num)
{
	int i, flag = 0;
	if(num == 0 || num == 1)
		return -1;
	for(i = 2; i < num/2; i++)
	{
		if(num % i == 0)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
		return -1;
	else
		return 1;
}

int main()
{
	int fd[2];
	pid_t pid;
	int i, flag;
	int fib[25], f[25];
	pipe(fd);
	pid = fork();
	if(pid == 0)
	{
		close(fd[1]);
		read(fd[0], f, 200);
		printf("Result\n");
		for(i = 0; i < 25; i++)
		{
			flag = prime(f[i]);
			if(flag != -1)
			{
				fprintf(stdout, "%d\n", f[i]);
			}			
		}	
		close(fd[0]);
		exit(1);	
	}
	else
	{
		close(fd[0]);
		for(i = 0; i < 25; i++)
		{
			fib[i] = fibo(i);
		}
		write(fd[1], fib, sizeof(fib));
		wait(NULL);
		close(fd[1]);
	}
	return 0;
}
