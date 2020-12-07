#include <iostream>
#define BLOCK_SIZE 6

using namespace std;

int main()
{
	int size, block_num, select;
	int key[BLOCK_SIZE] = { 3, 5, 1, 6, 4, 2 };
	//string p_text, c_text, d_text, key;
	char p_text[100] = { '\0', }, c_text[100] = { '\0', }, d_text[100] = { '\0', };


	cout << "문장 입력" << endl;

	cin >> p_text;

	size = strlen(p_text);
	//size = p_text.size();

	if (size % BLOCK_SIZE != 0)
	{
		block_num = size / BLOCK_SIZE + 1;

		for (int i = size; i < size * BLOCK_SIZE; i++) 
			p_text[i] = 'x';
			
	}
	else block_num = size / BLOCK_SIZE;

	//key = "351642";

	for (int i = 0; i < block_num; i++)
	{
		for (int j = 0; j < BLOCK_SIZE; j++)
			c_text[i * BLOCK_SIZE + j] = p_text[(key[j] - 1) + i * BLOCK_SIZE];
	}

	cout << c_text;
}