#include "filesystem/MimeTypes.hpp"

#include <filesystem>

std::string MimeTypes::get(const std::string& filename)
{
  auto extension = std::filesystem::path(filename).extension();

  if(extension == ".html")
    return "text/html";

  if(extension == ".css")
    return "text/css";

  if(extension == ".js")
    return "appliaction/javascript";
  
  if(extension == ".txt")
    return "text/plain";

  if(extension == ".png")
    return "image/png";

  if(extension == ".jpg" || extension == ".jpeg")
    return "image/jpeg";

  return "application/octet-stream";
}
