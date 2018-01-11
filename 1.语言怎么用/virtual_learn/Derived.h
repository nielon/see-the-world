#ifndef DERIVED_H
#define DERIVED_H 
#include "Base.h"
class Derived : public Base 
{
  public:
    virtual ~Derived() {
      cout << "Derived::~Derived()" << endl;
    };
    virtual void Func()
    {
      cout << "Derived::Func()" << endl;
    }
};
#endif /* DERIVED_H */
