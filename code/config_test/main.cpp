#include "properties.h"

int main(void)
{
  std::map<std::string, std::string> properties;
  property::ReadConfig("conn.properties", properties);
  property::PrintConfig(properties);
  return 0;
}
