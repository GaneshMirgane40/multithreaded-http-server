#include "server.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include "http_request.h"
BasicServer::BasicServer(int port)
    : server_socket(-1),
      port(port)
{
}

bool BasicServer::start()
{
    server_socket = socket(
        AF_INET,
        SOCK_STREAM,
        0
    );

    if(server_socket < 0)
    {
        std::cerr << "Socket creation failed\n";
        return false;
    }

    std::cout << "Socket created successfully\n";

    sockaddr_in server_addr{};

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if(bind(
            server_socket,
            (sockaddr*)&server_addr,
            sizeof(server_addr)
        ) < 0)
    {
        std::cerr << "Bind failed: "
          << strerror(errno)
          << "\n";
        return false;
    }

    std::cout << "Socket bound to port "
              << port
              << "\n";

   
if(listen(server_socket, 5) < 0)
{
    std::cerr << "Listen failed: "
      << strerror(errno)
      << "\n";
    return false;
}

std::cout << "Listening on port "
          << port
          << "\n";
          return true;
}
void BasicServer::run()
{
    std::cout << "Waiting for clients...\n";

    while(true)
    {
        sockaddr_in client_addr{};
        socklen_t client_len = sizeof(client_addr);

        int client_socket =
            accept(
                server_socket,
                (sockaddr*)&client_addr,
                &client_len
            );

        if(client_socket < 0)
        {
            std::cerr << "Accept failed\n";
            continue;
        }

       std::cout << "New client connected!\n";

char buffer[4096] = {0};

ssize_t bytes_received =
    recv(
        client_socket,
        buffer,
        sizeof(buffer) - 1,
        0
    );
    std::string rawRequest(buffer);

HttpRequest request;

if(bytes_received < 0)
{
    std::cerr << "recv failed\n";
}
else
{
    std::cout
        << "\n===== REQUEST =====\n"
        << buffer
        << "\n===================\n";
}

if(request.parse(rawRequest))
{
    std::cout
        << "\n===== PARSED REQUEST =====\n";

    std::cout
        << "Method: "
        << request.method
        << "\n";

    std::cout
        << "Path: "
        << request.path
        << "\n";

    std::cout
        << "Version: "
        << request.version
        << "\n";

    std::cout
        << "==========================\n";
}


const char* response =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/plain\r\n"
    "Content-Length: 11\r\n"
    "Connection: close\r\n"
    "\r\n"
    "Hello World";

send(
    client_socket,
    response,
    strlen(response),
    0
);

close(client_socket);
    }
}