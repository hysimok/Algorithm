#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

#include <stdio.h>

/*** ArrayList의 정의 ****/
#define LIST_LEN	100
//구조체를 변경하지 않고 이 행만 변경해도 구조체에 담을 데이터의 자료형을 쉽게 바꿀 수 있다.
typedef int LData;				

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;


/*** ArrayList와 관련된 연산들 ****/
typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif