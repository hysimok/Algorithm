#include <stdio.h>

int min_val(int *juice_ratio)
{
	int i;
	int min;

	min = juice_ratio[0];
	if (min > juice_ratio[1])
		min = juice_ratio[1];
	if (min > juice_ratio[2])
		min = juice_ratio[2];

	return (min);
}

float max_amount(int juice[][3])
{
	int		i, j;
	float	max_amnt;

	max_amnt = (float)juice[0][0] / (float)juice[1][0];
	if (max_amnt > (float)juice[0][1] / (float)juice[1][1])
		max_amnt = (float)juice[0][1] / (float)juice[1][1];
	if (max_amnt > (float)juice[0][2] / (float)juice[1][2])
		max_amnt = (float)juice[0][2] / (float)juice[1][2];

	return (max_amnt);
}

void reduction(int *ratio)
{
	int i;
	int min;

	min = min_val(ratio);
	for (i = 1; i <= min; i++)
	{
		if (ratio[0] % i == 0 && (ratio[1] % i == 0) && ratio[2] % i == 0)
		{
			ratio[0] /= i;
			ratio[1] /= i;
			ratio[2] /= i;
		}
	}
}

int main()
{
	int		juice[2][3];
	int 	i, j;
	float	max;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &juice[i][j]);
		}
	}

	reduction(juice[1]);
	max = max_amount(juice);

	for (j = 0; j < 3; j++)
	{
		if ((int)(juice[0][j] - max * juice[1][j]) == 0)
		{
			printf("%d ", 0);
		}
		else
		{
			printf("%f ", juice[0][j] - max * juice[1][j]);
		}
	}
	return (0);
}