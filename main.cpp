#include "String.h"
#include <cstdlib> 
#include <iostream>

int main(){
  std::size_t cap=10;
  String str(cap);
  std::cout<<(str.capacity()==10)<<std::endl;// Unitary test : checks the capacity() method
  std::size_t cap1=15;
  String str1(cap1);
  return 0;
  
}
