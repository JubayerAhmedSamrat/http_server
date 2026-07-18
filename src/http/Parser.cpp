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

  auto question_mark = request.path.find('?');
  if(question_mark != std::string::npos)
  {
    std::string query_string = 
      request.path.substr(question_mark + 1);

    request.path = 
      request.path.substr(0, question_mark);
    std::istringstream query_stream(query_string);

    std::string pair;

    while(std::getline(query_stream, pair, '&'))
    {
      auto equals = pair.find('=');

      if(equals == std::string::npos)
      {
        continue;
      }

      std::string key = 
        pair.substr(0, equals);

      std::string value = 
        pair.substr(equals + 1);

      request.query_params[key] = value;
    }
  }
  std::string line;
  std::getline(stream, line);

  while(std::getline(stream, line))
  {
    if(!line.empty() && line.back() == '\r')
    {
      line.pop_back();
    }

    if(line.empty())
    {
      break;
    }

    auto colon = line.find(':');

    if(colon == std::string::npos)
    {
      continue;
    }

    std::string key = line.substr(0, colon);
    std::string value = line.substr(colon + 1);

    if(!value.empty() && value.front() == ' ')
    {
      value.erase(0, 1);
    }

    request.headers[key] = value;
  }
  return request;
}


