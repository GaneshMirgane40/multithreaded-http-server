#include "logger.h"

#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>

std::mutex Logger::logMutex;

void Logger::logRequest(
    const std::string& method,
    const std::string& path
)
{
    std::lock_guard<std::mutex>
        lock(logMutex);

    std::ofstream logFile(
        "../logs/server.log",
        std::ios::app
    );

    if(!logFile.is_open())
    {
        return;
    }

    auto now =
        std::chrono::system_clock::now();

    std::time_t currentTime =
        std::chrono::system_clock::to_time_t(now);

    logFile
        << std::put_time(
               std::localtime(&currentTime),
               "%Y-%m-%d %H:%M:%S"
           )
        << " "
        << method
        << " "
        << path
        << "\n";
}