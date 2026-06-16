#include "mime_types.h"

std::string MimeTypes::getMimeType(
    const std::string& filepath
)
{
    if(
        filepath.size() >= 5
        &&
        filepath.substr(
            filepath.size() - 5
        ) == ".html"
    )
    {
        return "text/html";
    }

    if(
        filepath.size() >= 4
        &&
        filepath.substr(
            filepath.size() - 4
        ) == ".css"
    )
    {
        return "text/css";
    }

    if(
        filepath.size() >= 3
        &&
        filepath.substr(
            filepath.size() - 3
        ) == ".js"
    )
    {
        return "application/javascript";
    }

    return "text/plain";
}