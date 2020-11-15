#include <iostream>

int main()
{
		int	i, T, a, b;

		std::cin >> T;

		for (i = 0; i < T; i++)
		{
			std::cin >> a >> b;
			std::cout << a + b << std::endl;
		}
		return 0;
}