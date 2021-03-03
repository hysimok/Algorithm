#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;

	cin >> N >> M;

	vector < vector<int> > v;

	for(int i = 0; i < N ; i++)
	{
		vector <int> v_temp;
		for(int j = 0; j < M; j++)
		{
			int x;
			cin >> x;
			v_temp.push_back(x);
		}
		v.push_back(v_temp);
	}
	
	int	max = 0;
	int tmp_min = 0;
	for (int i = 0; i < N; i++)
  	{
		tmp_min = v[i][0];
		for(int j = 1; j < M; j++)
		{
			if (v[i][j] < tmp_min)
				tmp_min = v[i][j];
		}
		if (tmp_min > max)
			max = tmp_min;
	}
	cout << max << '\n';
	return (0);
}