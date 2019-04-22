#include <cstdlib>
#include "string.h"


string::string(size_t capacity){
  if(capacity<=0||capacity>MAX_SIZE){
    std::cout<<"The capacity resquested is either <=0 or >100, so it has been automatically set to 1"<<std::endl;
    capacity_=1;
  }else{
    capacity_=capacity;
  }
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
  if (nbchar<=MAX_SIZE){
    size_ = nbchar;
    capacity_ = nbchar;
    data_ = new char[nbchar+1]; //I add a space for the '\0'
    for (size_t i =0; i <= nbchar; i++){ //Copies the null-terminated chain into data_
      data_[i]=chain[i];
    }
  }
  else {
    std::cout << "Your chain is too long : 100 char max please" << std::endl; //If the chain is too long, error message
  }
}

//Copy constructor
string::string(const string& str){
  data_= new char[str.capacity_+1];//Creation of an array in the heap.
  for (size_t i =0;i<str.size_;i++){//copy the character sequence into it, included the '\0' char
    data_[i]=str.data_[i]; 
  }
  data_[str.size_]='\0';
  size_=str.size_;
  capacity_=str.capacity_;
}


//Destructor
string:: ~string(){
  delete [] data_;
}


//Methods:

//Method length: returns the size of the string
size_t string::length(){
  return size_;
}


//Getter of the current length of the string, in terms of bytes.
size_t string::size() const{
  return size_;   
}


//Method max_size: returns the maximum size a string can reach
size_t string::max_size(){
  return MAX_SIZE;
}

//Getter of capacity_ 
std::size_t string::capacity(){
  return this->capacity_;// Returns the attribute capacity_ that is protected in our class
}

//Getter of the current value of the string object
const char* string::c_str() const{
  return data_;
}

//Method resize: takes in parameter the size of my new string, the caracter wanted at the end if the size asked is bigger than the actual one, and resizes the string
void string::resize(size_t n, char c){


  if((n<=MAX_SIZE) & (n>0)){ //Making two branches, if the size asked is possible or not 
    if (n<=size_){           //If we only have to shorten the string
      data_[n]='\0';
    }
    else if (n>size_){       //If it is needed to add caracters at the end
      this->reserve(n);

      for (size_t j=size_; j<n; j++){//Adding caracters until the size wanted is reached
        data_[j]=c;
      }
      data_[n] = '\0';       
    }
    size_=n;
  }
  
  else if ((n > MAX_SIZE) || (n<=0)){ //If we ask for a size too big, equals to 0, or negative. We take also the case 0 because the method clear already exists to clear data_
    std::cout << "The size you want must >0 and less than 100" << std::endl; //error message is printed,but no changes in the string (according to the documentation)
  }
}


//Empty method
bool string::empty(){
  bool isEmpty=false;
  if(this->size_==0){ // checks the size of the string 
    isEmpty=true;     //if size_ is equal to 0, it returns isEmpty=true
    }
  return isEmpty;
}

//Clear
void string::clear(){
  data_[0]='\0';
  size_=0;
}

//Reserve method
void string::reserve(std::size_t n){ //Changes capacity_ 
  if(n>capacity_){
    char* tmp= data_;//Stocks the adress of the old char chain
    data_= new char[n+1];//Creates an empty array with the requested capacity
    capacity_=n;//Actualizes the capacity_ value
    for (size_t i=0; i<=size_;++i){//Copies the old char chain into the new array (including '\0')
        data_[i]=tmp[i];  
    } 
    delete [] tmp;
    
  }
}

//Operator + char
string operator+ (const string& lhs, char rhs){
  if (1+lhs.size_ <= lhs.MAX_SIZE){
    char* mychain = new char[lhs.size_+2]; //I add a space for the '\0'
    for (size_t i =0; i < lhs.size_; i++){  //I create a new chain like the one in parameters.
      mychain[i]=lhs.data_[i];
    }
    mychain[lhs.size_]=rhs; //Adding the char
    mychain[lhs.size_+1]='\0'; //Adding the end of the string
    string newstring(mychain);
    delete[] mychain;
    return newstring;
  }
  else {
    std::cout << "If you add a char, your string would be too long" << std::endl; //Error message if the size of the string reaches MAX_SIZE.
    return lhs; //The string in parameter is returned unchanged
  }
}


