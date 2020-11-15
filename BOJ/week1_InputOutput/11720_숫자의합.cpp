#include <iostream>
using namespace std;

int main()
{
		int		i, N, sum;
		string str;

		sum = 0;
		cin >> N >> str;
		for (i = 0; i < N; i++)
		{
				sum += str[i] - '0';
		}
		cout << sum << endl;
		
		return 0;
}