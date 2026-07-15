#pragma once

#include <string>

class Connection
{
public:
  explicit Connection(int client_fd);

  std::string receive();

  ~Connection();
private:
  int client_fd_;
};
