#include "server/server.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
  try
  {

    Server server{8080};

    server.start();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  return 0;
}
