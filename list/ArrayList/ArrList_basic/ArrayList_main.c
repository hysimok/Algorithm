#include "ArrayList.h"

int	main()
{
	List	list;
	int		data;
	int		i;
	int		sum = 0;

	i = 0;
	ListInit(&list);

	while (i < 9)
	{
		LInsert(&list, i + 1);
		i++;
	}

	if (LFirst(&list, &data))
	{
		sum += data;
		
		while (LNext(&list, &data))
			sum+= data;
		printf("sum : %d\n", sum);
	}
	else
		puts("There's no data");

	//2와 3의 배수에 해당하는 값 삭제
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	//전체 데이터 출력
	if (LFirst(&list, &data))
	{
		printf("%-3d", data);
		while (LNext(&list, &data))
			printf("%-3d", data);
	}
	printf("\n");
	return 0;
}