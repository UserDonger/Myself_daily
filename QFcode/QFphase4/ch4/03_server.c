#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#define N 128

// 可以实现单次的通信
int main(int argc, char const* argv[])
{
    if(argc < 3)
    {
        fprintf(stderr, "Usage: %s [ip] [port]\n", argv[0]);
        exit(1);
    }

    //第一步创建套接字
    int sockfd;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("fail to socket");
        exit(1);
    }

    //第二步：将套接字与服务器网络信息结构体绑定
    struct sockaddr_in serveraddr;
    socklen_t addrlen = sizeof(serveraddr);

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    if(bind(sockfd, (struct sockaddr *)&serveraddr, addrlen) == -1)
    {
        perror("fail to bind");
        exit(1);
    }

    //第三步：将套接字设置为被动监听状态
    if(listen(sockfd, 10) == -1)
    {
        perror("fail to listen");
        exit(1);
    }

    //第四步：阻塞等待客户端的链接请求
    int acceptfd;
    struct sockaddr_in clientaddr;
    if ((acceptfd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrlen)) == -1)
    {
        perror("fail to accept");
        exit(1);
    }

    //打印连接的客户端信息
    printf("ip: %s, port:%d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

    //第五步：进行通信
    char buf[N] = "";
    if (recv(acceptfd, buf, N, 0) == -1)//传入的是acceptfd
    {
        perror("fail to recv");
    }

    printf("from client:%s\n", buf);

    strcat(buf, " *_*");
    if(send(acceptfd, buf, N, 0) == -1)
    {
        perror("fail to send");
        exit(1);
    }

    close(sockfd);
    close(acceptfd);

    return 0;
}