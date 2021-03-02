#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int	N;			// 배열의 크기
	int	M;			// 숫자가 더해지는 횟수
	int	K;			// 연속으로 더할 수 있는 최대 횟수
	vector<int> v;

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		int	x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	int first = v[N - 1];
	int	second = v[N - 2];

	int	first_cnt = (M / (K + 1)) * K;
	first_cnt += M % (K + 1);

	int result = 0;
	result += first * first_cnt;
	result += second * (M - first_cnt);

	cout << result << '\n';

	return (0);
}