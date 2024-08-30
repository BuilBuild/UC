#include<stdlib.h>
#include<t_stdio.h>
#include <unistd.h>

int main()
{
	int pid = getpid();
	printf("pid: %d", pid);
	getchar();
	exit(3);

}
