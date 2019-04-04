#include <cstdlib>
#include <iostream>
#ifndef STRING_
#define STRING_

class String{
  
  protected:
  char* data_;
  size_t size_;
  size_t capacity_;
  static const size_t MAX_SIZE=100;
  
  public:
  //Constructors
    String(size_t capacity);
    String(const char* chain);
    
    
  //Methods
    size_t length();
    size_t max_size();
};

#endif //STRING_
