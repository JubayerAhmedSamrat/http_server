#include "filesystem/StaticFileHandler.hpp"
#include "filesystem/FileReader.hpp"

#include <filesystem>

Response StaticFileHandler::serve(const std::string& path)
{
  std::string filename = path;

  if(filename == "/")
  {
    filename = "/index.html";
  }

  std::string full_path = "public" + filename;

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
      "text/html"
      );
}
