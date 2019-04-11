#include "String.h"
#include <iostream>
#include <cstdlib> 
#include <iostream>

int main(){
  size_t cap=10;
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

  
  char* loup = new char [5];
  loup[0]='l'; loup[1]='o'; loup[2]='u'; loup[3]='p'; loup[4]='\0';
  char* nothing = new char[5];
  nothing[0]='\0'; nothing[1]='a'; nothing[2]='b';
  char* cat = new char[4];
  cat[0]='c'; cat[1]='a'; cat[2]='t'; cat[3]='\0';
    
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
  Stringloup.resize(2,'c');
  std::cout << Stringloup.c_str() << std::endl;
  Stringloup.resize(5,'c');
  std::cout << Stringloup.c_str() << std::endl;
    
  //Test operator = string
  Stringloup = str;
  std::cout << Stringloup.c_str() << std::endl;
  Stringloup = cat;
  std::cout << Stringloup.c_str() << std::endl;
  
  //Test operator + char
  Stringloup = str + 'u' + 's';
  std::cout << Stringloup.c_str() << std::endl;
  return 0;
}
