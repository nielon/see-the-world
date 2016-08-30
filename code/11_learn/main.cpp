#include <iostream>
#include <string>
#include <map>
int main(void)
{
  std::map<std::string, float> students;
  students["Nielong"] = 4.0;
  students["Tom"] = 1.0;
  for(auto &itor : students)
  {
    itor.second = 88;
    std::cout << itor.first << " score is " 
      << itor.second << std::endl;
  }
  return 0;
}
