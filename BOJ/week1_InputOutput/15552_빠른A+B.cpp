#include <iostream>
using namespace std;

int main()
{
		int T, i;
		int a, b;
		cin.tie(NULL);
		ios::sync_with_stdio(false);

		cin >> T;
		for(i = 0; i < T; i++)
		{
				cin >> a >> b;
				cout << a + b << '\n';
		}

		return 0;
}