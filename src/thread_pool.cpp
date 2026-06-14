#include "thread_pool.h"

#include <iostream>

ThreadPool::ThreadPool(
    size_t numThreads
)
{
    for(size_t i = 0; i < numThreads; i++)
    {
        workers.emplace_back(
            [i]()
            {
                std::cout
                    << "Worker "
                    << i
                    << " started\n";
            }
        );
    }
}

ThreadPool::~ThreadPool()
{
    for(auto& worker : workers)
    {
        if(worker.joinable())
        {
            worker.join();
        }
    }
}