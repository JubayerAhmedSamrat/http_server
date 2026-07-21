# HTTP Server Roadmap

## Version 1.0 ✅

### Networking

- [x] socket()
- [x] bind()
- [x] listen()
- [x] accept()
- [x] recv()
- [x] send()
- [x] SO_REUSEADDR

### HTTP

- [x] HTTP Request Parsing
- [x] HTTP Response Generation
- [x] Request Headers
- [x] Query Parameters
- [x] GET
- [x] POST

### Routing

- [x] Router
- [x] API Endpoints
- [x] Static File Serving

### Static Files

- [x] HTML
- [x] CSS
- [x] MIME Detection
- [x] Directory Traversal Protection

### Error Handling

- [x] 400
- [x] 403
- [x] 404
- [x] 405
- [x] 500

### Infrastructure

- [x] Logger
- [x] Middleware
- [x] Configuration
- [x] Persistent Accept Loop

---

## Version 2

- [ ] Thread Pool
- [ ] Multithreading
- [ ] Keep-Alive
- [ ] Connection Pool
- [ ] File Cache

---

## Version 3

- [ ] epoll
- [ ] Non-blocking sockets
- [ ] Event Loop
- [ ] Connection Timeout

---

## Version 4

- [ ] Reverse Proxy
- [ ] Load Balancer
- [ ] HTTPS
- [ ] HTTP/2
