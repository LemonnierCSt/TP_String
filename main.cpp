#include "String.h"
#include <cstdlib> 
#include <iostream>

int main(){
  std::size_t cap=10;
  String str(cap);
  std::cout<<(str.capacity()==10)<<std::endl;// Unitary test : checks the capacity() method, must return 1
  std::size_t cap1=15;
  String str1(cap1);
  std::cout<<(str1.empty()==false)<<std::endl;// Unitary test : checks the empty() method, must return 1
  
  return 0;
  
}
