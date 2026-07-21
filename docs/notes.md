# Notes

## HTTP Request Lifecycle

```
Client
    │
    ▼
Server
    │
    ▼
Connection
    │
    ▼
Parser
    │
    ▼
Middleware
    │
    ▼
Router
    │
    ▼
Handler
    │
    ▼
Response
    │
    ▼
Client
```

---

## HTTP Response Format

```
HTTP/1.1 200 OK
Content-Type: text/html
Content-Length: ...

<body>
```

---

## POSIX APIs Used

- socket()
- bind()
- listen()
- accept()
- recv()
- send()
- close()
- setsockopt()

---

## C++ Features Used

- RAII
- std::filesystem
- std::unordered_map
- std::function
- std::ostringstream
- std::istringstream
- Structured Bindings
- std::move
- constexpr
- Exceptions

---

## Current Features

- HTTP/1.1
- GET
- POST
- Query Parameters
- Routing
- Middleware
- Static Files
- MIME Types
- Configuration
- Logging
- Error Pages

---

## Future Topics

- Thread Pool
- epoll
- Non-blocking sockets
- Reverse Proxy
- Load Balancer
- HTTPS
