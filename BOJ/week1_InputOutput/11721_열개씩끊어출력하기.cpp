#include <iostream>
using namespace std;

int main()
{
		int		i, sum;
		string str;

		sum = 0;
		i = 0;
		cin >> str;
		while (str[i] != '\0')
		{
				cout << str[i];
				if (!((i + 1) % 10))
					cout << '\n';
				i++;
		}
		return 0;
}