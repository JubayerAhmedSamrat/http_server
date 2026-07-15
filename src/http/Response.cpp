#include "http/Response.hpp"

#include <sstream>

Response::Response(
    int status_code,
    std::string status_text,
    std::string body
    )
  : status_code_{status_code},
    status_text_{std::move(status_text)},
    body_{std::move(body)}
{

}

std::string Response::to_string() const
{
  std::ostringstream stream;

  stream 
    << "HTTP/1.1 "
    << status_code_ 
    << ' '
    << status_text_ 
    << "\r\n";

  stream 
    << "Content-Type: text/plain\r\n";

  stream 
    << "Content-Length: "
    << body_.size()
    << "\r\n";

  stream 
    << "Connection: close\r\n";

  stream 
    << "\r\n";

  stream 
    << body_;

  return stream.str();
}
