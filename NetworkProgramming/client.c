#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define SERV_PORT 12345

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
    return (n - nleft);

    
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    if(argc != 2) {
        err_quit("usage: client <IPaddress>");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr));
    send_data(stdin, sockfd);
    exit(0);
    
}

#define MESSAGE_SIZE 1024000
void send_data(FILE* fp, int sockfd) {
    // 初始化一个长度为MESSAGE_SIZE的字符串流
    char* query;
    query = malloc(MESSAGE_SIZE + 1);
    for(int i = 0; i < MESSAGE_SIZE; i++) {
        query[i] = 'a';
    }
    query[MESSAGE_SIZE] = '\0';

    // 调用send函数来发送数据
    const char* cp = query; //指示当前发送到了哪里
    remaining = strlen(query);
    while (remaining) {
        n_written = send(sockfd, cp, remaining, 0);
        fprintf(stdout, "send into buffer %ld\n", n_written);
        if(n_written <= 0) {
            perror("send");
            return;
        }
        remaining -= n_written;
        cp += n_written;
    }
    
}