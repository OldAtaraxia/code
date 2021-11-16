#include <stdio.h>

typedef unsigned short int sa_family_t;

struct sockaddr {
    sa_family_t sa_family;
    char sa_data[14];
};

typedef uint32_t in_addr_t;
struct in_addr {
    in_addr_t s_addr;
};

struct sockaddr_in {
    sa_family_t sin_family;
    in_port_t sin_port;
    struct in_addr sin_addr;

    unsigned char sin_zero[8];
};

struct sockaddr_in6 {
    sa_family_t sin6_family; //16-bit
    in_port_t sin6_port; // 传输端口号
    uint32_t sin6_flowinfo; // IPv6流控信息 32-bit
    struct in6_addr sin6_addr; // IPv6地址 128-bit
    uint32_t sin6_scope_id; // IPv6域ID 32-bit
};

struct sockaddr_un {
    unsigned short sun_family; // AF_LOCAL
    char sun_path[108]; // 路径名
};