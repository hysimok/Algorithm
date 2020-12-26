#include <iostream>
#include <algorithm>

using namespace std;

int arr[2][100001];    //배열데이터가 저장됨
int dp[2][100001];      //최대값 정보가 저장됨

int main()
{
    int T;
    int n;
    cin >> T;

    for(int test_case = 0; test_case < T; test_case++)
    {
        //get_input
        cin >> n;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                cin >> arr[i][j];
            }
        }

        //set initial value
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];

        //solve
        //dp[i][j] 는 arr[i][j] 스티커를 선택했을 때의 최대값이다
        for(int j = 2; j < n + 1; j++)
        {
            dp[0][j] = max(dp[1][j - 2], dp[1][j - 1]) + arr[0][j];
            dp[1][j] = max(dp[0][j - 2], dp[0][j - 1]) + arr[1][j];
        }

        //result
        cout << max(dp[0][n], dp[1][n]) << '\n';    
    }
    return (0);
}