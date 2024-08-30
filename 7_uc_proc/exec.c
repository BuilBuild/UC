#include<t_stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	char *ps_argv[] = {"ps", "-o", "pid, ppid,pgid,comm", NULL};
	//创建子进程
	pid_t pid = fork();
	if(pid == -1) E_MSG("fork...", -1);
	if(pid == 0){
		printf("child process...%d\n", getpid());
		//更新进程映像
		//execlp("ps", "ps", "-o", "pid, ppid,pgid,comm", NULL);
		execvp("ps", ps_argv);
		//execlp("/bin/ps", "ps", "-o", "pid, ppid,pgrp,comm", NULL);
		//只有exec 家族函数执行失败的时候才会执行以下代码
		perror("execlp...");
		exit(0);
	}else{
		//等待回收子进程资源
		wait(NULL);
	}


	return 0;

}
