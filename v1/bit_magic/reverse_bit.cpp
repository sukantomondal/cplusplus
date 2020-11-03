/* Author : Sukanto Mondal */

/* Reverse Bits of a Number
 *
 * Given an unsigned integer, reverse all bits of it and return the number with reversed bits.

Input : n = 1
Output : 2147483648
On a machine with size of unsigned
bit as 32. Reverse of 0....001 is
100....0.

Input : n = 2147483648
Output : 1

*/


#include<iostream>
#include<bitset>
using namespace std;

unsigned int reverse_bit (unsigned int num){
	int no_of_bits = sizeof(num) * 8;
	unsigned int reverse_num = 0;

	for(int i = 0;i < no_of_bits; i++){
	
		if((num & (1<<i))){ // if specific bit is set
			reverse_num |= 1 <<((no_of_bits -1)-i);
		}
	}

	return reverse_num;
}

/*
unsigned int reverse_bit_alt(unsigned int num){
	int no_of_bits = sizeof(num) * 8;
	unsigned int reverse_num = num;
	int count = 0;
	
	std::cout << "num = " << std::bitset<32>(num) << std::endl;

	while(num){
		reverse_num <<=1;
		num>>=1;
		std::cout << "num = " << std::bitset<32>(num) << std::endl;
		std::cout << "reverse_num = " << std::bitset<32>(reverse_num) << std::endl;
		no_of_bits--;
	}

	cout << no_of_bits << "\n";

	//for(int i = 0 ; i < no_of_bits ; i++){
	reverse_num <<= (no_of_bits-(32-no_of_bits));
	//reverse_num <<=1;
	std::cout << "reverse_num = " << std::bitset<32>(reverse_num) << std::endl;
	
	//}
	return reverse_num;
}

*/

int main (){
	unsigned int num = 10;
	cout << reverse_bit(num) << "\n";
	return 0;
}
