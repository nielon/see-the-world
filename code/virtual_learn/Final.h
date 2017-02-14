#ifndef FINAL_H
#define FINAL_H 
#include "Derived.h"
class Final: public Derived
{
  public:
    Final(const std::string str):m_id(str) {};
    virtual ~Final() {
      cout << "Final::~Final()" << endl;
    };
    virtual void Func()
    {
      cout << "Final::Func(), m_id is: " << m_id << endl;
    }
  private:
    std::string m_id;
};
#endif /* FINAL_H */
