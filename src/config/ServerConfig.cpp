#include "config/ServerConfig.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>

ServerConfig::ServerConfig(const std::string& filename)
{
  load(filename);
}
void ServerConfig::load(const std::string& filename)
{
  std::ifstream file(filename);

  if(!file)
  {
    throw std::runtime_error("Failed to open configuration file.");
  }

  std::string line;

  while(std::getline(file, line))
  {
    auto equals = line.find('=');
    if(equals == std::string::npos)
    {
      continue;
    }

    std::string key = line.substr(0, equals);
    std::string value = line.substr(equals + 1);

    if(key == "port")
    {
      port_ = static_cast<std::uint16_t>(std::stoi(value));
    }
    else if(key == "backlog")
    {
      backlog_ = std::stoi(value);
    }
  }


  std::cout << "Loaded configuration:\n";
  std::cout << "Port = " << port_ << '\n';
  std::cout << "Backlog = " << backlog_ << '\n';
}
std::uint16_t ServerConfig::port() const 
{
  return port_;
}

int ServerConfig::backlog() const 
{
  return backlog_;
}
