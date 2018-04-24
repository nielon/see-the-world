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
#include<unistd.h>

using namespace std;

void *thread(void *arg)
{
    stringstream oss;
    oss << "in thread, tid = " << pthread_self() << endl;
    cout << oss.rdbuf();
//    printf( "in thread, tid =  %d" ,pthread_self());

    sleep(60);

    return (void *)12;

}

int main()
{
    pthread_t tid;
    if(pthread_create(&tid, NULL, thread, 0) != 0)
    {
    cout << "pthread_create error" << endl;
    return 0;
    
    }

  //sleep(1);
    pthread_cancel(tid);
    
    int *r;
    pthread_join(tid, (void**)&r);

    assert(cout.good());
    cout << PTHREAD_CANCELED << endl;
    cout << r << endl;
    
    cout << "in main thread, tid = " << pthread_self() << endl;
    return 0;

}
