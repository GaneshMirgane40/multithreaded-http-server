#ifndef SERVER_H
#define SERVER_H
#include "thread_pool.h"

class BasicServer
{
private:
    int server_socket;
    int port;

    ThreadPool threadPool;

public:
    explicit BasicServer(int port);

    bool start();

    void run();

    void handleClient(
        int client_socket
    );
};

#endif