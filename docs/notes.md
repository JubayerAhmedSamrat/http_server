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
