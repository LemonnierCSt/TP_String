#include "string.h"
#include <iostream>
#include <cstdlib> 
#include <iostream>

int main(){
  size_t cap=0;
  string str(cap);

  std::cout<<(str.capacity()==1)<<std::endl;// Unitary test : checks the capacity() method, must return 1
  std::size_t cap1=15;
  string str1(cap1);
  std::cout<<(str1.empty()==false)<<std::endl;// Unitary test : checks the empty() method, must return 1

  string str2(cap);
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
  
  std::cout<<"Test operator=:"<<std::endl;
  str='c';
  std::cout<<str.c_str()<<std::endl;
 
  char loup [5]={'l','o','u','p'} ;
  char nothing[5]={'\0','a','b'};
  char work[5]={'w','o','r','k'};

  char* cat = new char[4];
  cat[0]='c'; cat[1]='a'; cat[2]='t'; cat[3]='\0';
    
  //Using constructor c-string
  string Stringloup(loup);
  string nulstr(nothing);
  string Sworking(work);
  string Scat(cat);

  //Test method length()
  std::cout << (nulstr.length()==0) << std::endl;
  std::cout << (Stringloup.length()==4) << std::endl;
  
  //Test method max_size()
  std::cout << (Stringloup.max_size()==100) << std::endl;
  std::cout << (nulstr.max_size()==100) << std::endl;
   
  //Test method resize
  Stringloup.resize(2,'c');
  std::cout << Stringloup.c_str() << std::endl;
  Stringloup.resize(5,'c');
  std::cout << Stringloup.c_str() << std::endl;
    
  //Test operator = string
  Stringloup = Sworking;
  std::cout << Stringloup.c_str() << std::endl;
  Stringloup = Scat;
  std::cout << Stringloup.c_str() << std::endl;
  
  //Test operator + char
  string Stringplus(Stringloup + 'u');
  std::cout << Stringplus.c_str() << std::endl;
  delete cat;

  //Tests operator + (char* and &string)
  std::cout<<"Test operator+:"<<std::endl;
  std::cout<<str.c_str()<<std::endl;
  char mychain[6]={'a','d','d','e','d','\0'};
  string str3=mychain+str;
  std::cout<<(str3.c_str()[5]=='c')<<std::endl;
  
  char mychain2[6]={'\0'};
  string str4=(mychain2+str);
  std::cout<<str4.c_str()<<std::endl;
  

  //Tests operator = (char*) method
  std::cout<<"Test operator = (char*): data_ and size_ "<<std::endl;
  str2=loup;
  std::cout <<"data_ value : "<< (str2.c_str()) << std::endl;
  std::cout <<"size_ value : "<< (str2.length()) << std::endl;
  
  //Test operator + (string arguments)
  std::cout<<"Test operator + (string)"<<std::endl;
  string concatStr=str1+str2;
  std::cout <<"value of concatenation: "<< concatStr.c_str()<< std::endl;


  return 0;
}
