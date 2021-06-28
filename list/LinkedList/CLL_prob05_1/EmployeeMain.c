#include "CLinkedList.h"
#include "Employee.h"

Employee *WhosNightDuty(List *plist, char *name, int days)
{
	int i, num;
	Employee *ret;

	num = LCount(plist);

	// 이름 찾기 ///////
	LFirst(plist, &ret);

	if(strcmp(ret->name, name) != 0)
	{
		for(i=0; i < num - 1; i++)
		{
			LNext(plist, &ret);

			if(strcmp(ret->name, name) == 0)
				break;
		}
		if(i >= num-1)     // 해당하는 이름이 존재하지 않으면
			return NULL;
	}

	// 그 뒤로 며칠 뒤 ///////
	for(i=0; i < days; i++)
		LNext(plist, &ret);

	return ret;
}

int main(){

	Employee	*pemp;
	Employee	*data;

	int			i;

	List		list;
	ListInit(&list);

	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->emp_num = 1;
	strcpy(pemp->name, "HYEYOON");
	LInsert(&list, pemp);

	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->emp_num = 2;
	strcpy(pemp->name, "BONGSOON");
	LInsert(&list, pemp);

	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->emp_num = 3;
	strcpy(pemp->name, "MUJI");
	LInsert(&list, pemp);

	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->emp_num = 4;
	strcpy(pemp->name, "JORDI");
	LInsert(&list, pemp);

	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->emp_num = 5;
	strcpy(pemp->name, "APEACH");
	LInsert(&list, pemp);

	if(LFirst(&list, &data))
	{
		printf("%d ", data->emp_num);
		printf("%s\n", data->name);
		
		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &data))
			{
				printf("%d ", data->emp_num);
				printf("%s\n", data->name);
			}
		}
	}

	pemp = WhosNightDuty(&list, "HYEYOON", 3);
	printf("HYEYOON님 3일 뒤 근무자는 : %d %s입니다\n", pemp->emp_num, pemp->name);

	return 0;
}