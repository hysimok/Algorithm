#include "DLinkedList.h"

/*
** 새로운 노드가 HEAD 에서 추가되는 연결리스트 구현
*/

void	ListInit(List *plist)
{
	plist->head = (Node *)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void	LInsert(List *plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	// else
	// 	SInsert(plist, data);	
}

void	FInsert(List *plist, LData data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	plist->numOfData++;
}

int		LFirst(List *plist, LData *pdata)
{
	// 더미노드가 NULL을 가리킨다면, 반환할 데이터가 없다.
	if (plist->head->next == NULL)
	 return FALSE;

	// before 는 더미 노드를 가리키게 함
	// cur은 첫 번째 노드를 가리키게 함
	plist->before = plist->head;
	plist->cur = plist->head->next;

	// 첫 번째 노드의 데이터 전달
	*pdata = plist->cur->data;
	return TRUE;
}

int		LNext(List *plist, LData *pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;
	
	// before 과 cur 한 칸씩 이동
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData 	LRemove(List *plist)
{
	//소멸 대상의 주소 값을 rpos에 저장
	Node *rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	plist->numOfData--;
	return rdata;
}

int		LCount(List *plist)
{
	return plist->numOfData;
}

