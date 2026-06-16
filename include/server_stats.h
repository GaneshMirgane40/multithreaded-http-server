#ifndef SERVER_STATS_H
#define SERVER_STATS_H

#include <mutex>

class ServerStats
{
private:
    int totalRequests;
    int successfulRequests;
    int notFoundRequests;

    std::mutex statsMutex;

public:
    ServerStats();

    void incrementTotal();

    void incrementSuccess();

    void incrementNotFound();

    int getTotal();

    int getSuccess();

    int getNotFound();
};

#endif