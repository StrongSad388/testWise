#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <netinet/in.h>
#include <errno.h>
#define MAXLINE 80

int startServer(int port, int protocol) {
    printf("Starting server on port %d\n", port);
    int s = socket(AF_INET, protocol, 0);
    struct sockaddr_in in;
    struct sockaddr_in client_in;
    bzero((void *)&client_in, sizeof(struct sockaddr_in));
    bzero((void *)&in, sizeof(struct sockaddr_in));
    in.sin_port = htons(port);
    in.sin_family = AF_INET;
    // sin_addr.s_addr and sin_zero are left at zero
    if (bind(s, (struct sockaddr *)&in, sizeof(struct sockaddr)) < 0) {
        fprintf(stderr, "bind(): %d\n", errno);
        return -1;
    }    
    if (listen(s, 1) < 0) {
        fprintf(stderr, "listen(): %d\n", errno);
        return -1;
    }
    // accept
    int caddr_len = sizeof(struct sockaddr_in);
    int serverSocket = accept(s, (struct sockaddr *)&client_in, (socklen_t *)&caddr_len);
    if (serverSocket < 0) {
        fprintf(stderr, "accept(): %d\n", errno);
        return -1;
    }

    int total = 0;
    int count = 0;
    do {
        char buffer[MAXLINE];
        bzero((char *)&buffer, MAXLINE);
        if ((count = recvfrom(serverSocket, &buffer, MAXLINE, 0, NULL, NULL)) < 0) {
            fprintf(stderr, "recv(): %d, count = %d\n", errno, count);
            return -1;
        }
        total += count;
    } while (count > 0);
    printf("Total: %d\n", total);
    return 0;
}

int getInAddr(char * host) {
    return 0x7f000001;
}

int startClient(char *host, int port, int protocol) {
    printf("Starting client on host %s and port %d\n", host, port);
    // open socket
    int s = socket(AF_INET, protocol, 0);
    unsigned long s_addr;
    struct sockaddr_in in;
    bzero((void *)&in, sizeof(struct sockaddr_in));
    in.sin_port = htons(port);
    in.sin_family = AF_INET;
    if ((s_addr = getInAddr(host)) < 0) {
        fprintf(stderr, "failed to resolve %s\n", host);
        return -1;
    }
    in.sin_addr.s_addr = htonl(s_addr);

    // connect
    int rc = connect(s, (struct sockaddr *)&in, sizeof(struct sockaddr));
    if (rc < 0) {
        fprintf(stderr, "connect(): %d\n", errno);
        return -1;
    }

    int inCount = 0;
    char buffer[512];
    while (EOF != scanf("%s", buffer)) {
        send(s, buffer, strnlen(buffer, 512), 0);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <server|client> [host] <port> [udp|tcp] \n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "server") == 0) {
        if (argc < 3) {
            printf("Usage: %s server <port>\n", argv[0]);
            return 1;
        }
        int port = atoi(argv[2]);
        return startServer(port, SOCK_STREAM);
    } else if (strcmp(argv[1], "client") == 0) {
        if (argc < 4) {
            printf("Usage: %s client <host> <port>\n", argv[0]);
            return 1;
        }
        char *host = argv[2];
        int port = atoi(argv[3]);
        return startClient(host, port, SOCK_STREAM);
    } else {
        printf("Usage: %s <server|client> [host] <port>\n", argv[0]);
        return 1;
    }
    return 0;
}