#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <string>

class HttpRequest
{
public:
    std::string method;
    std::string path;
    std::string version;

    bool parse(const std::string& rawRequest);
};

#endif