/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  试验 cout 的线程安全性
 *    c++11 下，不在一条语句中多次调用 << 运算符函数，不会发生交叉输出。此现象同 printf。
 *
 *        Version:  1.0
 *        Created:  2018年01月16日 10时19分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  niel (), nie7ng@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <sstream>
#define _USE_COUT_
void test(void)
{
    while (true)
    {
#ifdef _USE_COUT_
      std::stringstream ss;
        ss << std::this_thread::get_id() << ": Hello" << std::endl;
	std::cout << ss.rdbuf();
#else
        printf("%d: Hello\n", std::this_thread::get_id());
#endif
        //std::this_thread::sleep_for();
    
    }

}

void test2(void)
{
    while (true)
    {
#ifdef _USE_COUT_
        std::stringstream ss;
	ss << std::this_thread::get_id()  << ": #####" << std::endl;
        std::cout << ss.rdbuf();
#else
printf("%d: #####\n", std::this_thread::get_id());
#endif
    
    }

}

int main(void)
{
    std::thread t1(test);
    std::thread t2(test2);
    t1.join();
    t2.join();
}
