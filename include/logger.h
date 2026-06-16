#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <mutex>

class Logger
{
private:
    static std::mutex logMutex;

public:
    void logRequest(
        const std::string& method,
        const std::string& path
    );
};

#endif