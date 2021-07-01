#include "DBDLinkedList.h"

void ListInit(List *plist)
{
	plist->head = (Node *)malloc(sizeof(Node));
	plist->tail = (Node *)malloc(sizeof(Node));
	
	plist->head->prev = NULL;
	plist->head->next = plist->tail;
	plist->tail->prev = plist->head;
	plist->tail->next = NULL;

	plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;

	newNode->next = plist->tail;
	plist->tail->prev = newNode;
}

int LFirst(List *plist, Data *pdata)
{
	if(plist->head == NULL)
		return FALSE;
	
	plist->cur = plist->head;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List *plist, Data *pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;
	
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List *plist, Data *pdata)
{
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return TRUE;
}

