Client
    │
    ▼
TCP Connection
    │
    ▼
Connection
    │
receive()
    ▼
Parser
    │
parse()
    ▼
Request
    │
    ▼
Router
    │
route()
    ▼
Response
    │
to_string()
    ▼
Connection
    │
send()
    ▼
Client

## Responsibilities

### Server

- Owns the listening socket.
- Accepts new TCP connections.

### Connection

- Owns a client socket.
- Receives requests.
- Sends responses.

### Parser

- Converts raw HTTP text into a Request object.

### Router

- Determines which endpoint should handle the request.

### Response

- Builds a valid HTTP/1.1 response.
