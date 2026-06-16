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
    if(path == "/style.css")
{
    return "../public/style.css";
}

    return "../public/404.html";
}