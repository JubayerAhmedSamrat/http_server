## Day 3 

### Systems 
- Learned what bind() does.
- Learned that sockets must be bound to an address before accepting connections.
- Learned sockaddr_in.

### C++ 
-Learned aggregate initialization.

 sockaddr_in address{};

## Day 4 
### Systems 
- Learned how `listen()` marks a socket as passive.
- Learned about the kernel's pending connection queue.
- Learned the purpose of the backlog parameter.

### C++ 
- Learned `constexpr` for compile-time constants.
- Continued using POSIX system calls with exception handling.

## Day 5 
### Systems 
- Learned accept().
- Learned recv().
- Learned close().
- A listening socket accepts connections.
- A client socket communicates with exactly one client.
### C++ 
- Learned ssize_t.
- Learned why recv() returns the number of bytes read.

## Day 6 
### Systems 
- Moved client communication into a dedicated connection class.

### C++ 
- Learned the basics of RAII 
## Day 7
### Systems 
- An HTTP request starts with a request line.
- The request line contains the method, path, and HTTP version.
### C++ 
- Learned `std::istringstream`.
- Learned to model HTTP requests with a struct.
- Learned `const` member function.
## Day 8
### Systems 
- Learned how HTTP responses are formatted.
- Implemented HTTP/1.1 response generation.
- Learned why `Content-Length` is required.
- Used `send()` to transmit data over TCP.

### C++ 
- Learned `std::ostringstream`.
- Introduced `std::move`.
- Learned protocol bugs differ from compiler errors.

## Milestone 9 - Router 
### System 
- Added a dedicatd router class.
- Implemented routing for:
    - `/`
    - `/health`
    - `/echo`
- Added 404 responses. 

### C++   
- Used `const Request&` to avoid unnecessary copies.
- Improved separation of concern by moving routing logic out of `Server`. 

## Milestone 10 - Resource Ownership 
### System 
- Distinguished between the listening socket and client sockets.
- Ensured client sockets are closed after each request.
- Added cleanup for the listening socket.

### C++  
- Applied RAII 
- Added a destructor to `Server`.
- Improved ownership semantics.

## Milestone 11 - socket options 
### systems 
- Learned about the TCP `TIME_WAIT` state.
- Investigated why `bind()` can fail after a server exits.
- Introduced socket options using `setsockopt()`.
- Enabled `SO_REUSEADDR` for rapid server restarts.

### Networking 
- Learned how sockets options influences kernel networking behavior.
