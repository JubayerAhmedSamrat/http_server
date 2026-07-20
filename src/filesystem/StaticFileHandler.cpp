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
    return Response(
        403,
        "Forbidden",
        "403 Forbidden"
        );
  }
  if(!std::filesystem::exists(full_path))
  {
    return Response(
        404,
        "Not Found",
        "404 Not Found"
        );
  }

  return Response(
      200,
      "OK",
      FileReader::read(full_path),
      MimeTypes::get(full_path)
      );
}
