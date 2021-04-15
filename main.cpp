#include "rollingbuffer.h"
#include <iostream>
#include <iterator>
#include <vector>
int main() {
  rolling_buffer test;
  for (uint32_t i = 1; i < 12; i++) {
  }
 for (uint32_t i = 0; i < 11; i++) {
    test.push(i);
  }
  return 0;
}