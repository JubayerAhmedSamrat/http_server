#pragma once

#include <cstdint>

class Server
{
public:
  explicit Server(std::uint16_t port);

  void start();

private:
  std::uint16_t port_;
  int listen_fd_{-1};
};
