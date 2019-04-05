#include "String.h"
#include <iostream>
#include <cstdlib> 

int main(){
  size_t cap=10;
  String str(cap);
  
  //Armande's tests
  char* loup = new char [5];
  loup[0]='l'; loup[1]='o'; loup[2]='u'; loup[3]='p'; loup[4]='\0';
  char* nothing = new char[5];
  nothing[0]='\0'; nothing[1]='a'; nothing[2]='b';
  
  
  //Using constructor c-string
  String Stringloup(loup);
  
  std::cout << Stringloup.length() << std::endl;
  std::cout << Stringloup.max_size() << std::endl;
   
  return 0;
}
