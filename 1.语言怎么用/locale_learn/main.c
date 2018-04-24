/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  i
 *
 *        Version:  1.0
 *        Created:  2018年03月06日 17时47分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  niel (), nie7ng@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <wchar.h>

int main()
{
    wprintf(L"Locale is: %s\n", setlocale(LC_ALL, NULL));
    wprintf(L"能够正常打印中文\n");
    return(0);
}
