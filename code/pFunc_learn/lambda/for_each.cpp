#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 依据参数 n，过滤集合中单词

unsigned len = 4;
unsigned len2 = 4;

void Printlen(const string& word)
{
  if (word.size() > len)
    cout << word  << " ";
}
void Printlen2(const string& word)
{
  if (word.size() > len2)
    cout << word  << " ";
}

int main(int argc, char *argv[])
{
  if (argc == 3) {
    len = atoi(argv[1]);
    len2 = atoi(argv[2]);
  }
  vector<string> words = {"niel",
  "has",
  "many",
  "books"};

  cout << "-------------use for_each()" << endl;
  cout << "长度大于" << len << "的单词：";
  for_each(words.cbegin(), words.cend(), Printlen);
  cout << endl;
  cout << "长度大于" << len2 << "的单词：";
  for_each(words.cbegin(), words.cend(), Printlen2);
  cout << endl;
  return 0;
}
