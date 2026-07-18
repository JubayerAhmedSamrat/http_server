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

