#include<t_stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int flags = O_WRONLY | O_CREAT | O_TRUNC;
	int mod = 0644;
	int fd = open(argv[1], flags, mod);
	if (fd == -1)E_MSG("open",-1);
	
	printf("open success\n");
	close(fd);
	
	
	return 0;
}
