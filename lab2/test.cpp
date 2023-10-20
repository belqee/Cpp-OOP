#include <iostream>
#include "gtest/gtest.h"
#include "bit_array_class.h"

using namespace std;

TEST(BitArrayTest, oprtr_gaps) {
	BitArray a(4, 7);
	EXPECT_EQ(a[0], true);
	EXPECT_EQ(a[1], true);
	EXPECT_EQ(a[2], true);
	EXPECT_EQ(a[3], false);
}

TEST(BitArrayTest, tostring) {
	BitArray a(4, 7);
	EXPECT_EQ(a.to_string(), "1110");
}

TEST(BitArrayTest, swap) {
	BitArray a(4, 7);
	BitArray b(4, 1);
	
	EXPECT_EQ(a.to_string(), "1110");
	EXPECT_EQ(b.to_string(), "1000");
}

TEST(BitArrayTest, assignment) {
	BitArray a(4, 7);
	BitArray b;
	b = a;
	EXPECT_EQ(a.to_string(), "1110");
	EXPECT_EQ(b.to_string(), "1110");
}

TEST(BitArrayTest, resize) {
	BitArray a(4, 7);
	a.resize(6);
	EXPECT_EQ(a.to_string(), "111000");
	a.resize(8,1);
	EXPECT_EQ(a.to_string(), "11100011");
}

TEST(BitArrayTest, clear) {
	BitArray a(4, 7);
	a.clear();
	EXPECT_EQ(a.to_string(), "");
}

TEST(BitArrayTest, puchback) {
	BitArray a(4, 7);
	a.push_back(1);
	EXPECT_EQ(a.to_string(), "11101");
	a.push_back(1);
	EXPECT_EQ(a.to_string(), "111011");
	a.push_back(0);
	EXPECT_EQ(a.to_string(), "1110110");
}

TEST(BitArrayTest, inc_oprtr_and) {
	BitArray a(4, 1);
	BitArray b(4, 7);
	b &= a;
	EXPECT_EQ(b.to_string(), "1000");
}

TEST(BitArrayTest, inc_oprtr_or) {
	BitArray a(4, 1);
	BitArray b(4, 4);
	b |= a;
	EXPECT_EQ(b.to_string(), "1010");
}

TEST(BitArrayTest, inc_oprtr_XOR) {
	BitArray a(4, 7);
	BitArray b(4, 4);
	b ^= a;
	EXPECT_EQ(b.to_string(), "1100");
}

TEST(BitArrayTest, inc_oprtr_left_shift) {
	BitArray a(4, 9);
	a <<= 2;
	EXPECT_EQ(a.to_string(), "0100");
}

TEST(BitArrayTest, inc_oprtr_right_shift) {
	BitArray a(4, 7);
	a >>= 2;
	EXPECT_EQ(a.to_string(), "0011");
}

TEST(BitArrayTest, oprtr_left_shift) {
	BitArray a(4, 7);
	BitArray b;
	b = a << 2;
	EXPECT_EQ(a.to_string(), "1110");
	EXPECT_EQ(b.to_string(), "1000");
}

TEST(BitArrayTest, oprtr_right_shift) {
	BitArray a(4, 7);
	BitArray b;
	b = a >> 2;
	EXPECT_EQ(a.to_string(), "1110");
	EXPECT_EQ(b.to_string(), "0011");
}

TEST(BitArrayTest, set) {
	BitArray a(8, 7);
	a.set(7,1);
	EXPECT_EQ(a.to_string(), "11100001");
	a.set();
	EXPECT_EQ(a.to_string(), "11111111");
}

TEST(BitArrayTest, reset) {
	BitArray a(8, 7);
	a.reset(1);
	EXPECT_EQ(a.to_string(), "10100000");
	a.reset();
	EXPECT_EQ(a.to_string(), "00000000");
}

TEST(BitArrayTest, any) {
	BitArray a(8, 1);
	EXPECT_EQ(a.any(), true);
	a.reset();
	EXPECT_EQ(a.any(), false);
}

TEST(BitArrayTest, none) {
	BitArray a(8, 1);
	EXPECT_EQ(a.none(), false);
	a.reset();
	EXPECT_EQ(a.none(), true);
}

TEST(BitArrayTest, oprtr_inverse) {
	BitArray a(8, 1);
	EXPECT_EQ((~a).to_string(), "01111111");
}

TEST(BitArrayTest, count) {
	BitArray a(8, 1);
	a = ~a; //01111111
	EXPECT_EQ(a.count(), 7);
}

TEST(BitArrayTest, size) {
	BitArray a(8, 1);
	EXPECT_EQ(a.size(), 8);
}

TEST(BitArrayTest, empty) {
	BitArray a(8, 1);
	BitArray b;
	EXPECT_EQ(a.empty(), false);
	EXPECT_EQ(b.empty(), true);
}

TEST(BitArrayTest, oprtr_and) {
	BitArray a(8, 1);
	BitArray b(8, 7);
	BitArray c;
	c = a & b;
	EXPECT_EQ(c.to_string(), "10000000");
}

TEST(BitArrayTest, oprtr_or) {
	BitArray a(8, 1);
	BitArray b(8, 4);
	BitArray c;
	c = a | b;
	EXPECT_EQ(c.to_string(), "10100000");
}

TEST(BitArrayTest, oprtr_XOR) {
	BitArray a(8, 1);
	BitArray b(8, 7);
	BitArray c;
	c = a ^ b;
	EXPECT_EQ(c.to_string(), "01100000");
}

TEST(BitArrayTest, oprtr_eq) {
	BitArray a(8, 7);
	BitArray b(8, 7);
	BitArray c(8, 1);
	EXPECT_EQ(a == b, true);
	EXPECT_EQ(a == c, false);
}

TEST(BitArrayTest, oprtr_uneq) {
	BitArray a(8, 7);
	BitArray b(8, 7);
	BitArray c(8, 1);
	EXPECT_EQ(a != b, false);
	EXPECT_EQ(a != c, true);
}