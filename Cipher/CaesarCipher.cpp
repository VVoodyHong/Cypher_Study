#include <iostream>
#include <string>
using namespace std;

int main()
{
	int key, mode;
	char str[100];

	while (1)
	{
		cout << "Choose a mode ( Encryption: press 1, Decryption: press 2)"
			<< " If you want to exit, Press e" << endl;

		cin >> mode;

		if (mode != 1 && mode != 2) { cout << "bye!" << endl; break; }

		switch (mode)
		{
		case 1:
		{
			cout << "Enter the key:" << endl;
			cin >> key;

			cout << endl;

			cout << "Enter the string:" << endl;
			cin >> str;

			for (int i = 0; i < strlen(str); i++)
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
				{
					str[i] = str[i] - 'A';
					if (str[i] + key < 0)
						str[i] = str[i] + 26;
					str[i] = (str[i] + key) % 26;
					str[i] += 'A';
				}

				else if (str[i] >= 'a' && str[i] <= 'z')
				{
					str[i] = str[i] - 'a';
					if (str[i] + key < 0)
						str[i] = str[i] + 26;
					str[i] = (str[i] + key) % 26;
					str[i] += 'a';
				}
			}

			cout << str << endl;
		}; break;

		case 2:
		{
			cout << "Enter the key:" << endl;
			cin >> key;

			cout << endl;

			cout << "Enter the string:" << endl;
			cin >> str;

			for (int i = 0; i < strlen(str); i++)
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
				{
					str[i] = str[i] - 'A';
					if (str[i] - key < 0)
						str[i] = str[i] + 26;
					str[i] = (str[i] - key) % 26;
					str[i] += 'A';
				}

				else if (str[i] >= 'a' && str[i] <= 'z')
				{
					str[i] = str[i] - 'a';
					if (str[i] - key < 0)
						str[i] = str[i] + 26;
					str[i] = (str[i] - key) % 26;
					str[i] += 'a';
				}
			}

			cout << str << endl;
		}; break;
		}
	}
}