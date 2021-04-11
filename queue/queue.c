#include<stdio.h>
#include<string.h>
#include"AQueue.h"
#include"LQueue.h"

char datatype[MAXQUEUE];
int a = sizeof(AQueue);
LQueue *queue;
AQueue* qu;

int main()
{
	qu = (AQueue*)malloc(sizeof(AQueue));
	InitAQueue(qu, sizeof(char));
	char s = 'a';
	EnAQueue(qu, &s);
	s = 's';
	EnAQueue(qu, &s);
	TraverseAQueue(qu, APrint);
	char b=0;
	GetHeadAQueue(qu, &b);
	printf("%c\n", b);
	int a = LengthAQueue(qu);
	printf("%d\n", a);
	GetHeadAQueue(qu, &b);
	DeAQueue(qu);
	printf("%c\n", b);
	ClearAQueue(qu);
	a = LengthAQueue(qu);
	printf("%d\n", a);
	DestoryAQueue(qu);
	return 0;
}