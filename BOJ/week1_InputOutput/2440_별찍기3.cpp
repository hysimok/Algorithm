#include <iostream>
using namespace std;

int main()
{
		int		i, j, N;

		cin >> N;
		for (i = N; i > 0; i--)
		{
				for(j = 0; j < i ; j++)
						cout << "*";
				cout << '\n';
		}
		return 0;
}