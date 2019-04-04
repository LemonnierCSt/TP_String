#include <cstdlib>
#include "String.h"

String::String(std::size_t capacity){
  data_=new char[capacity];
  capacity_=capacity;
  size_=4;
  //*data_={'t','e','s','t','\0'};QUESTION 1
  data_[0]='t';data_[1]='e';data_[2]='s';data_[3]='t'; data_[4]='\0';
}




  
  

