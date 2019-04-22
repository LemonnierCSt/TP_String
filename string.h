#include <cstdlib>
#include <iostream>
#ifndef STRING_
#define STRING_

class string{

// The following operators are not part of the string class, but are friends of her: they will thereby be able to use easily it's attributes

  //Operator + char*
  friend string operator+ (const char*   lhs, const string& rhs);
  //Operator + char
  friend string operator+ (const string& lhs, char rhs); 
  //Operator + string
  friend string operator+ (const string& lhs, const string& rhs);
  
  protected:
  char* data_;
  size_t size_;
  size_t capacity_;//storage space currently allocated for the string (without the \0)
  static const size_t MAX_SIZE=100;//maximum length the string can reach.
  
  public:
  //Constructor with capacity
    string(std::size_t capacity); 
  //Constructor c-string
    string(const char* chain);  
  //Copy constructor
    string(const string& str);
  //Destructor
    ~string();  
    
  //Method length, getter of the current length of the string
    size_t length();  
  //Getter of the current length of the string, in terms of bytes.
    size_t size() const;
  //Resize method
    void resize(size_t n, char c);
  //Get capacity_ attribute
    std::size_t capacity();
  //Max_size method
    size_t max_size();     
  //Getter of the current value of the string object
    const char* c_str ()const;   
  //Reserve method
    void reserve(std::size_t n);
  //empty method
    bool empty();
  //Erases the contents of the string, which becomes an empty string (with a length of 0 character).
    void clear();  
  //Operator = string
    string& operator= (const string& str);    
  //Operator = char*
    string operator= (const char* c);    
  //Operator = char
    string& operator= (char c);
};

#endif //STRING_
