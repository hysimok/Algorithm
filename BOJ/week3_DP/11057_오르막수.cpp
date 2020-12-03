#include <iostream>
using namespace std;

int main()
{
	int	N;
	cin >> N;

	// dp[N][L] : N자리 오르막수에 대해, 끝자리가 L인 수의 개수
	int dp[1001][10];

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
	return (0);
}