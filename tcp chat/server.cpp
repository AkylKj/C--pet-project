#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdio>
#include <arpa/inet.h>

using namespace std;

int main(){

    // TCP socket creation
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    // setting address for the server
    sockaddr_in address{};

    address.sin_family = AF_INET;
    address.sin_port = htons(5555);
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);

    

    
}