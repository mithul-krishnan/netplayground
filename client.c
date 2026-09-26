#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in serverAddr;
    char buffer[1024] = {0};

    WSAStartup(MAKEWORD(2,2), &wsa);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    char *msg = "Check matrix type";
    send(sock, msg, strlen(msg), 0);

    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server response: %s\n", buffer);

    closesocket(sock);
    WSACleanup();
    return 0;
}
