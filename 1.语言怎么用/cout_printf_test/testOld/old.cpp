/*
 * =====================================================================================
 *
 *       Filename:  old.cpp
 *
 *    Description:  使用旧标准，试验 stream 内部状态是否会异常
 *
 *        Version:  1.0
 *        Created:  2018年01月16日 10时41分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  niel (), nie7ng@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <assert.h>

#include<pthread.h>
#include<iostream>
#include<sstream>
#include<unistd.h>

using namespace std;

void *thread(void *arg)
{
  while(true)
  {

      std::stringstream ss;
        ss << pthread_self() << ": Hello" << std::endl;
	std::cout << ss.rdbuf();
  }
}
void *thread2(void *arg)
{
  while(true)
  {

      std::stringstream ss;
        ss << pthread_self() << ": #####" << std::endl;
	std::cout << ss.rdbuf();
  }
}

int main()
{
    pthread_t tid,tid2;
    if(pthread_create(&tid, NULL, thread, 0) != 0)
    {
    cout << "pthread_create error" << endl;
    return 0;
    
    }

    if(pthread_create(&tid2, NULL, thread2, 0) != 0)
    {
    cout << "pthread_create error" << endl;
    return 0;
    
    }
    
    int *r;
    pthread_join(tid, (void**)&r);
    pthread_join(tid2, (void**)&r);

    return 0;

}
