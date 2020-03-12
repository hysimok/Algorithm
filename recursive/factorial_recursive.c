#include <stdio.h>

int recursive_factorial(int nb)
{
	if (nb <= 0)
		return (1);
	return (nb * recursive_factorial(nb - 1));
}

int main(void)
{
	int nb;

	nb = 6;
	printf("%d! = %d\n", nb, recursive_factorial(nb));
}