#ifndef SERVER_H
#define SERVER_H

class BasicServer
{
private:
    int server_socket;
    int port;

public:
    explicit BasicServer(int port);

    bool start();

    void run();

    void handleClient(
        int client_socket
    );
};

#endif