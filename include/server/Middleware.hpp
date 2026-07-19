#pragma once

#include "http/Request.hpp"

class Middleware
{
public:
  void log_request(const Request& request) const;

};
