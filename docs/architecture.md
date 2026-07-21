# HTTP Server Architecture

## Overview

The server follows a modular request-processing pipeline where each component has a single responsibility.

```
                Client
                   │
                   ▼
            TCP Connection
                   │
                   ▼
              Connection
                   │
               receive()
                   │
                   ▼
                Parser
                   │
                parse()
                   │
                   ▼
                Request
                   │
                   ▼
              Middleware
                   │
             log_request()
                   │
                   ▼
                Router
         ┌─────────┴─────────┐
         ▼                   ▼
   API Handlers      Static File Handler
         │                   │
         └─────────┬─────────┘
                   ▼
               Response
                   │
              to_string()
                   │
                   ▼
              Connection
                   │
                   ▼
            send_response()
                   │
                   ▼
                 Client
```

---

## Responsibilities

### Server

- Owns the listening socket.
- Creates, binds and listens.
- Accepts incoming TCP connections.

### Connection

- Owns one client socket.
- Receives raw HTTP requests.
- Sends serialized HTTP responses.
- Automatically closes the socket (RAII).

### Parser

Converts raw HTTP text into a structured `Request`.

Parses:

- Method
- Path
- Version
- Headers
- Query Parameters
- Body

### Middleware

Processes requests before routing.

Current middleware:

- Request logging

### Router

Maps incoming requests to handlers.

Current endpoints:

- /
- /health
- /echo
- /api/health

### Static File Handler

Serves files from the `public/` directory.

Features:

- MIME type detection
- index.html fallback
- Directory traversal protection

### Response

Creates valid HTTP/1.1 responses.

Adds:

- Status line
- Content-Type
- Content-Length
- Connection header
