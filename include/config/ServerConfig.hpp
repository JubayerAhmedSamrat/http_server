#pragma once

#include <cstdint>
#include <string>

class ServerConfig
{
public:
 explicit ServerConfig(const std::string& filename);

  std::uint16_t port() const;

  int backlog() const;

private:
  void load(const std::string& filename);

  std::uint16_t port_ = 8080;
  int backlog_ = 10;
};
