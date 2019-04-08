#include <cstdlib>
#include "String.h"

String::String(std::size_t capacity){
  data_=new char[capacity];
  capacity_=capacity;
  size_=4;
  //*data_={'t','e','s','t','\0'};QUESTION 1
  data_[0]='t';data_[1]='e';data_[2]='s';data_[3]='t'; data_[4]='\0';
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

//reserve method
void String::reserve(std::size_t n){ //Changes capacity_ 
  if(n>capacity_){                   //If n is greater than capacity, changes the value of capacity_
    capacity_=n;
  }

}
  
  

