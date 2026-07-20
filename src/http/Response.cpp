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

int Response::status_code() const 
{
  return status_code_;
}

const std::string& Response::status_text() const 
{
  return status_text_;
}

Response Response::ok(std::string body, std::string content_type)
{
  return Response(
      200,
      "OK",
      std::move(body),
      std::move(content_type)
      );
}

Response Response::not_found(std::string body, std::string content_type)
{
  return Response(
      404,
      "Not Found",
      std::move(body),
      std::move(content_type)
      );
}

Response Response::forbidden(std::string body, std::string content_type)
{
  return Response(
      403,
      "Forbidden",
      std::move(body),
      std::move(content_type)
      );
}

Response Response::bad_request(std::string body, std::string content_type)
{
  return Response(
      400,
      "Bad Request",
      std::move(body),
      std::move(content_type)
      );
}

Response Response::internal_error(std::string body, std::string content_type)
{
  return Response(
      500,
      "Internal Server Error",
      std::move(body),
      std::move(content_type)
      );
}

Response Response::method_not_allowed(std::string body, std::string content_type)
{
  return Response(
      405,
      "Method Not Allowed",
      std::move(body),
      std::move(content_type)
      );
}

