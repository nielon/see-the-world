#include "MyUtility.h"
#include <iostream>

using namespace std;

class MyTree
{
public:
  std::string text;
  bool leaf;
  std::list<MyTree> children;
};

MyTree GetNode(int id)
{
  MyTree tree;
  list<int> subids;
  // TODO: 简陋，未获取 节点名称
  Singleton::Instance().GetResult(id, subids);
  // TODO:给 tree.text 赋值
  if (subids.size() == 0)
    tree.leaf = true;
  else
  {
    tree.leaf = false;
    for (auto itor = subids.cbegin();
		itor != subids.cend();
		++itor)
      tree.children.push_back(GetNode(*itor));
  }
  return tree;
}

list<MyTree> GetSubNodes(int id)
{
  return GetNode(id).children;
}

int main(void)
{
  list<MyTree> subs= GetSubNodes(1);
}

