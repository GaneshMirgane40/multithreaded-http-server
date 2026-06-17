#include "server.h"

#include <iostream>
#include <csignal>
#include "config.h"

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
    Config config;

if(
    !config.load(
        "../config/server.config"
    )
)
{
    std::cout
        << "Failed to load config file\n";

    return 1;
}
    std::signal(
        SIGINT,
        signalHandler
    );
BasicServer server(
    config.getPort(),
    config.getThreads()
);

    serverPtr = &server;

    if(!server.start())
    {
        return 1;
    }

    server.run();

    return 0;
}