#include <cstdlib>

#ifndef STRING_
#define STRING_

class String{
  
  protected:
  char* data_;
  std::size_t size_;
  std::size_t capacity_;
  static const std::size_t MAX_SIZE=100;
  
  public:
  //Constructors
    String(std::size_t capacity);
  //Destructor
    ~String();
  //Get capacity_ attribute
    std::size_t capacity();
  //empty method
    bool empty();
    
};

#endif //STRING_
