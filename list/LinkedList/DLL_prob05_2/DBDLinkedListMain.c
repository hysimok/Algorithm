#include "DBDLinkedList.h"

int main(void)
{
	List list;
	int	data;
	ListInit(&list);

	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);

	//조회
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		// 오른쪽 노드로 이동하며 데이터 조회
		while(LNext(&list, &data))
			printf("%d ", data);
		
		// 왼쪽 노드로 이동하며 데이터 조회
		while(LPrevious(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}

	//2의 배수 데이터 삭제
	if(LFirst(&list, &data))
	{
		if(data % 2 == 0)
			LRemove(&list);

		while(LNext(&list, &data)) 
		{		
			if(data % 2 == 0)
				LRemove(&list);
		}
	}

	// 저장된 데이터의 재 조회 ///////
	if(LFirst(&list, &data))
	{
		printf("%d ", data);

		while(LNext(&list, &data)) 
			printf("%d ", data);
		
		printf("\n\n");
	}

	return 0;
}