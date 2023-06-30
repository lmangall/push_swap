#include "../include/push_swap.h"

int	print_binary(int num)
{
	// Handling special case when num is 0
	if (num == 0)
	{
		return (0);
	}

	// Finding the number of bits required
	int numBits = 0;
	int temp = num;
	while (temp > 0)
	{
		numBits++;
		temp /= 2;
	}

	// Creating an integer to store the binary representation
	int binary = 0;
	int bitPosition = 1;

	// Converting to binary representation
	for (int i = numBits - 1; i >= 0; i--)
	{
		int bit = num % 2;
		binary += bit * bitPosition;
		bitPosition *= 10;
		num /= 2;
	}

	return (binary);
}