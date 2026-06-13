#include "router.h"

std::string Router::route(const std::string& path)
{
    if(path == "/")
    {
        return "Welcome to Home Page";
    }

    if(path == "/about")
    {
        return "About Page";
    }

    if(path == "/contact")
    {
        return "Contact Page";
    }

    return "404 Not Found";
}