#include <iostream>
using namespace std;

int main()
{
	int	N;
	cin >> N;

	//dynamic allocation of memory
	int	**dp = new int*[N + 1];

	for (int i = 0; i < N + 1; i++)
		dp[i] = new int[10];
	
	//set initial value
	for(int i = 0; i < 10; i++)
		dp[1][i] = 1;		

	for(int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			dp[i][j] = 0;
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
			}
		}
	}
	
	int sum = 0;
	for(int j = 0; j < 10; j++)
		sum = (sum + dp[N][j]) % 10007;	
	cout << sum << '\n';

	for(int i = 0; i < (N + 1); i++)
		delete[] dp[i];
	delete[] dp;

	return (0);
}