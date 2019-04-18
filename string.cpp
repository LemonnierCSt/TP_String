#include <cstdlib>
#include "string.h"

string::string(size_t capacity){
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
  delete data_;
  data_=new char[capacity_+1];
  size_=1;
  data_[0]='t';data_[1]='\0';
}

//Constructor c-string (by parameter)
string::string(const char* chain){
  
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
    std::cout << "Your chain is too long : 100 char max please" << std::endl; //If the chain is too long, eroor message
  }
}

//Method length: returns the size of the string
size_t string::length(){
  return size_;
}

//Method max_size: returns the maximum size a string can reach
size_t string::max_size(){
  return MAX_SIZE;
}

//Method resize: takes in parameter the position of the last character, and shortens the string
void string::resize(size_t n, char c){

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
string:: ~string(){
  delete [] data_;
}

string::string(const string& str){
  data_= new char[str.capacity_+1];//Creation of an array in the heap.
  for (size_t i =0;i<=str.size_;i++){//copy the character sequence into it, included the '\0' char
    data_[i]=str.data_[i]; 
  }
  size_=str.size_;
  capacity_=str.capacity_;
}  

//Get capacity_ attribute
std::size_t string::capacity(){
  return this->capacity_;       // Returns the attribute capacity_ that is protected in our class
}

//Empty method
bool string::empty(){
  bool isEmpty=false;
  if(this->size_==0){ // checks the size of the string 
    isEmpty=true;     //if size_ is equal to 0, it returns isEmpty=true
    }
  return isEmpty;
}

//Getter of the current value of the string object
const char* string::c_str() const{
  return data_;
}

//Getter of the current length of the string, in terms of bytes.
size_t string::size() const{
  return size_;   
}

//Operator = string
string& string::operator= (const string& str){
  size_ = str.size_;  //changing the attributes of my string
  capacity_ = str.capacity_;
  delete [] data_;  //I delete the old data to replace it by the new one
  char* newdata = new char[size_];  //The new data_ shall be a copy, and not directly the same data
  for (size_t i = 0; i<size_+1; i++){
    newdata[i] = str.data_[i];
  }
  data_ = newdata;
  return *this;
}

//Operator + char
string operator+ (const string& lhs, char rhs){
  if (2+lhs.size_ < lhs.MAX_SIZE){
    char* mychain = new char[lhs.size_+2]; //I add a space for the '\0'
    for (size_t i =0; i < lhs.size_; i++){  //I create a new chain like the one in parameters.
      mychain[i]=lhs.data_[i];
    }
    mychain[lhs.size_]=rhs; //Adding the char
    mychain[lhs.size_+1]='\0'; //Adding the end of the string
    string newString(mychain);
    delete mychain;
    return newString;
  }
  else {
    std::cout << "If you add a char, your string would be too long" << std::endl; //Error message if the size of the string reaches MAX_SIZE.
    char* mychain = new char[1];
    mychain[0]='\0';  //data_ will be an array with no char, directly giving '\0'
    string newString(mychain);
    delete mychain;
    return newString;
  }
}

//reserve method
void string::reserve(std::size_t n){ //Changes capacity_ 
  if(n>capacity_){                   //If n is greater than capacity, changes the value of capacity_
    capacity_=n;
  }

}
//Clear
void string::clear(){
  data_[0]='\0';
  size_=0;
}

//operator = method (char* for parameter)
string string::operator=(const char* c){ // c is const because we don't change It
  int i=0;            
  do{                                   //copy of c in data_
    data_[i]=c[i];
    ++i;
  }while(c[i]!='\0');
  size_=i;                              //change of size_ with the number of elements of c
  data_[i+1]='\0';
  return *this;                         // return the current updated object
}  

string operator+(const string& lhs, const string& rhs) {

  char* newData=new char[lhs.capacity_+rhs.capacity_ +1];
  for(size_t i=0;i<lhs.size_;++i){
    newData[i]=lhs.data_[i];
  }
  for(size_t j=0;j<=(rhs.size_);++j){
    newData[j+lhs.size_]=rhs.data_[j];
  }
  string concatenate (newData);
  delete newData;
  return concatenate;
}
 
 //Operator = 
string& string::operator= (char c){
  if (capacity_<1){
    delete[] data_;
    data_= new char[2];
    capacity_=1;
  }
  data_[0]=c;
  data_[1]='\0';
  size_=1;
  
  return *this;
} 


//Operator +(char*)
string operator+ (const char*   lhs, const string& rhs){
  size_t nb_char=0;
  while(lhs[nb_char]!='\0'){//Computes the length of the char chain
    nb_char+=1;
  }
  if(nb_char>(rhs.MAX_SIZE-rhs.size_)){//CheckS that the concatenation of the lhs and rhs is not longer that MAX_SIZE
    std::cout<<"The char chain is too long, it will be shortened"<<std::endl;
    nb_char=rhs.MAX_SIZE-rhs.size_;//This allows to shorten the char chain that will be be added 
  }


  string tmp(nb_char+rhs.size_);//string object with a capacity = size of the string+ the size of the char chain
  
  if(nb_char==0){//Manages the case of a  null chain (just composed by a '\0')
    tmp.size_=0;
    tmp.data_[0]='\0';
  }else{//Manages the case of a  not null chain 
    tmp.size_=nb_char+rhs.size_;                          
    for(size_t i=0;i<nb_char+rhs.size_;++i){//copy the char chain
      tmp.data_[i]=lhs[i];
    }
    for(size_t i=nb_char;i<rhs.size_+nb_char;++i){//copy the string's char chain
      tmp.data_[i]=rhs.data_[nb_char-i];
    }
  }
      
      
  return tmp;    
}


