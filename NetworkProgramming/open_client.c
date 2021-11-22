int open_clientfd(char* hostname, char* port) {
    int clientfd;
    struct addrinfo hints, *listp, *p;

    /* 得到potential server addresses的列表 */
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hint.ai_flags = AI_ANUMERICSErV | AI_ADDRCONFIG;
    getaddrinfo(hostname, port, &hints, &listp);

    for(p = listp; p; p = p -> ai_next) {
        if((clientfd = socket(p ->ai_family, p -> ai_socktype, p -> ai_protocol)) < 0) {
            continue;
        }

        if(connect(clientfd, p -> ai_addr, p -> ai_addrlen) != -1) {
            // connect successfully
            break;
        }
        close(clientfd);
    }
    freeaddrinfo(listp);
    if(!p) {
        // connect failed   
        return -1;
    } else {
        return clientfd;
    }
}