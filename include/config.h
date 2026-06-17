#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config
{
private:
    int port;
    int threads;

public:
    Config();

    bool load(
        const std::string& filepath
    );

    int getPort() const;

    int getThreads() const;
};

#endif