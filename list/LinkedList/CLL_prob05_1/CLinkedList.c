#include "CLinkedList.h"

void ListInit(List *plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	(plist->numOfData)++;
}

void LInsertFront(List *plist, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->tail == NULL)
		return FALSE;
	
	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List *plist, Data *pdata)
{
	if (plist->tail == NULL)
		return FALSE;
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

/* 삭제 
** 일반 연결리스트와 다르게 고려해야할 상황
** 1) 삭제할 노드를 tail이 가리키는 경우
** 2) 삭제할 노드가 리스트에 홀로 남은 경우
*/
Data LRemove(List *plist)
{
	//소멸 대상의 주소 값을 rpos에 저장
	Node *rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail)					// 삭제 대상을 tail이 가리킨다면
	{
		if (plist->tail == plist->tail->next)	// 그리고 마지막 남은 노드라면
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	// free(rdata->name);
	free(rpos);
	plist->numOfData--;
	return rdata;
}

int LCount(List *plist)
{
	return plist->numOfData;
}
