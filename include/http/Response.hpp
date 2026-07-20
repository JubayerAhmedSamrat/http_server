#pragma once 

#include <string>

class Response 
{
public:
  Response(
      int status_code,
      std::string status_text,
      std::string body,
      std::string content_type = "text/plain"
      ); 

  std::string to_string() const;
  
  static Response ok(
      std::string body,
      std::string content_type = "text/plain"
      );
  static Response not_found(
      std::string body = "404 Not Found",
      std::string content_type = "text/plain"
      );
  static Response forbidden(
      std::string body = "403 Forbidden"
     ,std::string content_type = "text/plain" 
      );
  static Response bad_request(
      std::string body = "400 Bad Request",
      std::string content_type = "text/plain"
      );
  static Response internal_error(
      std::string body = "500 Internal server Error",
      std::string content_type = "text/plain"
      );
  static Response method_not_allowed(
      std::string body = "405 Method Not Allowed",
      std::string content_type = "text/plain" 
      );

private:
  int status_code_;
  std::string status_text_;
  std::string body_;
  std::string content_type_;
};
