#include <cstdlib>
#include <iostream>
#ifndef STRING_
#define STRING_

class String{

  friend String operator+ (const char*   lhs, const String& rhs);
  
  friend String operator+ (const String& lhs, char rhs); 

  friend String operator+(const String& lhs, const String& rhs);
  
  protected:
  char* data_;
  size_t size_;
  size_t capacity_;//storage space currently allocated for the string (without the \0)
  static const size_t MAX_SIZE=100;//maximum length the string can reach.
  
  public:
  //Constructors
    String(std::size_t capacity); 
  //Constructor c-String
    String(const char* chain);
  //Method length
    size_t length();
  //Method max_size
    size_t max_size();
  //Method resize
    void resize(size_t n, char c);

  //Destructor
    ~String();
  //Get capacity_ attribute
    std::size_t capacity();
  //empty method
    bool empty();
  //Copy constructor
    String(const String& str);
  //Getter of the current value of the String object
    const char* c_str ()const; 
  //Operator = String
    String& operator= (const String& str);

  //Getter of the current length of the string, in terms of bytes.
    size_t size() const;

  // reserve method
    void reserve(std::size_t n);

  //Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
    void clear();  
    
  // operator = method ( cha* for parameter)
    String operator=(const char* c);
    
  //Operator = 
    String& operator= (char c);

  

};
/*  
 //Operator +(char*)
    String operator+ (const char*   lhs, const String& rhs);
  //Operator+ (&String+&String)
    String operator+(const String& lhs, const String& rhs);
  //Operator + char
    String operator+ (const String& lhs, char rhs); 
*///Useless?
#endif //STRING_
