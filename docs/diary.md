# Development Diary

## Phase 1 — TCP Networking

Implemented:

- socket()
- bind()
- listen()
- accept()
- recv()
- send()

Learned:

- TCP sockets
- Client/server communication
- POSIX networking

---

## Phase 2 — HTTP

Implemented:

- HTTP request parsing
- HTTP response generation
- Request struct
- Response serialization

Learned:

- HTTP/1.1 protocol
- Request line
- Response headers
- Content-Length

---

## Phase 3 — Routing

Implemented:

- Router class
- Handler-based routing
- 404 responses

Endpoints:

- /
- /health
- /echo

---

## Phase 4 — Resource Management

Implemented:

- Connection RAII
- Server RAII
- Socket cleanup

Learned:

- Ownership
- Destructors
- RAII

---

## Phase 5 — Production Features

Implemented:

- SO_REUSEADDR
- Persistent accept loop
- Exception handling
- Configuration loading
- Centralized logger

---

## Phase 6 — HTTP Features

Implemented:

- Request headers
- Query parameters
- POST support
- Middleware
- Static file serving
- MIME detection
- HTML error pages
- Response factory methods

---

## Lessons Learned

- TCP Networking
- HTTP Protocol
- POSIX Sockets
- Modular Software Design
- Modern C++23
- Systems Programming
