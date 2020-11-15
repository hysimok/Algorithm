#include <iostream>
#include <vector>
using namespace std;

void	find_ans(int n, vector<int> &dp)
{
		dp[n] = (dp[n - 2] + dp[n - 1]) % 10007;
}

int main()
{
		int		n;
		cin		>> n;

		vector<int> dp(n + 1);
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 2; i <= n; i++)
		{
				find_ans(i, dp);
		}
		cout << dp[n] << '\n';
		return 0;
}