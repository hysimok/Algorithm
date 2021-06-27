#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

typedef int LData;

typedef struct	_node
{
	LData			data;
	struct _node	*next;
}				Node;

typedef struct	_linkedList
{
	Node	*head;
	Node	*cur;
	Node	*before;			//node의 삭제를 위해 필요
	int		numOfData;
	int		(*comp)(LData d1, LData d2);
}				LinkedList;

typedef LinkedList List;

void	ListInit(List *plist);

void	LInsert(List *plist, LData data);
void	FInsert(List *plist, LData data);
void	SInsert(List *plist, LData data);

int		LFirst(List *plist, LData *pdata);
int		LNext(List *plist, LData *pdata);

LData	LRemove(List *plist);
int		LCount(List *plist);

void	SetSortRule(List *plist, int (*comp)(LData d1, LData d2));

#endif