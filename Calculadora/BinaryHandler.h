#pragma once
#include <bitset>
#include <stack>
#include <string>

using namespace std;

class BinaryHandler
{
private:
	int original;
	bitset<32> binary;
	stack<char> storedBits;
	string bits;
	bool symbol;
public:
	BinaryHandler();
	~BinaryHandler();
	void Convert(stack<char> input);
	void FillArray(int number);
	bitset<32> getBinary(int number);
	bitset<32> add(bitset<32> a, bitset<32> b, int position = 0, bitset<1> carry = 0);
	bitset<32> substract(bitset<32> a, bitset<32> b, int position = 0, bitset<1> carry = 0);
	bitset<32> multiply(bitset<32> a, bitset<32> b, bitset<32> carry = 0);
	string ToString();
	string ToString(int number);
};

