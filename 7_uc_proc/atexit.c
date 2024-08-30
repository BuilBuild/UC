#include<t_stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
int atexit(void (*function)(void));
int on_exit(void(*function(int, void *)), void *arg);
*/
void goodbye(void)
{
	pid_t pid = getpid();
	printf("good  bye....%d\n", pid);
	return;
}

void bye(void)
{
	pid_t pid = getpid();
	printf("bye bye....%d\n", pid);
	return;
}


int main()
{
	pid_t pid = getpid();
	atexit(bye);
	atexit(bye);
	atexit(goodbye);
	pid_t p = fork();
	if(p == -1) E_MSG("fork ..", -1);
	if(p == 0){
		printf("child process....%d\n", getpid());
	}else{
		printf("parent process....%d\n", getpid());

	}
	getchar();
	exit(1);
}
