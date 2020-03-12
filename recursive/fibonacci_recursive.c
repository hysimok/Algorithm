int fibonacci(int index)
{
	if (index == 1)
		return (0);
	else if (index == 2)
		return (1);
	else
		return (fibonacci(n-1) + fibonacci(n-2));
}