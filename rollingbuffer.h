#pragma once
#include <iostream>
#include <iterator>
#include <stdint.h>
#include <vector>

class rolling_buffer
{
public:
    rolling_buffer(uint32_t size)

    {
        if (size == 0)
            std::invalid_argument("size=0");
        m_data.reserve(size);
    }

    uint32_t push(uint32_t element)
    {
        if (m_data.size() == m_data.capacity())
        {
            discard();
        }
        m_data.push_back(element);
        return element;
    }
    void show()
    {
        for (auto i:m_data)
        {
            std::cout << i << std::endl;
        }
    }
    uint32_t size()
    {
        return m_data.size();
    }
    uint32_t at(uint32_t position)
    {
        return m_data.at(position);
    }

private:
    std::vector<int> m_data;
    void discard()
    {
        m_data.erase(m_data.begin(), m_data.begin() + m_data.capacity() / 2);
    }
};