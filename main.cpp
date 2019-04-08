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

  String str2(cap);
  std::cout<<"Test c_str:"<<std::endl;
  std::cout<<str.c_str()<<std::endl;

  std::cout<<"Test size:"<<std::endl;
  std::cout<<str.size()<<std::endl;
  str2.reserve(20);
  std::cout<<"Test reserve:"<<std::endl;
  std::cout<<(str2.capacity()==20)<<std::endl; 

  return 0;
  
}
