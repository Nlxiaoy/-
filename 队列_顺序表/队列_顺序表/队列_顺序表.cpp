#include"标头.h"


//初始化队列
//让头尾指针指向零
void Init_SqQueue(SqQueue* Q)
{
	Q->front = Q->rear = 0;
}

//队列的判空
//看头尾指针是否相等
bool Empty_SqQueue(SqQueue* Q)
{
	if (Q->front == Q->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//判断队列是否满
//看尾指针是否等于 MAX_SIZE - 1
bool Full_SqQueue(SqQueue* Q)
{
	if (Q->rear == MAX_SIZE - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//入队操作
	//将元素赋值给rear所指向的data。rear++
	bool Enter_SqQueue(SqQueue* Q,int e)
	{
		if (Full_SqQueue(Q)) return false;
		Q->data[Q->rear] = e;
		Q->rear++;
		return true;
	}

	//出队操作
	//向后移动头指针
	bool Out_SqQueue(SqQueue* Q)
	{
		if (Empty_SqQueue(Q)) return false;
		Q->front++;
		return true;
	}

	//输出队列中的元素
	//依次输出头指针指向的data
	void Print_SqQueue(SqQueue* Q)
	{
		if (Empty_SqQueue(Q)) exit;
		int i=Q->front;
		while (i < Q->rear)
		{
			printf("%d\n", Q->data[i]);
			++i;
		}
	}


