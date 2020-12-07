#include <iostream>
#define BLOCK_SIZE 6
#define ROUND_NUM 2

using namespace std;

char Feistel_Enc(char input);
char Feistel_Dnc(char input);

char F1(char input);
char F2(char input);

int main()
{

	char p_bit = 0x2B;
	char c_bit, d_bit;
	int temp = 0;

	printf("평문: ");
	for (int i = BLOCK_SIZE - 1; i >= 0; i--)
	{
		temp = (p_bit >> i) & 0x01;
		printf("%d ", temp);
	}
	printf("\n");

	c_bit = Feistel_Enc(p_bit);

	printf("암호문: ");
	for (int i = BLOCK_SIZE - 1; i >= 0; i--)
	{
		temp = (c_bit >> i) & 0x01;
		printf("%d ", temp);
	}
	printf("\n");

	d_bit = Feistel_Dnc(c_bit);

	printf("복호문: ");
	for (int i = BLOCK_SIZE - 1; i >= 0; i--)
	{
		temp = (d_bit >> i) & 0x01;
		printf("%d ", temp);
	}
	printf("\n");

	return 0;
}

char Feistel_Enc(char input)
{

	char temp, left, right;

	left = (input >> 3) & 0x07;
	right = input & 0x07;

	for (int i = 0; i < ROUND_NUM; i++)
	{
		if (i == 0) left = left ^ F1(right);
		else if (i == 1) left = left ^ F2(right);

		if (i != ROUND_NUM - 1)
		{
			temp = left;
			left = right;
			right = temp;
		}
		else;
	}
	return (left << 3) | right;
}

char Feistel_Dnc(char input)
{

	char temp, left, right;

	left = (input >> 3) & 0x07;
	right = input & 0x07;

	for (int i = 0; i < ROUND_NUM; i++)
	{
		if (i == 0) left = left ^ F2(right);
		else if (i == 1) left = left ^ F1(right);

		if (i != ROUND_NUM - 1)
		{
			temp = left;
			left = right;
			right = temp;
		}
		else;
	}
	return (left << 3) | right;
}

char F1(char input)
{
	if (input == 0x00)
		return 0x05;
	else if (input == 0x01)
		return 0x02;
	else if (input == 0x02)
		return 0x03;
	else if (input == 0x03)
		return 0x06;
	else if (input == 0x04)
		return 0x04;
	else if (input == 0x05)
		return 0x01;
	else if (input == 0x06)
		return 0x07;
	else if (input == 0x07)
		return 0x00;
	else
		;
	return 0x00;
}

char F2(char input)
{
	if (input == 0x00)
		return 0x04;
	else if (input == 0x01)
		return 0x00;
	else if (input == 0x02)
		return 0x03;
	else if (input == 0x03)
		return 0x07;
	else if (input == 0x04)
		return 0x06;
	else if (input == 0x05)
		return 0x05;
	else if (input == 0x06)
		return 0x01;
	else if (input == 0x07)
		return 0x02;
	else
		;
	return 0x00;
}