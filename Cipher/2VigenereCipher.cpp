#include <iostream>

using namespace std;

int main()
{
	int str_size, key_size, select;
	char str[50];
	char key[10] = { 1, 2, 3, 4 };

	cout << "Choose a mode ( Encryption: press 1, Decryption: press 2)"
		<< " If you want to exit, Press e" << endl;

	cin >> select;

	cout << " Enther the str in 100 letters:" << endl;

	cin >> str;

	str_size = strlen(str);

	switch (select)
	{
	case 1:
		for (int i = 0; i < str_size; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				//str[i] -= 'A';
				str[i] += key[i % 4];
				//str[i] = str[i] + 'A';
			}

			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 'a';
				str[i] += key[i % 4] + 'a';
			}
		}; break;

	case 2:
		for (int i = 0; i < str_size; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] -= 'A';
				str[i] -= key[i % 4];
				str[i] = str[i] + 'A';
			}

			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 'a';
				str[i] -= key[i % 4];
				str[i] = str[i] + 'a';
			}
		}; break;
	}

	cout << str << endl;
}