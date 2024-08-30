#include<t_stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>

int main(void)
{
	int s;
	pid_t pid = fork();
	if(pid == -1) E_MSG("fock...", -1);
	if(pid == 0){//子进程执行代码
		printf("child proceee ...%d\n", getpid());
		getchar();
		exit(55);
	}else{//父进程执行代码
		wait(&s);//父进程堵塞 等待子进程结束
		if(WIFEXITED(s))
			printf("parent processs...%d, exit code(statu): %d\n", getpid(), WIFSIGNALED(s));
		if(WIFSIGNALED(s))
			printf("parent processs...%d, signal code(statu): %d\n", getpid(), WTERMSIG(s));
		
	}

	return 0;
}
