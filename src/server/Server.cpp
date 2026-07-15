#include "server/Server.hpp"

#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>


Server::Server(std::uint16_t port)
  :port_{port}
{

}

void Server::start()
{
  create_socket();
  bind_socket();
  start_listening();
}

void Server::create_socket()
{
  listen_fd_ = ::socket(AF_INET, SOCK_STREAM, 0);

  if(listen_fd_ == -1)
  {
    throw std::runtime_error("Failed to create socket.");
  }

  std::cout << "Socket created.\n";
}

void Server::bind_socket()
{
  sockaddr_in address{};

  address.sin_family = AF_INET;

  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port_);

  if(::bind(
        listen_fd_,
        reinterpret_cast<sockaddr*>(&address),
        sizeof(address)) == -1)
  {
    throw std::runtime_error("Failed to bind socket.");
  }
  std::cout << "Socket bound to port "<< port_ <<".\n";
}

void Server::start_listening()
{
  constexpr int BACKLOG = 10;

  if(::listen(listen_fd_, BACKLOG) == -1)
  {
    throw std::runtime_error("Faield to listen on socket.");
  }

  std::cout << "Listen on port " << port_ <<"....\n";
}
