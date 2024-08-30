#include<t_stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)E_MSG("open",-1);
	
	printf("open success\n");
	close(fd);
	
	
	return 0;
}
