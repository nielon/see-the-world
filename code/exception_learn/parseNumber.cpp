#include <cstdlib>
#include <cstring>
#include <cctype>
#include "parseNumber.h"

bool isNumber(char* str)
{
  if((str == NULL) || (strlen(str) == 0))
    return false;
  if((*str) == '-' || (*str) == '+')
    ++str;
  if( *str == '\0' )
    return false;
  while( *str != '\0' )
  {
    if(! isdigit(*str))
      return false;
    else
      ++str;
  }
  return true;
}
int parseNumber(char* str) throw(NumberParseException)
{
  if(!isNumber(str))
    throw NumberParseException();
  if( strlen(str) >= 5 )
    throw Overflow();
  return atoi(str);
}
