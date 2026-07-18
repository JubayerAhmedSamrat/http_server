#pragma once 

#include "http/Request.hpp"
#include "http/Response.hpp"

class Router 
{
public:
  Response route(const Request& request) const;
};
