#include "server.h"
#include "thread_pool.h"

#include <iostream>

int main()
{
    ThreadPool pool(4);

    pool.enqueue(
        []()
        {
            std::cout
                << "Task 1 executed"
                << std::endl;
        }
    );

    pool.enqueue(
        []()
        {
            std::cout
                << "Task 2 executed"
                << std::endl;
        }
    );

    BasicServer server(8080);

    if(!server.start())
    {
        return 1;
    }

    server.run();

    return 0;
}