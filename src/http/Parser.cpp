#include "http/Parser.hpp"
#include <sstream>
#include <stdexcept>

Request Parser::parse(const std::string& raw_request) const 
{
  std::istringstream stream(raw_request);

  Request request;
  
  parse_request_line(stream, request);
  parse_query_parameters(request);
  parse_headers(stream, request);
  parse_body(stream, request);

  return request;
}

void Parser::parse_request_line(
    std::istringstream& stream,
    Request& request 
    ) const 
{
  if(!(stream >> request.method
              >> request.path
              >> request.version))
  {
    throw std::runtime_error("Invalid HTTP request.");
  }

  std::string line;
  std::getline(stream, line);
}

void Parser::parse_query_parameters(
    Request& request
    ) const 
{
  auto question_mark = request.path.find('?');

  if(question_mark == std::string::npos)
  {
    return;
  }

  std::string query = 
    request.path.substr(question_mark + 1);

  request.path = 
    request.path.substr(0, question_mark);

  std::istringstream query_stream(query);

  std::string pair;

  while(std::getline(query_stream, pair, '&'))
  {
    auto equals = pair.find('=');
    if(equals == std::string::npos)
    {
      continue;
    }

    request.query_params[
      pair.substr(0, equals)
    ] = pair.substr(equals + 1);
  }

}

void Parser::parse_headers(
    std::istringstream& stream,
    Request& request 
    ) const 
{
  std::string line;

  while(std::getline(stream, line))
  {
    if(!line.empty() && 
        line.back() == '\r')
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

    std::string key = 
      line.substr(0, colon);

    std::string value = 
      line.substr(colon + 1);

    if(!value.empty() && 
        value.front() == ' ')
    {
      value.erase(0, 1);
    }

    request.headers[key] = value;
  }
}

void Parser::parse_body(
    std::istringstream& stream,
    Request& request
    ) const 
{
  std::ostringstream body;

  body << stream.rdbuf();
  request.body = body.str();
}

