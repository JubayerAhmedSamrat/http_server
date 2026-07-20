#include "server/server.hpp"
#include "config/ServerConfig.hpp"
#include "logger/Logger.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
  try
  {

    ServerConfig config("server.conf");
    Server server(config.port());

    server.start();
  }
  catch(const std::exception& e)
  {
    Logger::error(e.what());
    return 1;
  }

  return 0;
}
