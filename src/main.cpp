#include "server.h"

#include <iostream>
#include <csignal>

BasicServer* serverPtr = nullptr;

void signalHandler(int signal)
{
    std::cout
        << "\nStopping server..."
        << std::endl;

    if(serverPtr)
    {
        serverPtr->stop();
    }
}

int main()
{
    std::signal(
        SIGINT,
        signalHandler
    );

    BasicServer server(8080);

    serverPtr = &server;

    if(!server.start())
    {
        return 1;
    }

    server.run();

    return 0;
}