#include "config/ServerConfig.hpp"

std::uint16_t ServerConfig::port() const 
{
  return port_;
}

int ServerConfig::backlog() const 
{
  return backlog_;
}
