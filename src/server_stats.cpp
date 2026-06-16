#include "server_stats.h"

ServerStats::ServerStats()
    : totalRequests(0),
      successfulRequests(0),
      notFoundRequests(0)
{
}

void ServerStats::incrementTotal()
{
    std::lock_guard<std::mutex>
        lock(statsMutex);

    totalRequests++;
}

void ServerStats::incrementSuccess()
{
    std::lock_guard<std::mutex>
        lock(statsMutex);

    successfulRequests++;
}

void ServerStats::incrementNotFound()
{
    std::lock_guard<std::mutex>
        lock(statsMutex);

    notFoundRequests++;
}

int ServerStats::getTotal()
{
    std::lock_guard<std::mutex>
        lock(statsMutex);

    return totalRequests;
}

int ServerStats::getSuccess()
{
    std::lock_guard<std::mutex>
        lock(statsMutex);

    return successfulRequests;
}

int ServerStats::getNotFound()
{
    std::lock_guard<std::mutex>
        lock(statsMutex);

    return notFoundRequests;
}