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
  str2.reserve(20);
  std::cout<<"Test reserve:"<<std::endl;
  std::cout<<(str2.capacity()==20)<<std::endl; 

  std::cout<<"Test clear:"<<std::endl;
  std::cout<<str.c_str()<<std::endl;
  str.clear();
  std::cout<<str.c_str()<<std::endl;


  
  char* loup = new char [5];
  loup[0]='l'; loup[1]='o'; loup[2]='u'; loup[3]='p'; loup[4]='\0';
  char* nothing = new char[5];
  nothing[0]='\0'; nothing[1]='a'; nothing[2]='b';
    
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
  
  //Tests operator = (char*) method
  std::cout<<"Test operator = (char*): data_ and size_ "<<std::endl;
  str2=loup;
  std::cout <<"data_ value : "<< (str2.c_str()) << std::endl;
  std::cout <<"size_ value : "<< (str2.length()) << std::endl;
  
  //Test operator + (String arguments)
  std::cout<<"Test operator + (String)"<<std::endl;
  String concatStr=str1+str2;
  std::cout <<"value of concatenation: "<< concatStr.c_str()<< std::endl;
  delete [] loup;
  delete [] nothing;
   
  return 0;
}
