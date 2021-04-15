#pragma once
#include <iterator>
#include <stdint.h>
#include <vector>

class rolling_buffer {
public:
  rolling_buffer(uint32_t size = 10)
      : data(size), current_position_iterator{data.begin()} {}

  uint32_t push(uint32_t element) {
    if (current_position_iterator == data.end()) {
      discard();
    }
    *current_position_iterator = element;
    current_position_iterator++;
    return element;
  }
  uint32_t size() { return data.size(); }
  uint32_t at(uint32_t position) { return data.at(position); }

private:
  std::vector<int> data;
  std::vector<int>::iterator current_position_iterator;
  void discard() {
    std::copy(data.begin() + data.size() / 2, data.end(), data.begin());
    current_position_iterator =
        data.begin() + data.size() / 2 + data.size() % 2;
  }
};