#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//定义栈的最大容量
#define MAX_SIZE 10


//定义栈的结构体，名字为SqStack
typedef struct {
	int data[MAX_SIZE];
	int top;
}SqStack;

//初始化栈
//令栈的指针为-1
bool Init_SqStack(SqStack *s)
{
	(*s).top = -1;
	return true;
}

//判断栈是否为空
//检查top指针是否为-1
bool Empty_SqStack(SqStack* s)
{
	if ((*s).top == -1)
		return true;
	else
	{
		return false;
	}
}

//判断栈是否满
//看top指针是否为 MAX_SIZE - 1
bool Full_SqStack(SqStack* s)
{
	if ((*s).top == MAX_SIZE - 1)
		return true;
	else
	{
		return false;
	}
}


//入栈
//判断是否可以入栈-->元素入栈后修改指针
bool Push_SqStack(SqStack* s, int e)
{
	if (Full_SqStack(s))
	{
		printf("栈已满无法入栈！\n");
		return false;
	}
	else
	{
		(*s).data[++(*s).top] = e; //++s.top：首先，s.top 的值会增加1。这是前置递增操作，意味着先增加 s.top 的值，然后再使用这个新的值。
		return true;		//s.data[...] = e;：然后，将新值 e 存入 s.data 数组中由 s.top 索引指定的位置。
	}
}




//出栈
//从顶元素开始弹出并且令指针递减
bool Pop_SqStack(SqStack* s)
{
	int x;
	if (Empty_SqStack(s))
	{
		printf("栈已空无法出栈！\n");
		return false;
	}
	else
	{
		x = (*s).data[(*s).top--];
		printf("元素：%d 已出栈！\n", x);
		return true;
	} //注意出入栈的时候指针的增减顺序，入栈是先增，出栈是后减
}




int main()
{
	SqStack s;
	printf("初始化：%d\n", Init_SqStack(&s));
	printf("判空：%d\n", Empty_SqStack(&s));
	printf("判满：%d\n", Full_SqStack(&s));
	printf("\n------------------------\n");
	for (int i = 1; i <MAX_SIZE+1; ++i)
	{
		Push_SqStack(&s, i);
	}
	printf("\n------------------------\n");
	for (int i = 1; i < MAX_SIZE + 1; ++i)
	{
		Pop_SqStack(&s);
	}
	
	printf("判满：%d\n", Full_SqStack(&s));
	printf("判空：%d\n", Empty_SqStack(&s));

	return 0;
}
