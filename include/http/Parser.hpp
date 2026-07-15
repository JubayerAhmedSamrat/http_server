#pragma once 

#include "http/Request.hpp"

#include <string>

class Parser 
{
public:
  Request parse(const std::string& raw_request) const;
};
