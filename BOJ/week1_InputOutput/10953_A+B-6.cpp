#include <iostream>

int main()
{
		int		a, b, i, T;
		char	c;
		
		std::cin >> T;
		for (i = 0; i < T; i++)
		{
				std::cin >> a >> c >> b;
				std::cout << a + b << std::endl;
		}
		
		return (0);
}