#include<t_stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int fd = socket(PF_INET, SOCK_STREAM, 0);
	if(fd == -1) E_MSG("socket..", -1);

	struct sockaddr_in serv;	
	serv.sin_family = PF_INET;
	serv.sin_port = htons(5566);
	// 127.0.0.1 text -> binary
	// const char *inet_ntop(int af, const void * restrict src, char * restrict dst,socklen_t size);
	inet_pton(PF_INET, "127.0.0.1", &serv.sin_addr);// 将转换后的地址保存到serv.sin_addr中
	int c = connect(fd, (struct sockaddr *)&serv, sizeof(serv));
	if(c == -1) E_MSG("connect...", -1);
	//三次握手完成
	//向服务器发送请求信
	char * msg = "this is test..\n";
	printf("%s\n", msg);
	write(fd, msg, strlen(msg)+1);//保护\0
	//堵塞等待服务器的回应
	char buf[128]= {};
	int i  = read(fd, buf, 128);	
	//将响应信息输出到显示器
	write(1, buf, 128);
	//关闭本次连接
	close(fd);
	return 0;
}
