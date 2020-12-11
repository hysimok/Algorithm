#include <iostream>
using namespace std;

int main()
{
	long long dp[91][2] = {0};
	int N;

	cin >> N; 
	//set initial value;
	dp[1][0] = 0;
	dp[1][1] = 1;

	for(int i = 2; i <= N; i++)
	{
		if (dp[i - 1][0] != 0)
		{
			dp[i][0] += dp[i - 1][0];
			dp[i][1] += dp[i - 1][0];
		}
		if (dp[i - 1][1] != 0)
			dp[i][0] += dp[i - 1][1];
	}
	cout << dp[N][0] + dp[N][1] << '\n';
	return (0);
}