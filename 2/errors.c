//#include<stdio.h>
#include<t_stdio.h>
#define D 1 

#if !D
#include<sys/errno.h>
#include<string.h>
#endif

int main(int argc, char *argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
#if !D
		printf("fopen %s failed, the error number is %d\n", argv[1], errno);
		printf("fopen %s failed, the reason of error is %s\n", argv[1], strerror(errno));//in the string lib
#endif
//		perror("fopen\n");
		E_MSG("fopen...\n", -1);
	}
	printf("open %s success\n", argv[1]);
	fclose(fp);
	return 0;
}
