#pragma once 

#include <string>

class Response 
{
public:
  Response(
      int status_code,
      std::string status_text,
      std::string body
      );

  std::string to_string() const;

private:
  int status_code_;
  std::string status_text_;
  std::string body_;
};
