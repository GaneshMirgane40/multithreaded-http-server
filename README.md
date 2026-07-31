# 🚀 Multithreaded HTTP Server in C++

A configurable multithreaded HTTP server built from scratch in **C++** using **POSIX sockets** and **multithreading** concepts. The server efficiently handles multiple client connections using a custom thread pool, serves static web content, provides server statistics through HTML and JSON endpoints, and supports graceful shutdown with external configuration.

---

## ✨ Features

- 🌐 HTTP/1.1 GET request handling
- 🔌 POSIX socket programming
- ⚡ Multithreaded request processing using a custom Thread Pool
- 📂 Static file serving (HTML, CSS, JavaScript)
- 🛣️ Dynamic URL routing
- 📄 Custom 404 Not Found page
- 📝 Thread-safe request logging
- 📊 Server statistics tracking
- 📈 HTML dashboard (`/stats`)
- 🔗 JSON API endpoint (`/api/stats`)
- 🎨 MIME type detection
- ⚙️ External configuration via configuration file
- 🛑 Graceful server shutdown using signal handling

---

# 🏗️ Architecture

```
                 Client Browser
                        │
                        ▼
              TCP Socket (POSIX)
                        │
                        ▼
               HTTP Server Core
                        │
      ┌─────────────────┼─────────────────┐
      │                 │                 │
      ▼                 ▼                 ▼
 Thread Pool        Request Parser      Router
      │                                   │
      ▼                                   ▼
 Worker Threads                    File Handler
      │                                   │
      ▼                                   ▼
 Logger                      HTML / CSS / JS Files

                 │
                 ▼
          Server Statistics
          (/stats & /api/stats)
```

---

# 📁 Project Structure

```
CPP PROJECT 1
│
├── build/
├── config/
│   └── server.config
├── docs/
├── include/
│   ├── config.h
│   ├── file_handler.h
│   ├── http_request.h
│   ├── logger.h
│   ├── mime_types.h
│   ├── router.h
│   ├── server.h
│   ├── server_stats.h
│   └── thread_pool.h
│
├── logs/
│   └── server.log
│
├── public/
│   ├── index.html
│   ├── about.html
│   ├── contact.html
│   ├── style.css
│   ├── script.js
│   └── 404.html
│
└── src/
    ├── config.cpp
    ├── file_handler.cpp
    ├── http_request.cpp
    ├── logger.cpp
    ├── main.cpp
    ├── mime_types.cpp
    ├── router.cpp
    ├── server.cpp
    ├── server_stats.cpp
    └── thread_pool.cpp
```

---

# ⚙️ Configuration

The server configuration is loaded at runtime from:

```
config/server.config
```

Example:

```ini
PORT=9090
THREADS=4
```

This allows changing the listening port and worker thread count without recompiling.

---

# 🚀 Building the Project

## Requirements

- Linux / Ubuntu
- C++17
- CMake
- GCC / G++

### Clone Repository

```bash
git clone <repository-url>
cd CPP\ PROJECT\ 1
```

### Build

```bash
mkdir build
cd build

cmake ..
make
```

### Run

```bash
./http_server
```

---

# 🌐 Available Routes

| Route | Description |
|--------|-------------|
| `/` | Home page |
| `/about` | About page |
| `/contact` | Contact page |
| `/stats` | HTML server statistics |
| `/api/stats` | JSON server statistics |
| Any invalid route | Custom 404 page |

---

# 📊 Sample JSON API

Request:

```
GET /api/stats
```

Response:

```json
{
    "totalRequests": 25,
    "successfulRequests": 23,
    "notFoundRequests": 2
}
```

---

# 📝 Logging

Every incoming request is logged with:

- Timestamp
- HTTP Method
- Request Path

Example:

```
2026-06-16 18:49:04 GET /
2026-06-16 18:49:04 GET /style.css
2026-06-16 18:49:05 GET /api/stats
```

The logging system is thread-safe using mutex synchronization.

---

# 🧵 Multithreading

The server uses a custom thread pool to efficiently process multiple client requests concurrently.

Workflow:

```
Incoming Client
        │
        ▼
Accept Connection
        │
        ▼
Task Queue
        │
        ▼
Thread Pool
        │
        ▼
Worker Thread
        │
        ▼
Process HTTP Request
```

---

# 🛠️ Technologies Used

- C++
- POSIX Sockets
- C++17
- Multithreading (`std::thread`)
- Mutex
- Condition Variable
- Thread Pool
- HTTP/1.1
- CMake
- Linux System Programming

---

# 🎯 Key Learning Outcomes

- TCP/IP Socket Programming
- HTTP Request Parsing
- Concurrent Programming
- Thread Synchronization
- Custom Thread Pool Design
- Static File Serving
- MIME Type Detection
- REST-style JSON APIs
- Configuration Management
- Signal Handling
- Modular Software Design

---

# 🚀 Future Improvements

- Support for POST requests
- HTTP Keep-Alive connections
- Gzip Compression
- File Upload Support
- HTTPS (SSL/TLS)
- Directory Listing
- Request Timeout Handling
- Unit Testing
- Docker Support

---

# 👨‍💻 Author

**Ganesh Rajabhau Mirgane**

- B.Tech Information Technology
- Walchand College of Engineering, Sangli
