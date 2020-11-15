#include <iostream>
#include <vector>

using namespace std;

void find_min(int n , vector<int> &dp) {
		dp[n] = dp[n - 1] + 1;
		if (n % 2 == 0)
			dp[n] = min(dp[n / 2] + 1, dp[n]);
		if (n % 3 == 0)
			dp[n] = min(dp[n / 3] + 1, dp[n]);
}
int main() {

		int N;
		cin >> N;

		vector<int> dp(N + 1);

		dp[0] = 0;
		dp[1] = 0;
		for (int i = 2; i <= N; i++) {
			find_min(i, dp);
		}
		cout << dp[N] << '\n';
		return 0;
}