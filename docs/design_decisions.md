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
