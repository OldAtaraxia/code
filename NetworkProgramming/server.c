#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>

ssize_t readn(int fd, void* vptr, size_t size);
void read_data(int sockfd);

int main() {
    int listenfd, connfd;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));// 将字符串的前size个字节清零
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // 本机地址
    servaddr.sin_port = htons(12345); // 监听端口

    // bind到本地端口
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(listenfd, 1024);

    // 循环处理用户请求
    for(;;) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen);
        read_data(connfd);
        close(connfd);
    }
}

ssize_t readn(int fd, void* vptr, size_t size) {
    size_t nleft;
    ssize_t nread;
    char* ptr;

    ptr = vptr;
    nleft = size;

    while(nleft > 0) {
        if((nread = read(fd, ptr, nleft)) < 0) {
            if(errno == EINTR) {
                nread = 0; // 再次调用nread
            } else {
                return -1;
            }
        } else if(nread == 0) {
            break; // EOF
        }
        nleft -= nread;
        ptr += nread;
    }
    return (size - nleft);
}


void read_data(int sockfd) {
    ssize_t n;
    char buf[1024];

    int time = 0;
    for(;;) {
        fprintf(stdout, "block in read\n");
        if((n = readn(sockfd, buf, 1024)) == 0) {
            return; // EOF
        }
        time++;
        fprintf(stdout, "1k read for %d\n", time);
        usleep(1000); // 休眠1s, 模拟服务器端处理时延
    }
}


