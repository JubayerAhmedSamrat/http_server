#include "server/Middleware.hpp"

#include <iostream>

void Middleware::log_request(const Request& request) const 
{
  std::cout 
    << "\n=========== REQUEST ===============\n";

  std::cout 
    << request.method 
    << ' '
    << request.path 
    << '\n';

  std::cout 
    << "===================================\n";
}
