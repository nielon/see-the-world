#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 依据参数 n，过滤集合中单词

int main(void)
{
  const vector<string> words = {"niel",
  "has",
  "many",
  "books"};

  cout << "-------------use for()" << endl;
  cout << "长度大于3的单词：";
  for (auto citor = words.cbegin(); citor != words.cend(); ++citor)
  {
    if(citor->size() > 3)
      cout << *citor << " ";
  }
  cout << endl;
  cout << "长度大于4的单词：";
  //for (auto citor = words.cbegin(); citor != words.cend(); ++citor)
  //{
    //if(citor->size() > 4)
      //cout << *citor << " ";
  //}
  for ( auto word : words )
  {
    if(word.size() > 4)
      cout << word << " ";
  }
  cout << endl;

  return 0;
}
