#include <iostream>

using namespace std;

int main()
{
		int	N;
		cin >> N;

		// dp[N][L] : N자리 계단수에 대해, 끝자리가 L인 수의 개수
		int dp[101][10];

		//set initial value
		for(int i = 0; i < 10; i++)
		{
				if (i == 0)
						dp[1][i] = 0;
				else
						dp[1][i] = 1;		
		}
		for(int i = 2; i <= N; i++)
		{
				for (int j = 0; j < 10; j++)
				{
						if (j == 0)
								dp[i][j] = dp[i - 1][j + 1];
						else if (j == 9)
								dp[i][j] = dp[i - 1][j - 1];
						else
								dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
				}
		}
		
		int sum = 0;
		for(int j = 0; j < 10; j++)
				sum = (sum + dp[N][j]) % 1000000000;	
		cout << sum << '\n';
		return (0);
}