#include <iostream>

using namespace std;

int main()
{
	int	n;
	int	coin[4] = {500, 100, 50, 10};
	int	cnt = 0;

	cin >> n;
	cnt = 0;
	for(int i = 0; i < 4; i++)
	{
		cnt += n / coin[i];
		n %= coin[i];
	}
	cout << cnt << '\n';
	return (0);
}