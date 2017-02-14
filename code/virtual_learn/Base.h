#ifndef BASE_H
#define BASE_H 

#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::ostringstream;
using std::runtime_error;

class Base
{
  public:
    Base():m_tid(0) {};
    virtual ~Base() 
    {
      cout << "Base::~Base()" << endl;
      if (m_tid)
        pthread_join(m_tid, NULL);
    }

    void Start()
    {
      cout << "Base::Start().." << endl;
      int rc = pthread_create(&m_tid, NULL, &(staticFunc), this);
      if (rc)
      {
        ostringstream oss;
        oss << "ERROR: return code from pthread_create() is: " << rc;
        throw runtime_error(oss.str());
      }
    }
  private:
    pthread_t m_tid;

    static void* staticFunc(void *p)
    {
      Base *tmp = reinterpret_cast<Base*>(p);
      cout << "exec ?::Func()" << endl;
      tmp->Func();
      return NULL;
    }

    virtual void Func()
    {
      cout << "Base::Func()" << endl;
    }
};

#endif /* BASE_H */
