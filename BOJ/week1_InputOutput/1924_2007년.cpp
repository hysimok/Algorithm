#include <iostream>
using namespace std;
int		getNumberOfDays(int	month)
{
		int days;
		if (month < 8)
		{
				if (month == 2)
					days = 28;
				else if (month % 2)
					days = 31;
				else
					days = 30;
		}
		else
		{
				if (month % 2)
					days = 30;
				else
					days = 31;
		}
		return days;
}

int 	main()
{
		int			month, date;
		int			i, days;
		string	dayOfWeek[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

		cin >> month >> date;
		i = 1;
		days = 0;
		while (i != month && month != 1)
		{
				days += getNumberOfDays(i);
				i++;
		}
		days += date;
		cout << dayOfWeek[(days % 7)] << '\n';
		return 0;
}