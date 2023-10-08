#include "bit_array_class.h"
#include <iostream>
#include <string>

block_size BitArray::mirror_block(block_size& block) {
	block_size reversed_num = 0;
	for (int i = 0; i < 32; ++i) {
		if ((block & (1 << i)) != 0) {
			reversed_num |= 1 << (32 - 1 - i);
		}
	}
	return reversed_num;
}

BitArray::BitArray() {
	array_size = 1;
	head = new block_size[1];
	*head = 0;
}

BitArray::~BitArray() {
	delete[] head;
}

BitArray::BitArray(int num_bits, block_size value) {
	if (num_bits == 0) {
		array_size = 1;
		head = new block_size[1];
		*head = 0;
		bits_size = 0;
	}
	else {
		array_size = (num_bits - 1) / 8 / sizeof(unsigned long) + 1;
		head = new block_size[array_size];
		head[0] = mirror_block(value);
		bits_size = num_bits;
		for (int i = num_bits; i < 32; ++i) {
			head[0] = (~(0b10000000000000000000000000000000 >> i) & head[0]);
		}
		if (array_size > 0) {
			for (unsigned long i = 1; i < array_size; ++i) {
				head[i] = 0;
			}
		}
	}
}

BitArray::BitArray(const BitArray& b) {
	array_size = b.array_size;
	bits_size = b.bits_size;
	head = new block_size[b.array_size];
	for (unsigned int i = 0; i < b.array_size; ++i) {
		head[i] = b.head[i];
	}
}

void BitArray::swap(BitArray& b) {
	block_size* head_temp = head;
	head = b.head;
	b.head = head_temp;

	unsigned long array_size_temp = array_size;
	array_size = b.array_size;
	b.array_size = array_size_temp;

	unsigned long bits_size_temp = bits_size;
	bits_size = b.bits_size;
	b.bits_size = bits_size_temp;
}

BitArray& BitArray::operator=(const BitArray& b) {
	array_size = b.array_size;
	bits_size = b.bits_size;
	delete[] head;
	head = new block_size[b.array_size];
	for (unsigned int i = 0; i < (unsigned int)b.array_size; ++i) {
		head[i] = b.head[i];
	}
	return *this;
}

void BitArray::resize(int num_bits, bool value) {
	if (num_bits == (int)bits_size) {
		return;
	}
	unsigned long new_array_size = (num_bits - 1) / 8 / sizeof(unsigned long) + 1;
	if (num_bits > (int)bits_size) {
		if (new_array_size > array_size) {
			block_size* new_head = new block_size[new_array_size];
			for (unsigned int i = 0; i < (unsigned int)array_size; ++i) {
				new_head[i] = head[i];
			}
			for (unsigned int i = (unsigned int)array_size; i < (unsigned int)new_array_size; ++i) {
				new_head[i] = 0;
			}
			array_size = new_array_size;
			delete[] head;
			head = new_head;
		}
		if (value == 1) {
			for (unsigned int i = bits_size + 1; i < (unsigned int)num_bits + 1; ++i) {
				unsigned long position = (i - 1) / 8 / sizeof(unsigned long);
				head[position] = head[position] | (0b10000000000000000000000000000000 >> ((i % 32) - 1));
			}
		}
	}
	if (num_bits < (int)bits_size) {
		for (unsigned int i = num_bits + 1; i < (unsigned int)bits_size + 1; ++i) {
			unsigned long position = (i - 1) / 8 / sizeof(unsigned long);
			head[position] = head[position] & ~(0b10000000000000000000000000000000 >> ((i % 32) - 1));
		}
		if (new_array_size < array_size) {
			block_size* new_head = new block_size[new_array_size];
			for (unsigned int i = 0; i < new_array_size; ++i) {
				new_head[i] = head[i];
			}
			delete[] head;
			head = new_head;
			array_size = new_array_size;
		}
	}
	bits_size = num_bits;
}

void BitArray::clear() {
	delete[] head;
	head = new block_size[1];
	head[0] = 0;
	array_size = 1;
	bits_size = 0;
}

void BitArray::push_back(bool bit) {
	bits_size += 1;
	unsigned long new_array_size = (bits_size - 1) / 8 / sizeof(unsigned long) + 1;
	if (new_array_size > array_size) {

		block_size* new_head = new block_size[new_array_size];
		for (unsigned int i = 0; i < (unsigned int)array_size; ++i) {
			new_head[i] = head[i];
		}
		for (unsigned int i = (unsigned int)array_size; i < (unsigned int)new_array_size; ++i) {
			new_head[i] = 0;
		}
		array_size = new_array_size;
		delete[] head;
		head = new_head;
	}
	unsigned long position = (bits_size - 1) / 8 / sizeof(unsigned long);
	if (bit == 1) {
		head[position] = head[position] | (0b10000000000000000000000000000000 >> ((bits_size % 32) - 1));
	}
}

BitArray& BitArray::operator&=(const BitArray& b) {
	if (this->bits_size != b.bits_size) {
		throw std::exception("the sizes of the arrays do not match");
	}
	for (unsigned int i = 0; i < this->array_size; ++i) {
		this->head[i] = this->head[i] & b.head[i];
	}
	return *this;
}

BitArray& BitArray::operator|=(const BitArray& b) {
	if (this->bits_size != b.bits_size) {
		throw std::exception("the sizes of the arrays do not match");
	}
	for (unsigned int i = 0; i < this->array_size; ++i) {
		this->head[i] = this->head[i] | b.head[i];
	}
	return *this;
}

BitArray& BitArray::operator^=(const BitArray& b) {
	if (this->bits_size != b.bits_size) {
		throw std::exception("the sizes of the arrays do not match");
	}
	for (unsigned int i = 0; i < this->array_size; ++i) {
		this->head[i] = this->head[i] ^ b.head[i];
	}
	return *this;
}

