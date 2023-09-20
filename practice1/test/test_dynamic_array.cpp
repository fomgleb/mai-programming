#include "gtest/gtest.h"
#include "dynamic_array.hpp"

TEST(DynamicArrayTest, SetGetValue) {
    DynamicArray arr(5);
    arr.set(0, 50);
    EXPECT_EQ(arr.get(0), 50);
    arr.set(4, 100);
    EXPECT_EQ(arr.get(4), 100);
    arr.set(2, -100);
    EXPECT_EQ(arr.get(2), -100);
    arr.set(0, 1);
    EXPECT_EQ(arr.get(0), 1);
}

TEST(DynamicArrayTest, set) {
    DynamicArray arr(5);
    EXPECT_THROW(arr.set(5, 50), std::out_of_range);
    EXPECT_THROW(arr.set(1, 101), std::out_of_range);
    EXPECT_THROW(arr.set(2, -101), std::out_of_range);

    DynamicArray arr2(0);
    EXPECT_THROW(arr2.set(0, 1), std::out_of_range);
}

TEST(DynamicArrayTest, get) {
    DynamicArray arr(5);
    EXPECT_THROW(arr.get(5), std::out_of_range);
    DynamicArray arr2(0);
    EXPECT_THROW(arr2.get(0), std::out_of_range);
}

TEST(DynamicArrayTest, Copying) {
    DynamicArray arr(8);
    arr.set(3, 83);
    arr.set(7, 12);
    DynamicArray arr_copy(arr);
    EXPECT_EQ(arr_copy.getSize(), arr.getSize());
    for (size_t i = 0; i < arr.getSize(); ++i) {
        EXPECT_EQ(arr_copy.get(i), arr.get(i));
    }

    DynamicArray arr2(0);
    DynamicArray arr2_copy(arr2);
    EXPECT_EQ(arr2_copy.getSize(), arr2.getSize());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}










// std::string redirect_cout(std::function<void()> func) {
//     std::streambuf* coutStream = std::cout.rdbuf();
//     std::ostringstream tempStream;
//     std::cout.rdbuf(tempStream.rdbuf());

//     func();

//     std::cout.rdbuf(coutStream);

//     return tempStream.str();
// }
