
#include "module3.h"
#include "gtest/gtest.h"

namespace {

// TODO: переименовать тесты, написать реализации
TEST(TaskTest, getMyName3) {
    using Module3::getMyName;

    EXPECT_EQ(getMyName(), "Peter");
}

}