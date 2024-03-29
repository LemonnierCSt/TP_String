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

  // c_str test	
  string str2(cap);
  std::cout<<"Test c_str:"<<std::endl;
  std::cout<<str.c_str()<<std::endl;

  //reserve() method tests
  std::cout<<"Test size:"<<std::endl;
  std::cout<<str.size()<<std::endl;
  str2.reserve(20);
  std::cout<<"Test reserve:"<<std::endl;
  std::cout<<(str2.capacity()==20)<<std::endl; 

  //clear method test
  std::cout<<"Test clear:"<<std::endl;
  std::cout<<str.c_str()<<std::endl;
  str.clear();
  std::cout<<str.c_str()<<std::endl;

  //operator = (char) test  
  std::cout<<"Test operator=:"<<std::endl;
  str='c';
  std::cout<<str.c_str()<<std::endl;
  
  //Creation of char[] for tests
  char loup [5]={'l','o','u','p'} ;
  char nothing[5]={'\0','a','b'};
  char work[5]={'w','o','r','k'};
  char longchar[100]={'c'};
  char cat[4]={'c','a','t'};
  
  //Creating a long char to test for the maximum size
  int i = 0;
  while (i  < 100){
    longchar[i] = 'c';
    i++;
  }
  longchar[100]='\0';
  
  //Using constructor c-string
  string stringloup(loup);
  string nulstr(nothing);
  string sworking(work);
  string scat(cat);
  string maxlength(longchar);
  
  //Checking the capacity_
  std::cout << "Checking the capacity of some strings:" << std::endl;
  std::cout << (stringloup.capacity()==stringloup.length()) << std::endl;
  std::cout << (nulstr.capacity()==0) << std::endl;
  std::cout << (maxlength.capacity()==100) << std::endl;
  
  //Test method length()
  std::cout << "Test method length:" << std::endl;
  std::cout << (nulstr.length()==0) << std::endl;
  std::cout << (stringloup.length()==4) << std::endl;
  
  //Test method max_size()
  std::cout << "Test method max_size:" << std::endl;
  std::cout << (stringloup.max_size()==100) << std::endl;
  std::cout << (nulstr.max_size()==100) << std::endl;
   
  //Test method resize(size_t n, char c)
  std::cout << "Test method resize:" << std::endl;
  stringloup.resize(2,'c');
  std::cout << (stringloup.c_str()) << std::endl;
  stringloup.resize(5,'c');
  std::cout << stringloup.c_str() << std::endl;
  stringloup.resize(-3,'c');
  stringloup.resize(102,'c');
    
  //Test operator = string
  std::cout << "Test operator = string :" << std::endl;
  stringloup = sworking;
  std::cout << stringloup.c_str() << std::endl;
  stringloup = scat;
  std::cout << stringloup.c_str() << std::endl;
  
  //Test operator + char
  std::cout << "Test operator + char :" << std::endl;
  string stringplus = (stringloup + 'u');
  std::cout << stringplus.c_str() << std::endl;
  string otherplus = (maxlength + 'u');
  std::cout << otherplus.c_str() << std::endl;

  //Tests operator + (char* and &string)
  std::cout<<"Test operator+:"<<std::endl;
  std::cout<<str.c_str()<<std::endl;
  char mychain[6]={'a','d','d','e','d','\0'};
  string str3=mychain+str;
  std::cout<<(str3.c_str()[6]=='\0')<<std::endl;
  char mychain2[6]={'\0'};
  string str4=(mychain2+str);
  std::cout<<(str4.c_str()[0]=='c')<<std::endl;
  string str5=(mychain2+nulstr);
  std::cout<<(str5.c_str()[0]=='\0')<<std::endl;
  
  string str6=(mychain+maxlength);
  std::cout<<str6.c_str()<<std::endl;

  //Tests operator = (char*)
  std::cout<<"Test operator = (char*): data_ and size_ "<<std::endl;
  str2=loup;
  std::cout <<"data_ value : "<< (str2.c_str()) << std::endl;
  std::cout <<"size_ value : "<< (str2.length()) << std::endl;
  std::cout<<"Test operator = (char*) with a char* 's size equal to 100"<<std::endl;
  str2=longchar;
  std::cout <<"data_ value : "<< (str2.c_str()) << std::endl;
  std::cout <<"size_ value : "<< (str2.length()) << std::endl;
  
  //Test operator + (string arguments)
  std::cout<<"Test operator + (string)"<<std::endl;
  string concatStr=scat+scat;
  std::cout <<"value of concatenation: "<< concatStr.c_str()<< std::endl;
  std::cout<<"Test operator + (string) with concatenation's size greater than 100 : "<<std::endl;
  string concatStr2=stringloup+maxlength;
  std::cout <<"value of concatenation: "<< concatStr2.c_str()<< std::endl;


  return 0;
}
