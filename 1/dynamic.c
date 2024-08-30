#include<stdio.h>
#include <dlfcn.h>

typedef int (*fc)(int, int);

int main(int argc, char *argv[])
{
	void *handle = dlopen(argv[1], RTLD_NOW);
	if(handle == NULL)
	{
		printf("load error....%s\n", dlerror());
		return -1;
	}
	fc f = (fc)dlsym(handle, "t_add");
	
	printf("load success\n");
	if(f != NULL)
		printf("3 + 4 = %d\n", f(3,4));
	else
		printf("add error\n");
	dlclose(handle);
	return 0;
}
