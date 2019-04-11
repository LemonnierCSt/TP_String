#include <cstdlib>
#include "String.h"

String::String(size_t capacity){
  data_=new char[capacity];
  capacity_=capacity;
  size_=4;
  //*data_={'t','e','s','t','\0'};QUESTION 1
  data_[0]='t';data_[1]='e';data_[2]='s';data_[3]='t'; data_[4]='\0';
}

//Constructor c-string (by parameter)
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
      capacity_ = size_+1;  //If I can't, I allocate one space more than the size of my chain
    }
    data_ = new char[nbchar+1]; //I add a space for the '\0'
    for (size_t i =0; i < nbchar; i++){  //I create a new chain like the one in parameters.
      data_[i]=chain[i];
    }
    data_[nbchar+1] = '\0'; //I add '\0' to end the string
    }
    else {
    std::cout << "Your chain is too long : 100 char max please" << std::endl; //If the chain is too long, eroor message
  }
}

//Method length: returns the size of the string
size_t String::length(){
  return size_;
}

//Method max_size: returns the maximum size a string can reach
size_t String::max_size(){
  return MAX_SIZE;
}

//Method resize: takes in parameter the position of the last character, and shortens the string
void String::resize(size_t n, char c){

  if(n <= size_){ //if we want to shortten the chain
    char* newchain = new char[n+1];  //I create a new char[], and copy the old data_ in it
    size_ = n;
    for (size_t i = 0; i<size_; i++){
      newchain[i] = data_[i];
    }
    newchain[n]= '\0';
    delete this -> data_;  //I delete the old data_ and replace it by the new one
    data_ = new char[size_ + 1];
    for (size_t j = 0; j<= size_ ; j++){
      data_[j] = newchain[j];
    }
    delete newchain;
  }
  
  else if((n > size_) & (size_+1 < MAX_SIZE)){ //if we want to have a longer chain
    char* newchain = new char[n+1];
    for (size_t i = 0; i<size_; i++){
      newchain[i]=data_[i];
    }
    delete this-> data_;
    data_ = new char[size_ + 1];
    for (size_t i = 0; i<size_; i++){
      data_[i]=newchain[i];
    }
    for (size_t j = size_; j<n; j++){
      data_[j]=c;
    }
    data_[n]='\0';
    size_ = n;
    capacity_ = n+1;
    delete newchain;
  } 
  
  else if (n > MAX_SIZE){ //If we ask for a size too big
    std::cout << "The size you want is bigger than the maximum size" << std::endl; //message printed
    delete this -> data_;
    data_ = new char[1];
    data_[0] ='\0'; //empty char[]
    size_ = 0;
    capacity_ = 1;
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

//Operator = string
String& String::operator= (const String& str){
  size_ = str.size_;  //changing the attributes of my string
  capacity_ = str.capacity_;
  delete [] data_;  //I delete the old data to replace it by the new one
  char* newdata = new char[size_];  //The new data_ shall be a copy, and not directly the same data
  for (size_t i = 0; i<size_; i++){
    newdata[i] = str.data_[i];
  }
  data_ = newdata;
  return *this;
}

//Operator + char
String operator+ (const String& lhs, char rhs){
  if (2+lhs.size_ < lhs.MAX_SIZE){
    char* mychain = new char[lhs.size_+3]; //I add a space for the '\0'
    for (size_t i =0; i < lhs.size_; i++){  //I create a new chain like the one in parameters.
      mychain[i]=lhs.data_[i];
    }
    mychain[lhs.size_]=rhs; //Adding the char
    mychain[lhs.size_+1]='\0'; //Adding the end of the string
    String newstring(mychain);
    return newstring;
  }
  else {
    std::cout << "If you add a char, your string would be too long" << std::endl; //Error message if the size of the string reaches MAX_SIZE.
    char* mychain = new char[1];
    mychain[0]='\0';  //data_ will be an array with no char, directly giving '\0'
    String newstring(mychain);
    return newstring;
  }
}

