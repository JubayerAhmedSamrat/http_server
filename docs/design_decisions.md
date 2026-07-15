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
