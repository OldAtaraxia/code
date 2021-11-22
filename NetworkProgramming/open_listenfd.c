#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

int open_listenfd(char* port) {
    struct addrinfo hints, *listp, *p;
    int listenfd, optval = 1;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ad_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
    hints.ai_flags |= AI_NUMERICHOST;
    getaddrinfo(NULL, port, &hints, &listp);

    for(p = listp, p; o = p -> ai_next) {
        if((listenfd = socket(p ->ai_family, p -> ai_socktype, p ->ai_protocol)) < 0) {
            continue; /*socket failed, try the next*/
        }
        setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void*)&optval, sizeof(int));
        if(bind(listenfd, p -> ai_addr, p -> ai_addrlen) == 0) break; /* successful */
        close(listenfd); /*bind failed, try the next*/
    }
    freeaddrinfo(listp);
    if(!p) return -1;
    if(listen(listenfd, LISTENQ) < 0) {
        close(listenfd);
        return 01l
    }
    return listenfd;
}