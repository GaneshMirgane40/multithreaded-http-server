#include "config.h"

#include <fstream>
#include <string>

Config::Config()
    : port(8080),
      threads(4)
{
}

bool Config::load(
    const std::string& filepath
)
{
    std::ifstream file(filepath);

    if(!file.is_open())
    {
        return false;
    }

    std::string line;

    while(std::getline(file, line))
    {
        if(line.find("PORT=") == 0)
        {
            port =
                std::stoi(
                    line.substr(5)
                );
        }

        if(line.find("THREADS=") == 0)
        {
            threads =
                std::stoi(
                    line.substr(8)
                );
        }
    }

    return true;
}

int Config::getPort() const
{
    return port;
}

int Config::getThreads() const
{
    return threads;
}