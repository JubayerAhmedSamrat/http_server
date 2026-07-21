# HTTP Server Architecture

## Overview

The server follows a modular pipeline where each component has a single responsibility.

```
Client
    │
    ▼
Server
    │
    ▼
Connection
    │
    ▼
HTTP Parser
    │
    ▼
Middleware
    │
    ▼
Router
 ┌──┴─────────────┐
 ▼                ▼
API         Static Files
 └──────┬─────────┘
        ▼
HTTP Response
        ▼
Client
```

---

## Components

### Server

Responsible for:

- Creating sockets
- Binding
- Listening
- Accepting connections

---

### Connection

Handles raw TCP communication.

Responsibilities:

- recv()
- send()
- closing sockets

---

### HTTP Parser

Converts raw HTTP requests into structured Request objects.

Parses:

- Method
- Path
- Headers
- Query parameters
- Body

---

### Middleware

Runs before routing.

Current middleware:

- Request logging

Future middleware:

- Authentication
- Rate limiting
- Compression

---

### Router

Maps URLs to handlers.

Examples:

- /
- /health
- /api/health

---

### Static File Handler

Serves files from

public/

Automatically:

- detects MIME type
- loads index.html
- blocks directory traversal

---

### Response

Generates valid HTTP/1.1 responses.

Adds:

- Status Line
- Content-Type
- Content-Length
- Connection header

---

## Design Principles

- Single Responsibility Principle
- RAII
- Composition over inheritance
- Small reusable classes
