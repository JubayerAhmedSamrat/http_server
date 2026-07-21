# Decision #1

## Introduce a Dedicated Server Class

### Responsibilities

- Own the HTTP server lifecycle.
- Create and initialize the listening socket.
- Bind the socket to a network address.
- Start listening for incoming connections.
- Accept client connections.
- Manage server startup and shutdown.

### Reason

The server is the core component of the application.

Encapsulating the entire server lifecycle inside a dedicated `Server` class separates networking logic from the program entry point (`main.cpp`). This results in a cleaner architecture, improves maintainability, and provides a solid foundation for future features such as configuration management, logging, thread pools, and event-driven networking.

---

# Decision #2

## Keep `main.cpp` Minimal

### Responsibilities

- Serve as the application entry point.
- Construct the `Server` object.
- Start the server.
- Handle top-level exceptions.
- Exit gracefully on fatal errors.

### Reason

The entry point should contain as little logic as possible.

Keeping `main.cpp` small makes the application easier to understand and keeps application startup separate from server implementation. All networking, request handling, and resource management remain inside dedicated classes, following the principle of separation of concerns.

This design also makes the project easier to extend, test, and maintain as additional infrastructure components are introduced.
## Decision #3 

The Server class owns socket creation and binding.

Reason:

keeps networking responsibilities inside Server.

## Decision #4 
### Separate networking setup into dedicated methods 

The networking setup is split into:

- create_socket()
- bind_socket()
- start_listening()

Reasons:
- Single responsibility for each function.
- Easier debugging.
- Easier future extention (SO_REUSEADDR, IPv6, TLS, etc.).

## Decision #5 
The listening socket and client socket are kept separate.

Reason: 
- The listening socket continues accepting new clients.
- Each accepted connection gets its own file descriptor.

## Decision #6 
### Introduce Connection class 

Responsibilities:
- Own one client socket. 
- Received data.
- Automatically close the socket.

Benefits:
- Server only manages listening.
- Connection manages one client.
- Easier to add send(), keep-alive, and timeouts later.

## Decision #7 
### Separate parsing from networking 

Reason:
- Connection only receives bytes.
- Parser converts bytes into structured data.
- Easier to test and maintain.
## Decision #8

### Dedicated Respone class 

Responsibilites 
- Build valid HTTP Responses.
- Format status line.
- Add HTTP headers.
- Append body.

Reason 

The networking layer should only transmit bytes.
HTTP formatting belongs inside the Response class.

# Decision #9 
## Introduce a Router 

Responsibilities 

- Decide which endpoint should handle a request.
- Return the correct HTTP response.

Reason 

Networking and routing are different concerns.

The server should only manage sockets.

The Router should manage application behaviour.

# Decision #10 

## server owns the listening socket 

Responsibilities 
- Create the listening socket.
- bind it.
- Listening for incomming connections.
- close it during destruction.

Reason 

The listening socket is a resource owned by server.

Folowing RAII, the owner is resposible for cleanup. 

# Decision #11 
## Enable SO_REUSEADDR 
reason 
without this socket option, restarting the server immediately after exiting may fail because the previous TCP connection remains in the TIME_WAIT state.

using SO_REUSEADDR is standard for production network servers.
# Decision #12 
## Persistent Accept Loop 
Reason 

A production HTTP server should continue accepting new client connections intead of exiting after serving one request.

Errors while processing one client must not terminate the entire server.

# Decision #13

## Introduce Configuration Loader

Responsibilities

- Read server.conf
- Validate configuration
- Expose configuration through a clean interface

Reason

Configuration should be separated from server implementation to simplify deployment and future extensions.

---

# Decision #14

## Centralized Logger

Responsibilities

- Print informational messages
- Print errors
- Standardize logging format

Reason

Logging should be consistent across all components and isolated from business logic.

---

# Decision #15

## Static File Handler

Responsibilities

- Serve files from public/
- Detect MIME types
- Prevent directory traversal
- Return HTML error pages

Reason

Static file serving is a separate concern from request routing.

---

# Decision #16

## Response Factory Methods

Examples

- Response::ok()
- Response::not_found()
- Response::forbidden()

Reason

Factory methods eliminate duplicated status codes throughout the project and improve readability.
