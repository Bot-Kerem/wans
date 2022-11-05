#include <platform.h>

#include <fstream>

std::string Platform::OpenFile(std::string FilePath)
{
    std::fstream File(FilePath);
    if(!File.is_open())
    {
      return "";
    }
  return std::string((std::istreambuf_iterator<char>(File)), std::istreambuf_iterator<char>());
}
