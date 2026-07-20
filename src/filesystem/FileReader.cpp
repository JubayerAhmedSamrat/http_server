#include "filesystem/FileReader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

std::string FileReader::read(const std::string& filename)
{
  std::ifstream file(filename);

  if(!file)
  {
    throw std::runtime_error(
        "cannot open file: " + filename
        );
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}
