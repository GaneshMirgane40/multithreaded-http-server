#include "server.h"
#include "thread_pool.h"

int main()
{
    ThreadPool pool(4);
    BasicServer server(8080);

    if(!server.start())
    {
        return 1;
    }

    server.run();
    

    return 0;
}