#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

const char* checkMatrix(int n, int mat[n][n]) {
    int upper = 1, lower = 1, diagonal = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i < j && mat[i][j] != 0) lower = 0;
            if(i > j && mat[i][j] != 0) upper = 0;
            if(i != j && mat[i][j] != 0) diagonal = 0;
        }
    }
    if(diagonal) return "Diagonal Matrix";
    else if(upper) return "Upper Triangular Matrix";
    else if(lower) return "Lower Triangular Matrix";
    else return "Neither upper/lower/diagonal";
}

int main() {
    WSADATA wsa;
    SOCKET server, client;
    struct sockaddr_in serverAddr, clientAddr;
    int addrlen = sizeof(clientAddr);
    char buffer[1024];

    int mat[3][3] = {
        {1, 2, 3},
        {0, 5, 6},
        {0, 0, 9}
    };

    WSAStartup(MAKEWORD(2,2), &wsa);

    server = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080);

    bind(server, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(server, 3);
    printf("Server listening...\n");

    client = accept(server, (struct sockaddr*)&clientAddr, &addrlen);
    recv(client, buffer, sizeof(buffer), 0);
    printf("Client says: %s\n", buffer);

    const char* response = checkMatrix(3, mat);
    send(client, response, strlen(response), 0);
    printf("Matrix check sent to client.\n");

    closesocket(client);
    closesocket(server);
    WSACleanup();
    return 0;
}
