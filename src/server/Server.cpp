#include "server/Server.hpp"

#include <iostream>

Server::Server(std::uint16_t port)
  :port_{port}
{

}

void Server::start()
{
  std::cout << "Starting HTTP server on port "
            << port_
            << '\n';
            
}
