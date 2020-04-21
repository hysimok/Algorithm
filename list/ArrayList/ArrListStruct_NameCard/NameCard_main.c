#include "NameCard.h"
#include "ArrayList.h"
#include <stdlib.h>

int main()
{
	List list;
	NameCard *pcard;

	ListInit(&list);

	//총 3명의 전화번호를 list에 저장
	pcard = MakeNameCard("Jung", "1111");
	LInsert(&list, pcard);
	pcard = MakeNameCard("Park", "3333");
	LInsert(&list, pcard);
	pcard = MakeNameCard("Shin", "5555");
	LInsert(&list, pcard);

	//이름이 "Park"인 사람을 찾아 정보 출력
	if(LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "Park") == 0)
			ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
		{
			if (NameCompare(pcard, "Park") == 0)
				ShowNameCardInfo(pcard);
		}
	}

	//이름이 "Shin"인 사람을 찾아 전화번호 변경
	if(LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "Shin") == 0)
			ChangePhoneNum(pcard, "8888");
		while (LNext(&list, &pcard))
		{
			if (NameCompare(pcard, "Shin") == 0)
				ChangePhoneNum(pcard, "8888");
		}
	}

	//이름이 "Park"인 사람을 찾아 그 사람의 정보 삭제
	if(LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "Park") == 0)
		{
			pcard = LRemove(&list);
			free(pcard);
		}
		while (LNext(&list, &pcard))
		{
			if (NameCompare(pcard, "Park") == 0)
			{
				pcard = LRemove(&list);
				free(pcard);
			}
		}
	}

	//마지막으로 남아있는 모든 사람의 정보 출력
	if(LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}
	return (0);

}