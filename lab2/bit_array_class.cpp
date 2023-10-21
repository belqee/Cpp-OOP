#include "bit_array_class.h"
#include <iostream>
#include <string>

bytes_block BitArray::mirror_block(bytes_block& block) {
	bytes_block reversed_num = 0;
	for (int i = 0; i < sizeof(bytes_block) * 8; ++i) {
		if ((block & (1 << i)) != 0) {
			reversed_num |= 1 << (sizeof(bytes_block) * 8 - 1 - i);
		}
	}
	return reversed_num;
}

BitArray::BitArray() {
	array_size = 1;
	head = new bytes_block[1];
	*head = 0;
}

BitArray::~BitArray() {
	delete[] head;
}

BitArray::BitArray(int num_bits, bytes_block value) {
	if (num_bits == 0) {
		array_size = 1;
		head = new bytes_block[1];
		*head = 0;
		bits_size = 0;
	}
	else {
		array_size = (num_bits - 1) / 8 / sizeof(bytes_block) + 1;
		head = new bytes_block[array_size];
		head[0] = mirror_block(value);
		bits_size = num_bits;
		for (int i = num_bits; i < sizeof(bytes_block) * 8; ++i) {
			head[0] = (~(max_pow >> i) & head[0]);
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
	head = new bytes_block[b.array_size];
	for (unsigned int i = 0; i < b.array_size; ++i) {
		head[i] = b.head[i];
	}
}

void BitArray::swap(BitArray& b) {
	bytes_block* head_temp = head;
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
	if (array_size != b.array_size) {
		delete[] head;
		head = new bytes_block[b.array_size];
		array_size = b.array_size;
	}

	bits_size = b.bits_size;
	memcpy(head, b.head, sizeof(bytes_block) * b.array_size);
	return *this;
}

void BitArray::resize(int num_bits, bool value) {
	if (num_bits == (int)bits_size) {
		return;
	}
	unsigned int new_array_size = (num_bits - 1) / 8 / sizeof(bytes_block) + 1;
	if (num_bits > (int)bits_size) {
		if (new_array_size > array_size) {
			bytes_block* new_head = new bytes_block[new_array_size];
			memcpy(new_head, head, sizeof(bytes_block) * array_size);
			for (unsigned int i = array_size; i < new_array_size; ++i) {
				new_head[i] = 0;
			}
			array_size = new_array_size;
			delete[] head;
			head = new_head;
		}
		if (value == 1) {
			for (unsigned int i = bits_size + 1; i < (unsigned int)num_bits + 1; ++i) {
				unsigned int position = (i - 1) / 8 / sizeof(bytes_block);
				head[position] = head[position] | (max_pow >> ((i % (sizeof(bytes_block) * 8)) - 1));
			}
		}
	}
	if (num_bits < (int)bits_size) {
		for (unsigned int i = num_bits + 1; i < bits_size + 1; ++i) {
			unsigned long position = (i - 1) / 8 / sizeof(bytes_block);
			head[position] = head[position] & ~(max_pow >> ((i % (sizeof(bytes_block) * 8)) - 1));
		}
		if (new_array_size < array_size) {
			bytes_block* new_head = new bytes_block[new_array_size];
			memcpy(new_head, head, sizeof(bytes_block) * new_array_size);
			delete[] head;
			head = new_head;
			array_size = new_array_size;
		}
	}
	bits_size = num_bits;
}

void BitArray::clear() {
	delete[] head;
	head = new bytes_block[1];
	head[0] = 0;
	array_size = 1;
	bits_size = 0;
}

void BitArray::push_back(bool bit) {
	bits_size += 1;
	unsigned int new_array_size = (bits_size - 1) / 8 / sizeof(bytes_block) + 1;
	if (new_array_size > array_size) {
		bytes_block* new_head = new bytes_block[new_array_size];
		memcpy(new_head, head, array_size);
		for (unsigned int i = array_size; i < new_array_size; ++i) {
			new_head[i] = 0;
		}
		array_size = new_array_size;
		delete[] head;
		head = new_head;
	}
	unsigned int position = (bits_size - 1) / 8 / sizeof(bytes_block);
	if (bit == 1) {
		head[position] = head[position] | (max_pow >> ((bits_size % (sizeof(bytes_block) * 8)) - 1));
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

BitArray& BitArray::operator<<=(int n) { // этот надо бы сделать как правый сдвиг но мне уже впадлу
	if (n > (int)bits_size) {
		for (unsigned int i = 0; i < array_size; ++i) {
			head[i] = 0;
		}
	}
	for (unsigned int i = n + 1; i <= bits_size; ++i) {
		unsigned int pos = (i - 1 - n) / 8 / sizeof(bytes_block);
		if ((head[(i - 1) / 8 / sizeof(bytes_block)] & (max_pow >> ((i % (sizeof(bytes_block) * 8)) - 1))) == 0) {
			head[pos] = head[pos] & ~(max_pow >> (((i - n) % (sizeof(bytes_block) * 8)) - 1));
		}
		else {
			head[pos] = head[pos] | (max_pow >> (((i - n) % (sizeof(bytes_block) * 8)) - 1));
		}
	}
	for (unsigned int i = bits_size - n + 1; i <= bits_size; ++i) {
		unsigned int pos = (i - 1) / 8 / sizeof(bytes_block);
		head[pos] = head[pos] & ~(max_pow >> ((i - 1) % (sizeof(bytes_block) * 8)));
	}
	return *this;
}

BitArray& BitArray::operator>>=(int n) {
	if (n > (int)bits_size) {
		for (unsigned int i = 0; i < array_size; ++i) {
			head[i] = 0;
		}
	}
	int big_shift = n / (8 * sizeof(bytes_block));
	for (int i = (int)(array_size - big_shift - 1); i >= 0; --i) {
		head[i + big_shift] = head[i];
	}
	for (unsigned int i = 0; i < (unsigned int)big_shift; ++i) {
		head[i] = 0;
	}
	unsigned int small_shift = n % (8 * sizeof(bytes_block));
	if (small_shift == 0) {
		return *this;
	}
	if (big_shift != 0) {
		for (int i = (int)array_size - 1; i >= big_shift; --i) {
			head[i] = (head[i] >> small_shift) | (head[i - 1] << (sizeof(bytes_block) * 8 - small_shift));
		}
	}
	head[0] = head[0] >> small_shift;
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
	int position = (n - 1) / 8 / sizeof(bytes_block);
	if (val == 1) {
		head[position] = head[position] | max_pow >> (n % (sizeof(bytes_block) * 8));
	}
	if (val == 0) {
		head[position] = head[position] & ~(max_pow >> (n % (sizeof(bytes_block) * 8)));
	}
	return *this;
}

BitArray& BitArray::set() {
	for (unsigned int i = 0; i < array_size - 1; ++i) {
		head[i] = ~(unsigned int)0;
	}
	for (unsigned int i = 0; i < bits_size % (sizeof(bytes_block) * 8); ++i) {
		head[array_size - 1] = head[array_size - 1] | max_pow >> i;
	}
	return *this;
}

BitArray& BitArray::reset(int n) {
	if (n >= (int)bits_size) {
		return *this;
	}
	int position = (n - 1) / 8 / sizeof(bytes_block);
	head[position] = head[position] & ~(max_pow >> (n % (sizeof(bytes_block) * 8)));
	return *this;
}

BitArray& BitArray::reset() {
	for (unsigned int i = 0; i < array_size; ++i) {
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
	result.head = new bytes_block[array_size];
	result.array_size = array_size;
	result.bits_size = bits_size;
	for (unsigned int i = 0; i < array_size; ++i) {
		result.head[i] = ~head[i];
	}
	for (unsigned int i = bits_size % (sizeof(bytes_block) * 8); i < (sizeof(bytes_block) * 8); ++i) {
		result.head[array_size - 1] = result.head[array_size - 1] & ~(max_pow >> i);
	}
	return result;
}

int BitArray::count() const {
	int result = 0;
	for (unsigned int i = 0; i < array_size; ++i) {
		for (int j = 0; j < sizeof(bytes_block) * 8; ++j) {
			if (i * (sizeof(bytes_block) * 8) + j >= bits_size) {
				break;
			}
			bool temp = head[i] & (max_pow >> j);
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
	return (bool)(head[(i - 1) / 8 / sizeof(bytes_block)] & (max_pow >> (i % (sizeof(bytes_block) * 8))));
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
	BitArray result(b1);
	if (b1.size() != b2.size()) {
		throw std::exception("the sizes of the arrays do not match");
	}
	result &= b2;
	return result;
}

BitArray operator|(const BitArray& b1, const BitArray& b2) {
	BitArray result(b1);
	if (b1.size() != b2.size()) {
		throw std::exception("the sizes of the arrays do not match");
	}
	result |= b2;
	return result;
}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
	BitArray result(b1);
	if (b1.size() != b2.size()) {
		throw std::exception("the sizes of the arrays do not match");
	}
	result ^= b2;
	return result;
}

bool operator==(const BitArray& a, const BitArray& b) {
	if (a.size() != b.size()) {
		return false;
	}
	if (a.to_string() == b.to_string()) {
		return true;
	}
	return false;
}

bool operator!=(const BitArray& a, const BitArray& b) {
	return !(a == b);
}

std::string BitArray::to_string() const {
	std::string result = "";
	for (unsigned int i = 0; i < array_size; ++i) {
		for (int j = 0; j < sizeof(bytes_block) * 8; ++j) {
			if (i * (sizeof(bytes_block) * 8) + j >= bits_size) {
				break;
			}
			bool temp = head[i] & (max_pow >> j);
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
