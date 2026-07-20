#pragma once 

#include "http/Request.hpp"

#include <string>
#include <sstream>

class BadRequestException : public std::runtime_error
{
  public:
    using std::runtime_error::runtime_error;
};

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
