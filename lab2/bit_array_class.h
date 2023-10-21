#include <iostream>
#include <string>

typedef unsigned int bytes_block;
class BitArray
{
private: 
	bytes_block* head = nullptr;
	unsigned int array_size = 0;
	unsigned int bits_size = 0;
	const bytes_block max_pow = bytes_block(1 << (sizeof(bytes_block) * 8 - 1));
	//This method takes a block of type block_size and returns 
	//the reversed version of the block.It iterates through 
	//each bit in the block and constructs a new block with the bits reversed.
	bytes_block mirror_block(bytes_block& block);
public:

	//This is the default constructor for the BitArray class. 
	//It initializes the array size to 1 and creates 
	//a new array with a single block. The block is set to 0.
	BitArray();

	//This is the destructor for the BitArray class.
	//It frees the memory allocated for the array.
	~BitArray();

	//This constructor creates a BitArray object with 
	//the specified number of bits and initializes it for the 
	//first sizeof(int) bits with the given value. 
	//If the number of bits is 0, it creates an empty array with a single block set to 0.
	explicit BitArray(int num_bits, bytes_block value = 0);

	//Copy constructor for the BitArray class.
	//b is the BitArray object to be copied.
	BitArray(const BitArray& b);

	//This method swaps the contents of two BitArray objects.
	//It swaps the array pointers, array sizes, and bit sizes
	//between the current object and the object passed as an argument.
	void swap(BitArray& b);


	//This assignment operator assigns the contents of one BitArray 
	//object to another. It copies the array size, bit size, 
	//and array elements from the source object to the current object.
	BitArray& operator=(const BitArray& b);

	//Resizes the BitArray to the specified number of bits.
	//num_bits the new number of bits for the BitArray.
	//value is the value to fill the new bits with (default is false).
	void resize(int num_bits, bool value = false);
	
	//Clears the BitArray, setting its size equal to zero, deallocating the memory
	void clear();

	//This method appends a single bit to the end of the BitArray. 
	//It increases the bit size by 1 and adjusts the array size if necessary.
	//The new bit is added to the last block in the array.
	void push_back(bool bit);


	//This compound assignment operator performs a bitwise AND operation between
	//the current BitArray and another BitArray object. It modifies the current object
	//by performing the bitwise AND operation on each corresponding block.
	BitArray& operator&=(const BitArray& b);

	//This compound assignment operator performs a bitwise OR operation between
	//the current BitArray and another BitArray object. It modifies the current object
	//by performing the bitwise OR operation on each corresponding block.
	BitArray& operator|=(const BitArray& b);

	//This compound assignment operator performs a bitwise OR operation between
	//the current BitArray and another BitArray object. It modifies the current object
	//by performing the bitwise XOR operation on each corresponding block.
	BitArray& operator^=(const BitArray& b);
	

	//This compound assignment operator performs a left shift operation 
	//on the BitArray by the specified number of bits.
	//It shifts the bits in each block to the left and fills the empty bits with 0.
	BitArray& operator<<=(int n);

	//This compound assignment operator performs a right shift operation
	// on the BitArray by the specified number of bits.
	// It shifts the bits in each block to the right and fills the empty bits with 0.
	BitArray& operator>>=(int n);

	//This method returns a new BitArray object that is the result of
	//performing a left shift operation on the current BitArray
	//by the specified number of bits. The current object is not modified.
	BitArray operator<<(int n) const;

	//This method returns a new BitArray object that is the result of
	//performing a right shift operation on the current BitArray
	//by the specified number of bits. The current object is not modified.
	BitArray operator>>(int n) const;


	//This method sets the value of the bit at the specified index to the specified value.
	// If the index is out of range, the method does nothing.
	BitArray& set(int n, bool val = true);

	//This method sets all the bits in the BitArray to true.
	BitArray& set();

	//This method resets the value of the bit at the specified index to 0.
	//If the index is out of range, the method does nothing.
	BitArray& reset(int n);

	//This method resets all the bits in the BitArray to false.
	BitArray& reset();

	//This method returns the true if array contain any true value, else it returns false.
	bool any() const;
	
	//This method returns the true if array consists of false, else it returns false.
	bool none() const;
	
	//This method returns a new BitArray object that is the result of performing
	//a bitwise NOT operation on the current BitArray. The current object is not modified.
	BitArray operator~() const;
	
	//This method counts the number of bits set to 1 in the BitArray and returns the count.
	int count() const;

	//This method returns the value of the bit at the specified index.
	//If the index is out of range, it throws an exception.
	bool operator[](int i) const;

	//This method returns the number of bits in the BitArray.
	int size() const;

	//This method checks if the BitArray is empty.
	//It returns true if the BitArray is empty, otherwise it returns false.
	bool empty() const;

	//¬озвращает строковое представление массива.
	std::string to_string() const;
};

//This operator performs a bitwise AND operation between two BitArray objects
//and returns the result as a new BitArray object.
//The sizes of the two BitArray objects must match.
BitArray operator&(const BitArray& b1, const BitArray& b2);

//This operator performs a bitwise OR operation between two BitArray objects
//and returns the result as a new BitArray object.
//The sizes of the two BitArray objects must match.
BitArray operator|(const BitArray& b1, const BitArray& b2);

//This operator performs a bitwise XOR operation between two BitArray objects
//and returns the result as a new BitArray object.
//The sizes of the two BitArray objects must match.
BitArray operator^(const BitArray& b1, const BitArray& b2);

//This operator checks if two BitArray objects are equal.
//It returns true if the sizes and bit values of the two objects are the same, otherwise it returns false.
bool operator==(const BitArray& a, const BitArray& b);

//This operator checks if two BitArray objects are not equal.
//It returns true if the sizes and bit values of the two objects are the different, otherwise it returns false.
bool operator!=(const BitArray& a, const BitArray& b);

