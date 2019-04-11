#include <cstdlib>
#include "String.h"

String::String(size_t capacity){
  data_=new char[capacity+1];
  capacity_=capacity;
  size_=4;
  //*data_={'t','e','s','t','\0'};QUESTION 1
  data_[0]='t';data_[1]='e';data_[2]='s';data_[3]='t'; data_[4]='\0';
  if(capacity<=0||capacity>MAX_SIZE){
    std::cout<<"The capacity resquested is either <=0 or >100, so it have been automatically set to 1"<<std::endl;
    capacity_=1;
  }else{
    capacity_=capacity;// storage space currently allocated for the string (without the \0)
  }
  data_=new char[capacity_+1];
  size_=1;
  data_[0]='t';data_[1]='\0';
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
      capacity_ = size_;
    }
    data_ = new char[nbchar+1]; //I add a space for the '\0'
    for (size_t i =0; i < nbchar; i++){  //I create a new chain like the one in parameters.
      data_[i]=chain[i];
    }
    data_[nbchar] = '\0';//WHAT data_[nbchar+1] = '\0';
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
  delete [] data_;
}

String::String(const String& str){
  data_= new char[str.capacity_+1];//Creation of an array in the heap.
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
//Clear
void String::clear(){
  data_[0]='\0';
  size_=0;
}

//operator = method (char* for parameter)
String String::operator=(const char* c){ // c is const because we don't change It
  int i=0;            
  do{                                   //copy of c in data_
    data_[i]=c[i];
    ++i;
  }while(c[i]!='\0');
  size_=i;                              //change of size_ with the number of elements of c
  data_[i+1]='\0';
  return *this;                         // return the current updated object
}  

String operator+(const String& lhs, const String& rhs) {

  char* newData=new char[lhs.capacity_+rhs.capacity_ +1];
  for(int i=0;i<lhs.size_;++i){
    newData[i]=lhs.data_[i];
  }
  for(int j=0;j<=(rhs.size_);++j){
    newData[j+lhs.size_]=rhs.data_[j];
  }
  String concatenate (newData);
  delete newData;
  return concatenate;
}
 
 //Operator = 
String& String::operator= (char c){
  if (capacity_<1){
    delete[] data_;
    data_= new char[2];
    capacity_=1;
  }
  data_[0]=c;
  data_[1]='\0';
  return *this;
} 



