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
	// 정렬 기준이 마련되지 않았다면 머리에 노드 추가
	if (plist->comp == NULL)
		FInsert(plist, data);
	// 정렬 기준이 마련되었다면, 정렬 기준에 근거하여 노드 추가
	else
		SInsert(plist, data);	
}

void	FInsert(List *plist, LData data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	plist->numOfData++;
}

void	SInsert(List *plist, LData data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));		// 새 노드의 생성
	Node *pred = plist->head;							// pred는 plist의 더미 노드를 기리킴
	newNode->data = data;								// 새 노드에 데이터 저장

	// 새 노드가 들어갈 위치를 찾기 위한 반복문!
	// 반복문을 탈출하면 pred 가 가리키는 노드의 오른쪽에 새 노드가 추가된다.
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newNode->next = pred->next;							// 새 노드의 오른쪽을 연결
	pred->next = newNode;								// 새 노드의 왼쪽을 연결

	(plist->numOfData)++;
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

void	SetSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

