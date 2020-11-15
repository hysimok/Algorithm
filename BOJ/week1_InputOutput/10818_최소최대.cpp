#include <iostream>
using namespace std;

int main()
{
		int		i, N, num;
		int		min, max;
		
		cin >> N;
		min = 1000000;
		max = -1000000;
		for (i = 0; i < N; i++)
		{
				cin >> num;
				if (num > max)
						max = num;
				if (num < min)
						min = num;
		}
		cout << min << " " << max << '\n';
		return 0;
}