#include <iostream>
using namespace std;

int main()
{
	int	N;
	cin >> N;
	int	input[16][2] = {0};
	int	tmp_sum;
	int	result;

	for (int i = 1; i < (N + 1); i++)
		cin >> input[i][0] >> input[i][1];

	result = 0;
	for (int i = 1; i <= N; i++)
	{
		int j;
		j = i;
		tmp_sum = 0;
		while (j <= N)
		{
			if (j + input[j][0] > N + 1)
			{
				j++;
				continue;
			}
			tmp_sum += input[j][1];
			j = j + input[j][0];
		}
		if (tmp_sum > result)
			result = tmp_sum;
	}
	cout << result << '\n';
	return (0);
}