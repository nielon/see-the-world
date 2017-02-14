#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

//#ifndef UNICODE
//#define UNICODE
//#endif [> ifndef SYMBOL <]

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
  setlocale(LC_ALL, "");
  const wchar_t *pwch = L"汉字";
  printf("str: %s\n", "中文");
  printf("wstr: %ls\n", pwch);
#ifndef UNICODE
	char str[] = "12345";
	printlen(str);
	printf("%s's size is: %ld\n", str, sizeof(str));

	char str1[] = "你好，世界";
	printlen(str1);
	printf("%s's size is: %ld\n", str1, sizeof(str1));

	printf("---------------\n");
#endif

#ifdef UNICODE
	wchar_t wstr[] = L"12345";
	wprintlen(wstr);
	wprintf(L"L%ls's size is: %d\n", wstr, sizeof(wstr));

	wchar_t wstr1[] = L"你好，世界";
	wprintlen(wstr1);
	wprintf(L"L%ls's size is: %d\n", wstr1, sizeof(wstr1));
#endif
	return 0;

}
