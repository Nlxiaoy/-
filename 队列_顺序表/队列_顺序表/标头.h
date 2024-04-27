#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_SIZE 100
typedef struct {
	int data[MAX_SIZE];
	int front;
	int rear;
}SqQueue;


void Init_SqQueue(SqQueue* Q);
bool Empty_SqQueue(SqQueue* Q);
bool Enter_SqQueue(SqQueue* Q, int e);
bool Out_SqQueue(SqQueue* Q);
void Print_SqQueue(SqQueue* Q);

