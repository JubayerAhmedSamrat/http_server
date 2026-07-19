#include "server/server.hpp"
#include "config/ServerConfig.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
  try
  {

    ServerConfig config;
    Server server(config.port());

    server.start();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  return 0;
}
