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
  //Constructor with the capacity
    String(std::size_t capacity);
  //Constructor c-string
    String(const char* chain);
  //Method length
    size_t length();
  //Method max_size
    size_t max_size();
  //Method resize
    void resize(size_t n);

  //Destructor
    ~String();
  //Get capacity_ attribute
    std::size_t capacity();
  //empty method
    bool empty();
  //Copy constructor
    String(const String& str);
  //Getter of the current value of the string object
    const char* c_str ()const;
  //Getter of the current length of the string, in terms of bytes.
    size_t size() const;
  //Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
    void clear();
  //Operator = 
    String& operator= (char c);

};

#endif //STRING_
