#include "String.h"
#include <iostream>
#include <cstdlib> 
#include <iostream>

int main(){
  size_t cap=0;
  String str(cap);

  std::cout<<(str.capacity()==1)<<std::endl;// Unitary test : checks the capacity() method, must return 1
  std::size_t cap1=15;
  String str1(cap1);
  std::cout<<(str1.empty()==false)<<std::endl;// Unitary test : checks the empty() method, must return 1

  String str2(cap);
  std::cout<<"Test c_str:"<<std::endl;
  std::cout<<str.c_str()<<std::endl;

  std::cout<<"Test size:"<<std::endl;
  std::cout<<str.size()<<std::endl;

  std::cout<<"Test clear:"<<std::endl;
  std::cout<<str.c_str()<<std::endl;
  str.clear();
  std::cout<<str.c_str()<<std::endl;
  
  std::cout<<"Test operator=:"<<std::endl;
  str='c';
  std::cout<<str.c_str()<<std::endl;
 
  char loup [5]={'l','o','u','p'} ;
  char nothing[5]={'\0','a','b'};
  
  //Using constructor c-string
  String Stringloup(loup);
  String nulstr(nothing);
  
  
  //Test method length()
  std::cout << (nulstr.length()==0) << std::endl;
  std::cout << (Stringloup.length()==4) << std::endl;
  
  //Test method max_size()
  std::cout << (Stringloup.max_size()==100) << std::endl;
  std::cout << (nulstr.max_size()==100) << std::endl;
   
  //Test method resize --> I need data_
  Stringloup.resize(2);
  
  
  std::cout<<"Test operator+:"<<std::endl;
  std::cout<<str.c_str()<<std::endl;
  char mychain[6]={'a','d','d','e','d','\0'};
  String str3=mychain+str;
  std::cout<<(str3.c_str()[5]=='c')<<std::endl;
  
  char mychain2[6]={'\0'};
  String str4=(mychain2+str);
  std::cout<<str4.c_str()<<std::endl;
  return 0;
}
