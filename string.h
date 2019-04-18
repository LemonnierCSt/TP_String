#include <cstdlib>
#include <iostream>
#ifndef STRING_
#define STRING_

class string{

  friend string operator+ (const char*   lhs, const string& rhs);
  
  friend string operator+ (const string& lhs, char rhs); 

  friend string operator+(const string& lhs, const string& rhs);
  
  protected:
  char* data_;
  size_t size_;
  size_t capacity_;//storage space currently allocated for the string (without the \0)
  static const size_t MAX_SIZE=100;//maximum length the string can reach.
  
  public:
  //Constructors
    string(std::size_t capacity); 
  //Constructor c-string
    string(const char* chain);
  //Method length
    size_t length();
  //Method max_size
    size_t max_size();
  //Method resize
    void resize(size_t n, char c);

  //Destructor
    ~string();
  //Get capacity_ attribute
    std::size_t capacity();
  //empty method
    bool empty();
  //Copy constructor
    string(const string& str);
  //Getter of the current value of the string object
    const char* c_str ()const; 
  //Operator = string
    string& operator= (const string& str);

  //Getter of the current length of the string, in terms of bytes.
    size_t size() const;

  // reserve method
    void reserve(std::size_t n);

  //Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
    void clear();  
    
  // operator = method ( cha* for parameter)
    string operator=(const char* c);
    
  //Operator = 
    string& operator= (char c);

  

};
/*  
 //Operator +(char*)
    string operator+ (const char*   lhs, const string& rhs);
  //Operator+ (&string+&string)
    string operator+(const string& lhs, const string& rhs);
  //Operator + char
    string operator+ (const string& lhs, char rhs); 
*///Useless?
#endif //STRING_
