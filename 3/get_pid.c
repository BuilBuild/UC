#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{	
	printf("the pid is: %d\n", getpid());
	getchar();
	return 0;
}
