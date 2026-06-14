#include "router.h"

std::string Router::route(const std::string& path)
{
    if(path == "/")
    {
        return "../public/index.html";
    }

    if(path == "/about")
    {
        return "../public/about.html";
    }

    if(path == "/contact")
    {
        return "../public/contact.html";
    }

    return "../public/404.html";
}