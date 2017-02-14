/*
linux 下 wchar_t和char的相互转化和测试
win32下wchar_t占2个字节，linux下wchar_t占4个字节。wchar_t的高字节应该存放在char数组的低字节。
Linux下面的没有命名为 WideCharToMultiByte() 和 MultiByteToWideChar() 函数，WideCharToMultiByte，MultiByteToWideChar是windows下的函数，
在linux下也有类似的两个函数：
mbstowcs()
wcstombs() 
值得注意的是:
size_t mbstowcs(wchar_t *wcstr,const char *mbstr,size_t count);
这个函数的第三个参数count，大小一定要是mbstr长度的2倍，否则出来的中文也会是乱码。

wcstombs和mbstowcs使用
#include <locale.h>
setlocale(LC_ALL, "");
wcstombs(char * to,wchar_t * from,size_t _maxCount);
mbstowcs(wchar_t * to,char * from,size_t _maxCount);

还有呢，转码还可以使iconv函数族，包含以下三个函数（其具体实例可以见demo_iconv.c和code_convert.c）：
iconv_t iconv_open(const char *tocode, const char *fromcode);
size_t iconv(iconv_t cd,char **inbuf,size_t *inbytesleft,char **outbuf,size_t *outbytesleft);
int iconv_close(iconv_t cd);
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>


size_t get_wchar_size(const char *str)
{
   size_t len = strlen(str);
   size_t size=0;
   size_t i;
   for(i=0; i < len; i++)
   {
      if( str[size] >= 0 && str[size] <= 127  ) //不是全角字符
      size+=sizeof(wchar_t);
      else //是全角字符，是中文
      {
        size+=sizeof(wchar_t);
        i+=2;
      
      }
   
   }
  return size;

}

char *w2c(const wchar_t *pw)
{
   if(!pw)
   return NULL;

   size_t size= wcslen(pw)*sizeof(wchar_t);
   char *pc;
   if(!(pc = (char*)malloc(size)))
   {
     printf("malloc fail");
     return NULL;
   
   }
   wcstombs(pc,pw,size);
   return pc;


}

wchar_t *c2w(const char *pc)
{
   if(!pc)
   return NULL;

   size_t size_of_wc = get_wchar_size(pc);
   wchar_t *pw;
   if(!(pw = (wchar_t*)malloc(size_of_wc)))
   {
      printf("malloc fail");
      return NULL;
   
   }
   mbstowcs(pw,pc,size_of_wc);
   return pw;


}

int main(void)
{
   setlocale(LC_ALL,"zh_CN.utf8");
   printf("1 print chinese by wprintf test: \n");
   wchar_t *wstr = L"中文";
   //wprintf(L"%ls",wstr); //此处不要使用wprintf，因为上面已经使用了printf，而他们使用的是不同的流，不能混用
   printf("%ls\n",wstr); //ls

   printf("2 print chinese by printf test: \n");
   char *str = "汉字";
   printf("%s\n\n\n",str); //s

   printf("3 char and wchar_t size of system test: \n");
   printf("%s%ld\n","the size of wchar_t is : ",sizeof(wchar_t)); //4
   printf("%s%ld\n\n\n","the size of char is : ",sizeof(char));   //1

   char *pc;
   wchar_t *pw = L"中文是abc一门语言abc";
   char *tmp = "中文是abc一门语言abc";
   printf("%s%s\n","input test wchar_t* ",tmp);
   pc = w2c(pw);
   printf("4 print char test after w2c (wchar to char):\n");
   printf("%s\n",pc);


   wchar_t *cw1 = c2w(pc);   //char to wchar
   char *wc1 = w2c(cw1);   //wchar to char
   printf("5 print char test after w2c c2w and w2c:\n");
   printf("%s\n\n\n",wc1);

   char *pmc = "abc中文abc";
   wchar_t *pmw;
   printf("%s%s\n","input test char* ",pmc);
   pmw = c2w(pmc);
   char *pmc1 = w2c(pmw);
   printf("6 print char test after c2w and w2c:\n");
   printf("%s\n",pmc1);

   printf("%ls\n",wstr);
   //cout<<wstr<<endl;
   return 0;


}
