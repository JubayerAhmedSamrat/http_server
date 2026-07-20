#include "filesystem/StaticFileHandler.hpp"
#include "filesystem/FileReader.hpp"
#include "filesystem/MimeTypes.hpp"

#include <filesystem>

Response StaticFileHandler::serve(const std::string& path)
{
  std::string filename = path;

  if(filename == "/")
  {
    filename = "/index.html";
  }

  std::string full_path = "public" + filename;
  if(path.find("..") != std::string::npos)
  {
    return Response::forbidden(
        FileReader::read("public/errors/403.html"), "text/html"
        );
  }
  if(!std::filesystem::exists(full_path))
  {
    return Response::not_found(
        FileReader::read("public/errors/404.html"), "text/html"
        );
  }

  return Response::ok(
      FileReader::read(full_path),
      MimeTypes::get(full_path)
      );
}
