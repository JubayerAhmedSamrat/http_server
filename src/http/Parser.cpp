#include "http/Parser.hpp"
#include <sstream>
#include <stdexcept>

Request Parser::parse(const std::string& raw_request) const 
{
  std::istringstream stream(raw_request);

  Request request;

  if(!(stream >> request.method >> request.path >> request.version))
  {
    throw std::runtime_error("Invalid HTTP request.");
  }

  return request;
}
