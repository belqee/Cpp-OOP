
#include "module2.h"
#include "gtest/gtest.h"

namespace {

// TODO: переименовать тесты, написать реализации
TEST(TaskTest, getMyName) {
    using Module1::getMyName;

    EXPECT_EQ(getMyName(), "John");
}

}