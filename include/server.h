#ifndef SERVER_H
#define SERVER_H
#include "thread_pool.h"
#include "server_stats.h"
#include <string>

class BasicServer
{
private:
    int server_socket;
    int port;

    ThreadPool threadPool;
    ServerStats stats;

public:
    explicit BasicServer(int port);

    bool start();

    void run();

    void handleClient(
        int client_socket
    );
    std::string generateStatsPage();
};

#endif