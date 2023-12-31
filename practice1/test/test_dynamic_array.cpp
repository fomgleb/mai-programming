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

    DynamicArray arr2(0);
}

TEST(DynamicArrayTest, get) {
    DynamicArray arr(5);
    DynamicArray arr2(0);
}

TEST(DynamicArrayTest, Constructor_InitializerList) {
    DynamicArray arr1{42, 29};
    EXPECT_EQ(arr1.get(0), 42);
    EXPECT_EQ(arr1.get(1), 29);
    EXPECT_EQ(arr1.getSize(), 2);

    DynamicArray arr2{};
    EXPECT_EQ(arr2.getSize(), 0);

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

TEST(DynamicArrayTest, pushBack) {
    DynamicArray arr(0);
    arr.pushBack(12);
    EXPECT_EQ(arr.get(0), 12);
    EXPECT_EQ(arr.getSize(), 1);

    DynamicArray arr2(3);
    arr2.set(0, 43);
    arr2.set(2, 99);
    arr2.pushBack(57);
    EXPECT_EQ(arr2.get(0), 43);
    EXPECT_EQ(arr2.get(1), 0);
    EXPECT_EQ(arr2.get(2), 99);
    EXPECT_EQ(arr2.get(3), 57);
    EXPECT_EQ(arr2.getSize(), 4);
}

TEST(DynamicArrayTest, add) {
    DynamicArray arr1{38, 30, -1};
    DynamicArray arr2{0, 11, 84, 92};
    arr1.add(arr2);
    EXPECT_EQ(arr1.get(0), 38);
    EXPECT_EQ(arr1.get(1), 41);
    EXPECT_EQ(arr1.get(2), 83);
    EXPECT_EQ(arr1.getSize(), 3);

    DynamicArray arr3(0);
    DynamicArray arr4(0);
    arr3.add(arr4);
    EXPECT_EQ(arr3.getSize(), 0);

    DynamicArray arr5{42};
    DynamicArray arr6{6, 32, 0, 23};
    arr5.add(arr6);
    EXPECT_EQ(arr5.get(0), 48);
    EXPECT_EQ(arr5.getSize(), 1);
}

TEST(DynamicArrayTest, subtract) {
    DynamicArray arr1{38, 30, -1};
    DynamicArray arr2{0, 11, 84, 92};
    arr1.subtract(arr2);
    EXPECT_EQ(arr1.get(0), 38);
    EXPECT_EQ(arr1.get(1), 19);
    EXPECT_EQ(arr1.get(2), -85);
    EXPECT_EQ(arr1.getSize(), 3);

    DynamicArray arr3(0);
    DynamicArray arr4(0);
    arr3.subtract(arr4);
    EXPECT_EQ(arr3.getSize(), 0);

    DynamicArray arr5{42};
    DynamicArray arr6{6, 32, 0, 23};
    arr5.subtract(arr6);
    EXPECT_EQ(arr5.get(0), 36);
    EXPECT_EQ(arr5.getSize(), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
