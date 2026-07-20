#include "http/Response.hpp"

#include <sstream>

Response::Response(
    int status_code,
    std::string status_text,
    std::string body,
    std::string content_type
    )
  : status_code_{status_code},
    status_text_{std::move(status_text)},
    body_{std::move(body)},
    content_type_{std::move(content_type)}
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
    << "Content-Type: "
    << content_type_
    << "\r\n";

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
