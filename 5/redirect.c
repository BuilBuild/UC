#include<t_stdio.h>
#include<t_file.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char *msg = "this is test\n";
	int flags = O_WRONLY | O_CREAT | O_TRUNC;
	int mod = 0644;
	int fd = open(argv[1], flags, mod);// fd : 3
	if(fd == -1) E_MSG("open", -1);
	// 将标准输出的文件描述符复制一份到最小的未有描述符的位置
	int s_fd = dup(1);// s_fd : 4
	// 将打开的文件的文件描述符复制到标准输
	dup2(fd, 1);// 此时打开文件的的文件描述符增加一次引用记录 2
	close(fd);// 关闭打开文件的描述符 3号位置上的记录 只剩下1号位置上的记录
	write(1, msg, strlen(msg));// 向1位置上的文件描述符进行写入，也就是向文件写入
	dup2(s_fd, 1);// 将4号位置上的文件描述符复制到1号位上，此时打开文件的文件描述符计数变为0，自动销毁
	close(s_fd);//关闭4号位置上的文件描述符，标准输出的文件描述符引用计数由2减1
	write(1, msg, strlen(msg));//向标准输出输出
	return 0;
}

