# HTTP Server Roadmap 
## Networking 

- [x] socket()
- [x] bind()
- [x] listen()
- [x] accept()
- [x] recv()
- [x] send()

## HTTP 

- [x] Parse Request Line 
- [x] Build HTTP Response 
- [x] HTTP Headers 
- [x] Content-Length 

## Routing 

- [x] Router class 
- [x] GET / 
- [x] GET /health 
- [x] GET /echo 
- [x] 404 Response 

## Resource Mangement 

- [x] Connection RAII 
- [x] Server RAII 
- [x] SO_REUSEADDR 

## Upcomming 

- [ ] Persistent accept loop
- [ ] Logger integration 
- [ ] Request headers 
- [ ] Query parameters 
- [ ] POST requests 
- [ ] Static file serving 
- [ ] Thread Pool 
- [ ] epoll()
- [ ] Keep-Alive 
- [ ] Middleware 
- [ ] Benchmarks 
