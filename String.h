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
  //Constructor c-string
    String(const char* chain);
    
  //Method length
    size_t length();
  //Method max_size
    size_t max_size();
  //Method resize
    void resize(size_t n);
    
};

#endif //STRING_
