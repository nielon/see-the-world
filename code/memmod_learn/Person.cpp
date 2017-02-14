#include "Person.h"
#include <iostream>

using namespace std;
void Person::print()
{
  cout << "id=" << id << ", age=" << age << endl;
}

void Person::personCount()
{
  cout << "personCount=" << count << endl;
}

void Person::job()
{
  cout << "Person" << endl;
}

Person::~Person()
{
  --count;
  cout << "~Person" << endl;
}
