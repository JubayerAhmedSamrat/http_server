#pragma once

#include <cstdint>

class ServerConfig
{
public:
  ServerConfig() = default;

  std::uint16_t port() const;

  int backlog() const;

private:
  std::uint16_t port_ = 8080;

  int backlog_ = 10;
};
