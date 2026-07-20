#include "server/server.hpp"
#include "config/ServerConfig.hpp"
#include "logger/Logger.hpp"

#include <iostream>
#include <stdexcept>
#include <csignal>

Server* g_server = nullptr;

void signal_handler(int)
{
  if(g_server)
  {
    g_server->stop();
  }
}
int main()
{
  try
  {

    ServerConfig config("server.conf");
    Server server(config.port());
    g_server = &server;
    std::signal(SIGINT, signal_handler);

    server.start();
  }
  catch(const std::exception& e)
  {
    Logger::error(e.what());
    return 1;
  }

  return 0;
}
