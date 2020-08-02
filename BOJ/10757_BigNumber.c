#include <stdio.h>
#include <string.h>
#define StoD(X) (X==0?0:X-'0')

char a[10000];
char b[10000];
char res[10000];

//배열에 반대로 저장
void	reverse(char *arr, int len)
{
	int		i;
	char	temp;

	for (i = 0; i < len / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}

int main()
{
	int len;
	int carry = 0;
	int i;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(res, 0, sizeof(res));
	scanf("%s %s", a, b);
	reverse(a, strlen(a));
	reverse(b, strlen(b));
	
	if (strlen(a) >= strlen(b))
		len = strlen(a);
	else
		len = strlen(b);

	for (i = 0; i <= len; i++)
	{
		res[i] = (StoD(a[i]) + StoD(b[i]) + carry) % 10 + '0';
		if (StoD(a[i]) + StoD(b[i]) + carry > 9)
			carry = 1;
		else
			carry = 0;
	}
	if (res[len] == '0')
		res[len] = 0;
	
	reverse(res, strlen(res));
	printf("%s", res);

	return 0;
}