#include <iostream>
#define N 3

using namespace std;

int main()
{
	char text[20];
	char c_text[20];
	char tmp_text[N][10];

	cout << "Enter the str in 20 letters:" << endl;

	cin >> text;

	int str_size = strlen(text);

	for (int i = 0; i < str_size; i++)
	{
		if ((text[i] >= 'a') && (text[i] <= 'z') || (text[i] >= 'A') && (text[i] <= 'Z'))
		{

			if (i % 2 == 0)
				tmp_text[0][i / 2] = text[i];
			else
				tmp_text[1][i / 2] = text[i];
		}

	}

	if (str_size % 2 == 0)
	{
		for (int i = 0; i < str_size / 2; i++)
		{
			c_text[i] = tmp_text[0][i];
			c_text[i + str_size / 2] = tmp_text[1][i];

		}
	}

	else
	{
		for (int i = 0; i < str_size / 2; i++)
		{
			c_text[i] = tmp_text[0][i];
			c_text[i + str_size / 2 + 1] = tmp_text[1][i];
		}
		c_text[str_size / 2] = tmp_text[0][str_size / 2];
	}
	c_text[str_size] = '\0';
	cout << c_text << endl;
}

