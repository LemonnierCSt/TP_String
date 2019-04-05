#include <cstdlib>
#include "String.h"

String::String(size_t capacity){
  data_=new char[capacity];
  capacity_=capacity;
  size_=4;
  //*data_={'t','e','s','t','\0'};QUESTION 1
  data_[0]='t';data_[1]='e';data_[2]='s';data_[3]='t'; data_[4]='\0';
}

String::String(const char* chain){
  
  size_t nbchar = 0;
  while (chain[nbchar]!='\0'){  //I count the number of chars in my chain
    nbchar+=1;   
  }
  size_ = nbchar;
  if (nbchar<=100){
    if(nbchar<50){
      capacity_ = size_*2;  //If I can, I allocate twice the size_ of my chain
    } else if((nbchar>50) & (nbchar<100)){
      capacity_ = size_+1;
    }
    data_ = new char[nbchar+1]; //I add a space for the '\0'
    for (size_t i =0; i < nbchar; i++){  //I create a new chain like the one in parameters.
      data_[i]=chain[i];
    }
    data_[nbchar+1] = '\0';
    }
    else {
    std::cout << "Your chain is too long : 100 char max please" << std::endl;
  }
}

size_t String::length(){
  return size_;
}

size_t String::max_size(){
  return MAX_SIZE;
}

void String::resize(size_t n){
  if(n <= size_){
    data_[n]= '\0';
  }
}
  

