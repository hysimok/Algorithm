#include <iostream>
using namespace std;

int main()
{
		int		i, j, N;

		cin >> N;
		for (i = 1; i <= N; i++)
		{
				for (j = 1; j <= (N - i); j++)
						cout << ' ';
				for (j = 1; j <= (2 * i - 1); j++)
				{
						if (j % 2)
							cout << '*';
						else
							cout << ' ';
				}
				cout << '\n';
		}
		return 0;
}