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


//Destructor
String:: ~String(){
  delete this-> data_;
}

String::String(const String& str){
  data_= new char[str.capacity_];//Creation of an array in the heap.
  for (size_t i =0;i<=str.size_;i++){//copy the character sequence into it, included the '\0' char
    data_[i]=str.data_[i]; 
  }
  size_=str.size_;
  capacity_=str.capacity_;
}  

//Get capacity_ attribute
std::size_t String::capacity(){
  return this->capacity_;       // Returns the attribute capacity_ that is protected in our class
}

//Empty method
bool String::empty(){
  bool isEmpty=false;
  if(this->size_==0){ // checks the size of the string 
    isEmpty=true;     //if size_ is equal to 0, it returns isEmpty=true
    }
  return isEmpty;
}

//Getter of the current value of the string object
const char* String::c_str() const{
  return data_;
}

//Getter of the current length of the string, in terms of bytes.
size_t String::size() const{
  return size_;   
    
}
//Clear
void String::clear(){
  delete data_;
  size_=0;
  data_[0]='\0';
  
 
}  
  


