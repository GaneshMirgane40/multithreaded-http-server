#include "file_handler.h"

#include <fstream>
#include <sstream>

std::string FileHandler::readFile(
    const std::string& filepath
)
{
    std::ifstream file(filepath);

    if(!file.is_open())
    {
        return "";
    }

    std::stringstream buffer;

    buffer << file.rdbuf();

    return buffer.str();
}