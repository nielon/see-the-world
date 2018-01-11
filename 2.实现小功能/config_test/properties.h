#ifndef _PROPERTIES_H_
#define _PROPERTIES_H_
 
#include <string>
#include <map>
 
#define COMMENT_CHAR '#'

namespace property
{
  bool ReadConfig(const std::string & filename, std::map<std::string, std::string> & m);
  void PrintConfig(const std::map<std::string, std::string> & m);
}
#endif
