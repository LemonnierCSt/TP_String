#include "String.h"
#include <iostream>
#include <cstdlib> 

int main(){
  size_t cap=10;
  String str(cap);
  char loup[] = "loup";
  String Stringloup(loup);
  std::cout << Stringloup.length() << std::endl;
  std::cout << Stringloup.max_size() << std::endl;
  return 0;
}
