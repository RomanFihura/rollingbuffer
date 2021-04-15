#include "rollingbuffer.h"
#include <iostream>
#include <iterator>
#include <vector>
int main() {
  rolling_buffer test;

  for (uint32_t i = 1; i < 11; i++) {
    test.push(i);
  }

  // std::cout << test.at(5);
  test.push(5555);
  // test.push(666);
  test.show();
  std::cout << std::endl << test.size();
  return 0;
}