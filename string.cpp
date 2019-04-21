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
  for (size_t i =0;i<=str.size_;i++){//copy the character sequence into it, included the '\0' char
    data_[i]=str.data_[i]; 
  }
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

  if((n<MAX_SIZE) & (n>0)){ //Making two branches, if the size asked is possible or not 
    char* newchain = new char[n+1]; //Creating a new char[] where the new string will be put
    if (n<=size_){//If we only have to shorten the string
      for (size_t i=0; i<n; i++){
        newchain[i]=data_[i];
      }
    }
    else if (n>size_){//If it is needed to add caracters at the end
      for (size_t i=0; i<size_; i++){
        newchain[i]=data_[i];
      }
      for (size_t j=size_; j<n; j++){//Adding caracters until the size wanted is reached
        newchain[j]=c;
      }
    }
    newchain[n] = '\0';
    delete this -> data_; //Deleting the current data_ now it is not needed it any more
    size_ = n; //Redifining the atributes
    capacity_ = n;
    data_ = new char[size_ + 1];
    for (size_t j = 0; j<= size_ ; j++){
      data_[j] = newchain[j];
    }
    delete newchain;
  }
  
  else if ((n > MAX_SIZE) || (n<=0)){ //If we ask for a size too big or less than 1
    std::cout << "The size you want must be positive and less than 100" << std::endl; //error message printed
    delete this -> data_;
    data_ = new char[1];
    data_[0] ='\0'; //empty char[] returned
    size_ = 0;
    capacity_ = 1;
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
  if(n>capacity_){                   //If n is greater than capacity, changes the value of capacity_
    capacity_=n;
  }
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

    string newstring(mychain);

    delete mychain;
    return newstring;
  }
  else {
    std::cout << "If you add a char, your string would be too long" << std::endl; //Error message if the size of the string reaches MAX_SIZE.
    char* mychain = new char[1];
    mychain[0]='\0';  //data_ will be an array with no char, directly giving '\0'

    string newstring(mychain);

    delete mychain;
    return newstring;
  }
}


//Operator + string
string operator+(const string& lhs, const string& rhs) {
  char* newData=new char[lhs.capacity_+rhs.capacity_ +1];//error+TEST svp
  for(size_t i=0;i<lhs.size_;++i){
    newData[i]=lhs.data_[i];
  }
  for(size_t j=0;j<=(rhs.size_);++j){
    newData[j+lhs.size_]=rhs.data_[j];//copy the second string, including the '\0'(source d'erreur?)
  }
  string concatenate (newData);
  delete newData;
  return concatenate;
}

//Operator = string
string& string::operator= (const string& str){
  size_ = str.size_;  //changing the attributes of my string
  capacity_ = str.capacity_;
  delete [] data_;  //I delete the old data to replace it by the new one
  char* newdata = new char[size_];  //The new data_ shall be a copy, and not directly the same data//ERROR(+1!)
  for (size_t i = 0; i<size_+1; i++){
    newdata[i] = str.data_[i];
  }
  data_ = newdata;
  return *this;
}

//Operator = char*
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


//Operator = char
string& string::operator= (char c){//use clear maybe? ou empty?
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


