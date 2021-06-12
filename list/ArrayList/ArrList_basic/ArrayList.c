#include "ArrayList.h"

void ListInit(List * plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData > LIST_LEN) 
	{
		puts("Fail to Save.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

// 첫 번째 데이터가 pdata가 가리키는 메모리에 저장된다.
int LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

// 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
int LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData)-1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

// 멤버변수 curPosition 을 확인해서 조회가 이루어진 값의 위치를 확인하고 삭제.
// 중간에 데이터가 삭제되었으므로, 이후의 데이터를 한 칸씩 앞으로 이동시킨다.
LData LRemove(List * plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for(i=rpos; i<num-1; i++)
		plist->arr[i] = plist->arr[i+1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}