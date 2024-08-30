#include<t_stdio.h>
#include<sys/mman.h>
#include<string.h>

int main(void)
{
	int prot = PROT_READ | PROT_WRITE;
	int flags = MAP_PRIVATE | MAP_ANONYMOUS;
	int fd = -1;
	int offset = 0; 
	int map_size = 1024;
	void *p = mmap(NULL, map_size, prot, flags, fd, offset);
	if(p == MAP_FAILED) E_MSG("map faild..", -1);
	strcpy(p, "hello beijing");
	printf("the region value is: %s\n", (char *)p);
	munmap(p, map_size);
	return 0;
}
