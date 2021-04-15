#pragma once
#include <iostream>
#include <iterator>
#include <stdint.h>
#include <vector>

class rolling_buffer {
public:
  rolling_buffer(uint32_t size = 9)
      : data(size), current_position_iterator{data.begin()} {}

  uint32_t push(uint32_t element) {
    if (current_position_iterator == data.end()) {
      discard();
    }
    *current_position_iterator = element;
    //data.push_back(element);
    current_position_iterator++;
    return element;
  }
  void show() {
    for (uint32_t i = 0; i < data.size(); i++) {
      std::cout << data[i] << std::endl;
    }
  }
  uint32_t size() {
    return std::distance(data.begin(), current_position_iterator);
  }
  uint32_t at(uint32_t position) { return data.at(position); }

private:
  std::vector<int> data;
  std::vector<int>::iterator current_position_iterator;
  void discard() {

    data.erase(data.begin(), data.begin() + data.capacity() / 2);
    current_position_iterator =
        data.begin() + data.capacity() / 2 + data.capacity() % 2;
    data.resize(data.capacity());
    // std::copy(data.begin() + data.size() / 2, data.end(), data.begin());
  }
};