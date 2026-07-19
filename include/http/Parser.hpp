#pragma once 

#include "http/Request.hpp"

#include <string>
#include <sstream>

class Parser 
{
public:
  Request parse(const std::string& raw_request) const;

private:
  void parse_request_line(
      std::istringstream& stream,
      Request& request
      ) const;
  void parse_query_parameters(
      Request& request
      ) const;
  void parse_headers(
      std::istringstream& stream,
      Request& request
      ) const;
  void parse_body(
      std::istringstream& stream,
      Request& request
      ) const;
};
