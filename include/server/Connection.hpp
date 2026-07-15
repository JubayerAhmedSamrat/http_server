#pragma once

#include <string>

class Connection
{
public:
  explicit Connection(int client_fd);

  std::string receive();
  void send_response(const std::string& response);

  ~Connection();
private:
  int client_fd_;
};
