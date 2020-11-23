#include <iostream>
#include <vector>

using namespace std;

void	find_ans(int n, vector<int> &dp)
{
		for (int i = 4; i <= n; i++)
		{
				dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}
}

int	main(){
		int T, n;
		cin >> T;
		vector<int> dp;

		for (int i = 0; i < T; i++)
		{
				cin >> n;
				dp.assign(n + 1, 0);
				dp[1] = 1;
				dp[2] = 2;
				dp[3] = 4;
				find_ans(n, dp);
				cout << dp[n] << '\n';
		}
		return (0);
}