//Operator + string
string operator+(const string& lhs, const string& rhs) { 
  if(lhs.size_+rhs.size_>lhs.MAX_SIZE){ // if the concatenation's size_ is greater than MAX_SIZE, we only return the lhs argument 
    std::cout<<"The result is too long (of size greater than 100), the concatenation won't happen"<<std::endl;
    return lhs;
  }
  else{
  char* newData=new char[lhs.size_+rhs.size_ +1];//error+TEST svp ==> corrected w/ size_ instead of capacity_

  for(size_t i=0;i<lhs.size_;++i){
    newData[i]=lhs.data_[i];
  }
  for(size_t j=0;j<=rhs.size_;++j){
    newData[j+lhs.size_]=rhs.data_[j];//copy the second string, including the '\0'(source d'erreur?) ==> corrected but still the same  
  }
  string concatenate (newData);
  delete newData;  
  return concatenate;
  }
}

//Operator = string
string& string::operator= (const string& str){
  size_ = str.size_;  //changing the attributes of my string
  capacity_ = str.capacity_;
  delete [] data_;  //I delete the old data to replace it by the new one
  char* newdata = new char[size_+1];  //The new data_ shall be a copy, and not directly the same data//ERROR(+1!)
  for (size_t i = 0; i<size_+1; i++){
    newdata[i] = str.data_[i];
  }
  data_ = newdata;
  return *this;
}

//Operator = char*
string string::operator=(const char* c){ // c is const because we don't change It
  int i=0;          
  do{                                   
    ++i;
  }while(c[i]!='\0');
  if(i>MAX_SIZE){   // If the number of characters of c is > MAX_SIZE we "cut" at the 100th character
    size_=MAX_SIZE; 
    capacity_=MAX_SIZE;
  }
  else{
  size_=i;  //change of size_ with the number of elements of c
  capacity_=2*size_;   // We double the value of capacity by the size_
  }
  delete [] data_;
  data_=new char[size_+1];
  for(int j=0;j<=size_;++j){  //copy of c in data_(until the 100th character if c's length is greater than MAX_SIZE)
    data_[j]=c[j];
  }
  return *this;  // return the current updated object
  }                        


//Operator = char
string& string::operator= (char c){
  if (capacity_<1){
    delete[] data_;
    data_= new char[2];
  }
  data_[0]=c;
  data_[1]='\0';
  size_ = 1;
  capacity_ =1;
  return *this;
} 


//Operator +(char*)
string operator+ (const char*   lhs, const string& rhs){
  size_t nb_char=0;
  while(lhs[nb_char]!='\0'){//Computes the length of the char chain
    nb_char+=1;
  }
  if(nb_char>(rhs.MAX_SIZE-rhs.size_)){//Checks that the concatenation of the lhs and rhs is not longer than MAX_SIZE
    std::cout<<"The char chain is too long, it will be shortened"<<std::endl;
    nb_char=rhs.MAX_SIZE-rhs.size_;//This shortens the char chain that will be added 
  }

  string tmp(nb_char+rhs.size_);//string object with a capacity = size of the string+ the size of the char chain. If 0 is passed in parameter (nullchain+ null string), this non-trivial constructor migth display an warning message, but it is not causing an error.
  tmp.size_=nb_char+rhs.size_;                          
  for(size_t i=0;i<nb_char;++i){//copies the char chain in the new data_
    tmp.data_[i]=lhs[i];
  }
  for(size_t i=nb_char;i<=rhs.size_+nb_char;++i){//copies the string's char chain in data_
    tmp.data_[i]=rhs.data_[i-nb_char];

  }
  return tmp;    
}


