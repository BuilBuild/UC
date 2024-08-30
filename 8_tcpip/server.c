#include<t_stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char buf[128];
	//创建一个网络通信端点
	int s_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(s_fd == -1) E_MSG("socket...", -1);
	
	//将s_fd和本地的地址和端口号进行绑定
	/*
	int bind(int socket, const struct sockaddr *address, socklen_t address_len);
	*/
	struct sockaddr_in serv;//ipv4 PF_INET
	//对serv的成员变量进行初始化
	serv.sin_family = AF_INET;
	serv.sin_port = htons(5566);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);//所有地址均可访问
	int b = bind(s_fd, (struct sockaddr *)&serv, sizeof(serv));
	if(b == -1) E_MSG("bind...", -1);
	//将s_fd 设置为被动连接，监听客户端的到来
	//将客户端的连接放入到未决连接队列中
	//指定未决连接队列的大小
	if((listen(s_fd, 5 )) == -1) E_MSG("listen...", -1);
	while(1){
		//从s_fd中的未决连接队列中提取一个进行处理
		//返回一个连接描述符，使用这个连接描述符和客户端进行通讯
		//int accept(int socket, struct sockaddr *restrict address,socklen_t *restrict address_len);
		int c_fd = accept(s_fd, NULL, NULL);
		if(c_fd == -1) E_MSG("accept...", -1);//到这里三次握手已经完成，可以进行数据的传输
		//从c_fd中读取客户端发送过来的请求信息
		int r = read(c_fd, buf,128);
		//printf("%s\n", buf);
		//write(1, buf,128);
		//处理客户端的请求信息
		int i;
		for(i = 0; i<r;i++)
			buf[i] = toupper(buf[i]);
		//将处理的结果返回客户端

		write(c_fd, buf, r);
		//关闭本次连接
		close(c_fd);	
	}
	

}
