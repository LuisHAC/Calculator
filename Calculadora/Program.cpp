#include <iostream>
#include "BinaryHandler.h"
using namespace std;
int main()
{
	cout << "Binary Test 1.0\n";
	BinaryHandler Binary = BinaryHandler(), Binary2 = BinaryHandler();
	bitset<32> a = Binary.getBinary(83);
	bitset<32> b = Binary.getBinary(350);
	cout << a << "\t(8)\t+\t(3)\t" << b << "\n";
	//Binary.getBinary(0);
	cout << Binary.add(a, b) << "\n";
	//Binary.getBinary(0);
	cout << Binary.substract(a, b) << "\n";
	cout << Binary.multiply(a, b) << "\n";
	//cout << 
	getchar();
};