#include <iostream>
#include <string>

using namespace std;

int main()
{
	int select, str_size, key_size;
	char str[50];
	char key[10];

	cout << "Choose a mode ( Encryption: press 1, Decryption: press 2)"
		<< " If you want to exit, Press e" << endl;

	cin >> select;

	cout << "Enter the key in 10 letters:" << endl;

	cin >> key;

	cout << "Enter the str in 100 letters:" << endl;

	cin >> str;

	str_size = strlen(str);
	key_size = strlen(key);

	for (int i = 0; i < str_size; i++)
	{
		if (select == 1)
		{
			int j = i % key_size;

			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] -= 'A';
				key[j] -= 'A';
				//if (str[i] + key[j] < 0) str[i] += 26;

				str[i] = (str[i] + key[j]) % 26;
				str[i] = str[i] + 'A';
				key[j] = key[j] + 'A';
			}

			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 'a';
				key[j] -= 'a';
				if (str[i] + key[j] < 0) str[i] += 26;

				str[i] = (str[i] + key[j]) % 26;
				str[i] = str[i] + 'a';
				key[j] = key[j] + 'a';
			}
		}
		if (select == 2)
		{
			int j = i % key_size;

			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] -= 'A';
				key[j] -= 'A';
				if (str[i] - key[j] < 0) str[i] += 26;

				str[i] = (str[i] - key[j]) % 26;
				str[i] = str[i] + 'A';
				key[j] = key[j] + 'A';
			}

			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 'a';
				key[j] -= 'a';
				if (str[i] - key[j] < 0) str[i] += 26;

				str[i] = (str[i] - key[j]) % 26;
				str[i] = str[i] + 'a';
				key[j] = key[j] + 'a';
			}
		}
	}

	cout << str << endl;
}