// whattotest.cpp

#include <stdio.h> 
#include <string.h> 

bool findString(uint8_t* mainStr, const char* subStr, uint32_t maxlen)
{
  //todo: add subStr NULL checking 
  //todo: add strlen NUL check
  //todo: remove maxlen necessity 
  if (mainStr == NULL)
    return false;

  uint8_t strTemp[32];

  uint32_t count = 0;
  uint32_t mainLen = 0;
  uint32_t subLen = 0;
  
  mainLen = strlen((char*)mainStr);
  subLen = strlen((char*)subStr);
  
  if(mainLen > maxlen){
    mainLen = maxlen;
  }

  memset(strTemp,'\0', 32);
  memcpy(strTemp,subStr,subLen);

  for(uint32_t i = 0; i < mainLen; i++){
    if(mainStr[i]== strTemp[count]) 
      count++;
    else
      count = 0;

    if(count == subLen){
      return true; 
    }
  }
  return false;
}