#pragma once 

#include "http/Request.hpp"
#include "http/Response.hpp"

#include <functional>
#include <string>
#include <unordered_map>

class Router 
{
public:
  Router();

  Response route(const Request& request) const;

private:
  using Handler = std::function<Response(const Request&)>;

  std::unordered_map<std::string, Handler> routes_;
};
