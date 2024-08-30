#include<t_stdio.h>
#include<t_file.h>

int cp_file(int s_fd, int d_fd)
{
	int total = 0;//记录世纪拷贝的字节数
	int r, w;
	char buf[128];
	while(r = read(s_fd, buf, 128) > 0)
	{
		char *tmp = buf;
		while(r > 0)
		{
			w = write(d_fd, tmp, r);//w代表实际写入到目标文件的字节数
			r = r-w;
			total += w;
			tmp += w;
		}
	}
	return total;
}

//	通过命令行传递文件的名字
//	argv[1] 源文件名字
//	argv[2]	目标文件名字
int main(int argc, char *argv[])
{
	int src_fd = open(argv[1], O_RDONLY);
	int flags = O_WRONLY | O_CREAT | O_TRUNC;
	int mod = 0644;
	int dst_fd = open(argv[2], flags, mod);
	if(src_fd == -1|dst_fd == -1) E_MSG("open", -1);
	

	close(src_fd);
	close(dst_fd);
	return 0;
}

