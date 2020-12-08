#include <stdio.h>

void HanoiTower(int num, char from, char by, char to)
{
	if (num == 1)
	{
		printf("원반 1을 %c에서 %c로 이동\n", from, to);	
	}
	else
	{
		// Move n - 1 number of disks from A to B
		HanoiTower(num - 1, from, to, by);
		// Move the disk n from A to C
		printf("원반 %d를 %c에서 %c로 이동\n", num, from, to);
		// Move n - 1 number of disks from B to C
		HanoiTower(num - 1, by, from, to);
	}
}

int main()
{
	// Move 3 number of disks from A to C
	HanoiTower(3, 'A', 'B', 'C');
	return (0);
}