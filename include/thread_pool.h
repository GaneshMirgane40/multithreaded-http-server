#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool
{
private:
    std::vector<std::thread> workers;

    std::queue<std::function<void()>> tasks;

    std::mutex queueMutex;

    std::condition_variable condition;

    bool stop;

public:
    ThreadPool(size_t numThreads);

    ~ThreadPool();

    void enqueue(
        std::function<void()> task
    );
};

#endif