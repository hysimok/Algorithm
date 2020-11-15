#include <iostream>
using namespace std;

int main()
{
		int		i, j, N;

		cin >> N;
		for (i = N; i > 0; i--)
		{
				for (j = 0; j < (N - i); j++)
						cout << ' ';
				for (j = 0; j < (2 * i - 1); j++)
						cout << '*';
				cout << '\n';
		}
		for (i = 2; i < N + 1; i++)
		{
				for(j = 0; j < (N - i) ; j++)
						cout << ' ';
				for(j = 0; j < (2 * i - 1); j++)
						cout << '*';
				cout << '\n';
		}
		return 0;
}