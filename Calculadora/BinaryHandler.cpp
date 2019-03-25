#include "BinaryHandler.h"

BinaryHandler::BinaryHandler()
{
	bits = "";
	original = 0;
	binary = 0;

}

BinaryHandler::~BinaryHandler()
{
}

void BinaryHandler::FillArray(int number)
{
	//bool bit;
	int copy = number;
	if (copy > 0)
	{
		storedBits.push(number % 2);
		FillArray(copy / 2);
	}
	else
	{
		Convert(storedBits);
	}
}

string BinaryHandler::ToString()
{
	return bits;
}

bitset<32> BinaryHandler::getBinary(int number)
{
	bits = "";
	original = 0;
	binary = bitset<32>("0");
	storedBits = stack<char>();
	FillArray(number);
	return binary;
}

bitset<32> BinaryHandler::add(bitset<32> a, bitset<32> b, int position, bitset<1> carry)
{
	//bitset<32> c;
	if (position < 32)
	{

		binary[position] = (a[position] xor b[position]);
		//bitset<1> flag = a[position] xor b[position];
		binary[position] = binary[position] xor carry[0];
		carry[0] = (a[position] and b[position]) or (a[position] and carry[0]) or (b[position] and carry[0]);
		//add(a, b, position + 1, carry);
		return add(a, b, position + 1, carry);
		
	}
	
	return binary;
}

bitset<32> BinaryHandler::substract(bitset<32> a, bitset<32> b, int position, bitset<1> carry) //a gets b substracted, position is always 0 and carry always 0
{
	
	//bitset<32> c;
	if (position < 32)
	{
		if (a[position] == 1 && (b[position] xor carry[0]) == 1)
		{
			binary[position] = 0;
			if (carry[0] == 1)
				carry[0] = 0;
		}
		else if (a[position] == 0 && (b[position] xor carry[0]) == 1)
		{
			binary[position] = 1;
			carry[0] = 1;

		}
		else if (carry[0] and b[position] == 1)
		{
			binary[position] = a[position];
			carry [0] = 1;
		}
		else
			binary[position] = a[position];

		//carry[0] = (a[position] and b[position]) or (a[position] and carry[0]) or (b[position] and carry[0]);
		//add(a, b, position + 1, carry);
		return substract(a, b, position + 1, carry);

	}
	if (a.to_ulong() < b.to_ulong())
		return ~binary;
	else
		return binary;
}

bitset<32> BinaryHandler::multiply(bitset<32> a, bitset<32> b, bitset<32> result)
{
	if (b != 0)
	{
		result = add(result, a);
		return multiply(a, substract(b, bitset<32>("1")), result);
	}
	else
		return result;
}



void BinaryHandler::Convert(stack<char> input)
{
	if (!input.empty())
	{
		if (input.top() == true)
			bits.append(1, '1');
		else
			bits.append(1, '0');
		input.pop();
		Convert(input);
	}
	else
	{
		
		binary = bitset<32>(bits);
	}
	
}



