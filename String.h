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
  //Copy constructor
    String(const String& str);
  //Get capacity_ attribute
    std::size_t capacity();
  //Getter of the current value of the string object
    const char* c_str ()const;
  //Getter of the current length of the string, in terms of bytes.
    size_t size() const;
};

#endif //STRING_
