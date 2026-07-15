#include "server/Connection.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <stdexcept>

Connection::Connection(int client_fd)
  : client_fd_{client_fd}
{

}

std::string Connection::receive()
{
  char buffer[4096]{};

  ssize_t bytes_received = 
    ::recv(
        client_fd_,
        buffer,
        sizeof(buffer) - 1,
        0
        );
  if(bytes_received == -1)
  {
    throw std::runtime_error("Failed to recieve data.");
  }

  buffer[bytes_received] = '\0';

  return std::string(buffer);
}

Connection::~Connection()
{
  ::close(client_fd_);
}

void Connection::send_response(const std::string& response)
{
  ::send(
      client_fd_,
      response.c_str(),
      response.size(),
      0);
}
