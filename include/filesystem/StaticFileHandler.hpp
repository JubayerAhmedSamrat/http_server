#pragma once 
#include "http/Response.hpp"

#include <string>

class StaticFileHandler
{
public:
  static Response serve(const std::string& path);
};
