#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

//#ifndef UNICODE
//#define UNICODE
//#endif

void printlen(char *str)
{
	printf("%s's length is: %ld\n", str, strlen(str));

}

void wprintlen(wchar_t *str)
{
	wprintf(L"L%ls's length is: %d\n", str, wcslen(str));

}

int main(void)
{
#ifndef UNICODE
  setlocale(LC_ALL,""); // important

  	wchar_t wstr[] = L"12345";
	char str[6];
	size_t req = wcstombs(NULL, wstr, 0) + 1;
	printf("req: %ld\n", req);
	wcstombs(str, wstr, 3);
	printlen(str);
	printf("%s's size is: %ld\n", str, sizeof(str));

	wchar_t wstr1[] = L"你好，世界";
	char str1[16];
	size_t req1 = wcstombs(NULL, wstr1, 0) + 1;
	printf("req1: %ld\n", req1);
	wcstombs(str1, wstr1, req1);
	printlen(str1);
	printf("%s's size is: %ld\n", str1, sizeof(str1));

	printf("---------------\n");
#endif

#ifdef UNICODE
  setlocale(LC_ALL,""); // important
	char str[] = "12345";
	wchar_t wstr[6];
	size_t req = mbstowcs(NULL, str, 0);
	wprintf(L"req: %ld\n", req);
	mbstowcs(wstr, str, 3);
	wprintlen(wstr);
	wprintf(L"L%ls's size is: %d\n", wstr, sizeof(wstr));

	char str1[] = "你好，世界";
	wchar_t wstr1[6];
	size_t req1 = mbstowcs(NULL, str1, 0);
	wprintf(L"req1: %ld\n", req1);
	mbstowcs(wstr1, str1, 2);
	wprintlen(wstr1);
	wprintf(L"L%ls's size is: %d\n", wstr1, sizeof(wstr1));
#endif
	return 0;

}
