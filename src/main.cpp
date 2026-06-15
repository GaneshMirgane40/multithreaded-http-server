#include "server.h"
#include "thread_pool.h"

#include <iostream>

int main()
{
   

    
    BasicServer server(8080);

    if(!server.start())
    {
        return 1;
    }

    server.run();

    return 0;
}