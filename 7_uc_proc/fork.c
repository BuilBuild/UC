#include<t_stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	if(pid == -1) E_MSG("fork ", -1);
	if(pid == 0)//子进程执行到的代码
	{
		printf("child .... process\n");
	}
	else// 父进程执行的代码
	{
		printf("parent ... process\n");
	}
	// 父进程和子进程都能执行到的代码
	printf("all ok\n");
	return 0;
}
