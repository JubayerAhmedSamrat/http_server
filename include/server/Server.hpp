#pragma once

#include <cstdint>

class Server
{
public:
  explicit Server(std::uint16_t port);

  void start();
  ~Server();

private:
  void create_socket();
  void bind_socket();
  void start_listening();
  void accept_connection();


  std::uint16_t port_;
  int listen_fd_{-1};

};
