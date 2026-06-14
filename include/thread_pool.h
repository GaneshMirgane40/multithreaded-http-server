#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <thread>

class ThreadPool
{
private:
    std::vector<std::thread> workers;

public:
    ThreadPool(size_t numThreads);
    ~ThreadPool();
};

#endif