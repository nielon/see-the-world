#include <iostream>
#include <string>
#include "Derived.h"
#include "Final.h"
#include "Base.h"

using namespace std;


int main(void)
{
  //Base *p = new Final("o");
  //p->Func();
  //cout << "---------------" << endl;
  //Final obj("use cast");
  //p = reinterpret_cast<Base*>(&obj);
  //p->Func();
  //cout << "---------------" << endl;
  //for (int i=0;i < 100000; ++i)
          //Start();
  //cout << "----------------" << endl;

  Base *p = new Final("test");
  p->Start();
  //cout << "waiting 2s.." << endl;
  //sleep(2);
  delete p;
  //cout "----------------------" << endl;
  //Final obj("test");
  //Base *p= &obj;
  //p->Start();
  //cout << "wating 2s.." << endl;
  //sleep(2);
  //const int count = 20;
  //int loop = 10000;
  //while (loop--) {
      //Final *thread[count];
      //int i;
      //for (i=0; i<count; i++) {
          //thread[i] = new Final("light");
          //thread[i]->Start();
      
      //}
      //for (i=0; i<count; i++)
          //delete thread[i];
  
  //}
  return 0;
}

//static void* threadFunc(void *tmp)
//{
  //Base *p = reinterpret_cast<Base*>(tmp);
  //p->Func();
  //return NULL;
//}


//void Start()
//{
  //pthread_t tid;
  //Final obj("Final");
  //int rc = pthread_create(&tid, NULL, threadFunc, &obj);
  //if (rc)
  //{
    //ostringstream oss;
    //oss << "ERROR: return code from pthread_create() is: " << rc;
    //throw runtime_error(oss.str());
  //}
  ////pthread_join(tid, NULL);
//}
