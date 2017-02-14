#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 依据参数 n，过滤集合中单词

int main(int argc, char *argv[])
{
  unsigned len, len2;
  len = len2 = 4;
  if (argc == 3) {
    len = atoi(argv[1]);
    len2 = atoi(argv[2]);
  }
  vector<string> words = {"niel",
  "has",
  "many",
  "books"};

  cout << "-------------use for_each() && lambda" << endl;

  cout << "长度大于" << len << "的单词：";
  for_each(words.cbegin(), words.cend(), 
      [len](const string& word){
        if (word.size() > len)
	  cout << word << " ";
      });
  cout << endl;

  cout << "长度大于" << len2 << "的单词：";
  for_each(words.cbegin(), words.cend(), 
      [len2](const string& word){
        if (word.size() > len2)
	  cout << word << " ";
      });
  cout << endl;
  return 0;
}
