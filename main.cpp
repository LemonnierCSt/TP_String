#include "String.h"
#include <cstdlib> 
#include <iostream>

int main(){
  std::size_t cap=10;
  String str(cap);
  String str2(cap);
  std::cout<<(str.capacity()==10)<<std::endl;

  std::cout<<"Test c_str:"<<std::endl;
  std::cout<<str.c_str()<<std::endl;

  return 0;
  
}
