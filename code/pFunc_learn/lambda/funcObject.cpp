#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 依据参数 n，过滤集合中单词

class Printlen
{
  private:
    unsigned m_len;
  public:
    Printlen() = default;
    Printlen(const unsigned len):m_len(len) {}
    void operator()(const string& word)
    {
      if(word.size() > m_len)
	cout << word << " ";
    }
};


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

  cout << "-------------use for_each() && function Object " << endl;
  cout << "长度大于" << len << "的单词：";
  Printlen printlen(len);
  for_each(words.cbegin(), words.cend(), printlen);
  cout << endl;
  cout << "长度大于" << len2 << "的单词：";
  Printlen printlen2(len2);
  for_each(words.cbegin(), words.cend(), printlen2);
  cout << endl;
  return 0;
}
