#include "http_request.h"

#include <sstream>

bool HttpRequest::parse(const std::string& rawRequest)
{
    std::istringstream stream(rawRequest);

    stream >> method
           >> path
           >> version;

    return !method.empty()
        && !path.empty()
        && !version.empty();
}