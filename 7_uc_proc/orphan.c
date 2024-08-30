#include<t_stdio.h>
#include <unistd.h>
#include<sys/types.h>

int main()
{
	pid_t pid = fork();
	if(pid == -1) E_MSG("fork...", -1);
	if(pid == 0){
		printf("parent of child pid: %d\n", getppid());
		printf("child pid: %d\n", getpid());
		sleep(10);
		printf("in child code wait... parent of child pid: %d\n", getppid());
	}else{
		sleep(1);
		printf("in parent code parent process pid: %d\n", getpid());
	
	}

	return 0;
}
