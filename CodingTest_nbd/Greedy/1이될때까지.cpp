#include <iostream>
using namespace std;

int main()
{
	int N, K;
	int cnt = 0;

	cin >> N >> K;
	while (N != 1)
	{
		if (N % K == 0)
		{
			N /= K;
			cnt++;
		}
		else
		{
			N -= 1;
			cnt++;
		}
		if (N == 1)
			break;
	}
	cout << cnt << '\n';
	return (0);
}