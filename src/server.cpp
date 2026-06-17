#include "server.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include "http_request.h"
#include "router.h"
#include "file_handler.h"
#include "logger.h"
#include "mime_types.h"

BasicServer::BasicServer(
    int port,
    int numThreads
)
    : server_socket(-1),
      port(port),
      threadPool(numThreads),
      running(true)
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
        std::cerr
            << "Bind failed: "
            << strerror(errno)
            << "\n";

        return false;
    }

    std::cout
        << "Socket bound to port "
        << port
        << "\n";

    if(listen(server_socket, 5) < 0)
    {
        std::cerr
            << "Listen failed: "
            << strerror(errno)
            << "\n";

        return false;
    }

    std::cout
        << "Listening on port "
        << port
        << "\n";

    return true;
}
void BasicServer::stop()
{
    running = false;

    close(server_socket);
}

void BasicServer::run()
{
    std::cout << "Waiting for clients...\n";

    while(running)
    {
        sockaddr_in client_addr{};
        socklen_t client_len =
            sizeof(client_addr);

        int client_socket =
            accept(
                server_socket,
                (sockaddr*)&client_addr,
                &client_len
            );

        if(client_socket < 0)
{
    if(!running)
    {
        break;
    }

    std::cerr
        << "Accept failed\n";

    continue;
}
        std::cout
            << "New client connected!\n";

        threadPool.enqueue(
            [this, client_socket]()
            {
                handleClient(
                    client_socket
                );
            }
        );
    }
}

void BasicServer::handleClient(
    int client_socket
)
{

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
    stats.incrementTotal();

    if(bytes_received < 0)
    {
        std::cerr
            << "recv failed\n";

        close(client_socket);
        return;
    }

    std::cout
        << "\n===== REQUEST =====\n"
        << buffer
        << "\n===================\n";

    if(request.parse(rawRequest))
    {
        Logger logger;

        logger.logRequest(
            request.method,
            request.path
        );

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
Router router;
FileHandler fileHandler;

std::string body;
bool is404 = false;

if(request.path == "/stats")
{
    body =
        generateStatsPage();

    stats.incrementSuccess();
}
else
{
    std::string filepath =
        router.route(request.path);

    is404 =
        (filepath == "../public/404.html");

    if(is404)
    {
        stats.incrementNotFound();
    }
    else
    {
        stats.incrementSuccess();
    }

    body =
        fileHandler.readFile(filepath);

    std::cout
        << "File path: "
        << filepath
        << "\n";

    std::cout
        << "Body size: "
        << body.size()
        << "\n";
}

    std::string statusLine =
        is404
        ? "HTTP/1.1 404 Not Found\r\n"
        : "HTTP/1.1 200 OK\r\n";
        std::string contentType =
    "text/html";

if(request.path != "/stats")
{
    std::string filepath =
        router.route(request.path);

    contentType =
        MimeTypes::getMimeType(
            filepath
        );
}

    std::string response =
        statusLine +
        "Content-Type: "
+ contentType +
"\r\n"
        "Content-Length: " +
        std::to_string(body.length()) +
        "\r\n"
        "Connection: close\r\n"
        "\r\n" +
        body;

    send(
        client_socket,
        response.c_str(),
        response.length(),
        0
    );

    close(client_socket);
}
std::string BasicServer::generateStatsPage()
{
    return
        "<html>"
        "<head><title>Server Stats</title></head>"
        "<body>"
        "<h1>Server Statistics</h1>"
        "<p>Total Requests: "
        + std::to_string(
            stats.getTotal()
        )
        + "</p>"
        "<p>Successful Requests: "
        + std::to_string(
            stats.getSuccess()
        )
        + "</p>"
        "<p>404 Requests: "
        + std::to_string(
            stats.getNotFound()
        )
        + "</p>"
        "</body>"
        "</html>";
}