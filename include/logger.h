#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
public:
    void logRequest(
        const std::string& method,
        const std::string& path
    );
};

#endif