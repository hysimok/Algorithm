#include <iostream>
using namespace std;

int main()
{
		int		i, j, N;

		cin >> N;
		for (i = 0; i < N; i++)
		{
				for(j = 0; j < i; j++)
						cout << ' ';
				for(j = 0; j < N - i; j++)
						cout << '*';
				cout << '\n';
		}
		return 0;
}