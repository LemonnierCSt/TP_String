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
    String(const String& str);

  //Get capacity_ attribute
    std::size_t capacity();
  //Getter of the current value of the string object
    const char* c_str ()const;
  //Getter of the current length of the string, in terms of bytes.
    size_t size() const;
  //Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
    void clear();
};

#endif //STRING_
