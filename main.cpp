#include "rollingbuffer.h"
#include <iostream>
#include <iterator>
#include <vector>
int main() {
  rolling_buffer test;

  for (uint32_t i = 0; i < 11; i++) {
    test.push(i);
  }
  test.push(33);
  return 0;
}