#include "rollingbuffer.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(rollingbuffer, size)
{

    rolling_buffer test(10);
    for (uint32_t i = 1; i < 12; i++)
    {
        test.push(i);
    }
    EXPECT_NE(12, test.size());
    EXPECT_EQ(6, test.size());
}
TEST(rollingbuffer, position)
{

    rolling_buffer test(10);
    for (uint32_t i = 0; i < 10; i++)
    {
        test.push(i);
        EXPECT_EQ(i, test.at(i));
    }
}
TEST(rollingbuffer, afterdiscard)
{

    rolling_buffer test(10);
    for (uint32_t i = 0; i < 11; i++)
    {
        test.push(i);
    }
    EXPECT_EQ(10, test.at(5));
}
TEST(rollingbuffer, size_after_discard)
{

    rolling_buffer test(10);
    for (uint32_t i = 0; i < 11; i++)
    {
        test.push(i);
    }
    EXPECT_EQ(6, test.size());
}
