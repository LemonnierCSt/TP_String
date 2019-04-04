#include "String.h"
#include <iostream>
#include <cstdlib> 

int main(){
  std::size_t cap=10;
  String str(cap);
  char loup[] = "loup";
  String Stringloup(loup);
  std::cout << Stringloup.length() << std::endl;
  return 0;
}
