#include<iostream>
#include<algorithm>

using namespace std;

int n, ans;
int	dp[1001];
int arr[1001];

int main() {
    
    int n;
    int ans;

    ans = 0;
    //get input
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    //solve
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }

    //print answer
    cout << ans << '\n';
    return 0;
}
