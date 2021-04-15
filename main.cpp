#include "rollingbuffer.h"
#include <iostream>
#include <iterator>
#include <vector>
int main() {
  rolling_buffer test;

  for (uint32_t i = 0; i < 11; i++) {
    test.push(i);
  }
 
  std::cout << test.at(5);
  std::cout << std::endl << test.size();
  return 0;
}