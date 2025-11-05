#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8888

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *response = "Hello from server";

    // 建立 socket 檔案描述符
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return -1;
    }

    // 設置 socket 選項
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        close(server_fd);
        return -1;
    }

    // 設置位址結構
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // 接受任意位址
    address.sin_port = htons(PORT);

    // 綁定 socket 到指定位址與埠口
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        return -1;
    }

    // 開始監聽連線
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        return -1;
    }

    // Server started listening on port 8888
    printf("Server started listening on port %d\n", PORT);

    // 接受連線
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0) {
        perror("accept");
        close(server_fd);
        return -1;
    }

    // 讀取客戶端發送的資料
    read(new_socket, buffer, 1024);
    printf("Received message from Client: %s\n", buffer);

    // 發送回應給客戶端
    send(new_socket, response, strlen(response), 0);
    printf("Response sent to client\n");

    // 關閉 socket
    close(new_socket);
    close(server_fd);
    return 0;
}