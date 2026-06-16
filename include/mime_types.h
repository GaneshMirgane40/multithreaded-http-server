#ifndef MIME_TYPES_H
#define MIME_TYPES_H

#include <string>

class MimeTypes
{
public:
    static std::string getMimeType(
        const std::string& filepath
    );
};

#endif