BitArray& BitArray::operator<<=(int n) {
	for (int i = 0; i < n; ++i) {
		for (unsigned int j = 0; j < this->array_size; ++j) {
			bool sign = 0;
			if (j + 1 < array_size) {
				sign = 0b10000000000000000000000000000000 & head[j + 1];
			}
			head[j] = head[j] << 1;
			if (sign != 0) {
				head[j] = head[j] | 1;
			}
		}
	}
	return *this;
}

BitArray& BitArray::operator>>=(int n) {
	for (int i = 0; i < n; ++i) {
		for (unsigned int j = 0; j < this->array_size; ++j) {
			bool sign = 0;
			if (j + 1 < array_size) {
				sign = 1 & head[j];
			}
			head[j] = head[j] >> 1;
			if (sign != 0) {
				head[j + 1] = head[j + 1] | 0b10000000000000000000000000000000;
			}
		}
	}
	return *this;
}

BitArray BitArray::operator<<(int n) const {
	BitArray result = *this;
	result <<= n;
	return result;
}

BitArray BitArray::operator>>(int n) const {
	BitArray result = *this;
	result >>= n;
	return result;
}

BitArray& BitArray::set(int n, bool val) {
	if (n >= (int)bits_size) {
		return *this;
	}
	int position = (n - 1) / 8 / sizeof(unsigned long);
	if (val == 1) {
		head[position] = head[position] | 0b10000000000000000000000000000000 >> (n % 32);
	}
	if (val == 0) {
		head[position] = head[position] & ~(0b10000000000000000000000000000000 >> (n % 32));
	}
	return *this;
}

BitArray& BitArray::set() {
	for (unsigned int i = 0; i < array_size - 1; ++i) {
		head[i] = ~(unsigned int)0;
	}
	for (unsigned int i = 0; i < bits_size % 32; ++i) {
		head[array_size - 1] = head[array_size - 1] | 0b10000000000000000000000000000000 >> i;
	}
	return *this;
}

BitArray& BitArray::reset(int n) {
	if (n >= (int)bits_size) {
		return *this;
	}
	int position = (n - 1) / 8 / sizeof(unsigned long);
	head[position] = head[position] & ~(0b10000000000000000000000000000000 >> (n % 32));
	return *this;
}

BitArray& BitArray::reset() {
	for (int i = 0; i < (int)array_size; ++i) {
		head[i] = 0;
	}
	return *this;
}

bool BitArray::any() const {
	bool result = false;
	for (unsigned int i = 0; i < array_size; ++i) {
		if (head[i] != 0) {
			result = 1;
			break;
		}
	}
	return result;
}

bool BitArray::none() const {
	bool result = true;
	for (unsigned int i = 0; i < array_size; ++i) {
		if (head[i] != 0) {
			result = 0;
			break;
		}
	}
	return result;
}

BitArray BitArray::operator~() const {
	BitArray result;
	result.head = new block_size[array_size];
	result.array_size = array_size;
	result.bits_size = bits_size;
	for (unsigned int i = 0; i < array_size; ++i) {
		result.head[i] = ~head[i];
	}
	for (unsigned int i = bits_size % 32; i < 32; ++i) {
		result.head[array_size - 1] = result.head[array_size - 1] & ~(0b10000000000000000000000000000000 >> i);
	}
	return result;
}

int BitArray::count() const {
	int result = 0;
	for (unsigned long i = 0; i < array_size; ++i) {
		for (int j = 0; j < sizeof(block_size) * 8; ++j) {
			if (i * 32 + j >= bits_size) {
				break;
			}
			bool temp = head[i] & (0b10000000000000000000000000000000 >> j);
			if (temp == 1) {
				result += 1;
			}
		}
	}
	return result;
}

bool BitArray::operator[](int i) const {
	if ((unsigned int)i >= bits_size) {
		throw std::exception("out of array");
	}
	return (bool)(head[(i - 1) / 8 / sizeof(unsigned long)] & (0b10000000000000000000000000000000 >> (i % 32)));

}

int BitArray::size() const {
	return bits_size;
}

bool BitArray::empty() const {
	if (bits_size == 0) {
		return true;
	}
	return false;
}

BitArray operator&(const BitArray& b1, const BitArray& b2) {
	BitArray result;
	if (b1.size() != b2.size()) {
		return result;
	}
	result.resize(b1.size(), 1);
	result &= b1;
	result &= b2;
	return result;
}

BitArray operator|(const BitArray& b1, const BitArray& b2) {
	BitArray result;
	if (b1.size() != b2.size()) {
		return result;
	}
	result.resize(b1.size(), 0);
	result |= b1;
	result |= b2;
	return result;
}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
	BitArray result;
	if (b1.size() != b2.size()) {
		return result;
	}
	result.resize(b1.size(), 0);
	result |= b1;
	result ^= b2;
	return result;
}

bool operator==(const BitArray& a, const BitArray& b) {
	if (a.size() != b.size()) {
		return false;
	}
	if (a.to_string() == b.to_string()){
		return true;
	}
	return false;
}

bool operator!=(const BitArray& a, const BitArray& b) {
	return !(a == b);
}

std::string BitArray::to_string() const {
	std::string result = "";
	for (unsigned long i = 0; i < array_size; ++i) {
		for (int j = 0; j < sizeof(block_size) * 8; ++j) {
			if (i * 32 + j >= bits_size) {
				break;
			}
			bool temp = head[i] & (0b10000000000000000000000000000000 >> j);
			if (temp == 1) {
				result += "1";
			}
			else {
				result += "0";
			}
		}
	}
	return result;
}
