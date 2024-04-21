#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {   
	int data[MAX_SIZE];
	int length;
}SqList;  //定义了一个结构体，结构体里面包含了一个最大长度为10的数组和顺序表当前的长度length，SqList是当前结构体的简称

//顺序表的初始化
void InitList(SqList* L)
{
	L->length = 0;
}

//在顺序表L的i位序中插入元素e，要注意区分位序和下标。下标+1=位序，顺序表的第一位元素的下标是从0开始的
//判断插入位置是否合法-->将第i个元素及其后面的元素向后移动一位-->在位置i放入e-->顺序表长度+1
bool List_Insert(SqList* L, int i, int e)
{
	if (i > L->length+1 || i < 1 || L->length > MAX_SIZE)
	{
		printf("非法插入操作！\n");
		return false;
	}
		
	for (int j = L->length; j >= i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}

//删除顺序表中的位序为i的值，并用e返回
//判断删除位置是否合法-->将第i+1及其后面的元素的位置向前移动一位-->顺序表长度-1
bool List_Delete(SqList* L, int i)
{
	if (i > L->length || i < 1)
	{
		printf("非法删除操作!\n");
		return false;
	}
	for (int j = i; j<L->length; j++)
	{
		L->data[j - 1] = L->data[j];
	}
	L->length--;
	return true;
}

//按位查找顺序表中的元素
//判断查找位置是否合法-->将被查找的元素直接用函数返回
int Get_List(SqList* L, int i)
{
	if (i > L->length || i < 1)
	{
		printf("非法查找操作！\n");
		return -999;
	}
	else
	{
		return L->data[i - 1];
	}
}

//按值查找顺序表中的元素
//遍历顺序表中的每个元素并且与e比对-->返回元素的位序,因为是返回位序，所以i要加一才行
int Get_List_Locate(SqList* L, int e)
{
	for (int i = 0; i <= L->length; ++i)
	{
		if (L->data[i] == e)
			return i + 1; 
		else
		{
			return -1;
		}
	}
}

//打印整张顺序表
//直接遍历整张表同时输出每一个元素
void Prin_List(SqList* L)
{
	printf("顺序表：");
	for (int i = 0; i < L->length; ++i)
	{
		printf("%d\t", L->data[i]);
	}
	printf("\n");
}

//在尾部插入一个元素
//判断插入元素是否合法-->插入元素，长度+1
bool Insert_List_Tail(SqList* L, int e)
{
	if (L->length >= MAX_SIZE)
	{
		printf("顺序表已满，无法插入！\n");
		return false;
	}
	L->data[L->length] = e;
	L->length++;
	return true;
}


int main()
{
	SqList L;
	InitList(&L);
	List_Insert(&L, 1, 1);
	List_Insert(&L, 2, 1);
	List_Insert(&L, 3, 1);
	List_Insert(&L, 4, 1);
	List_Insert(&L, 5, 1);
	List_Insert(&L, 6, 1);
	List_Insert(&L, 7, 1);
	List_Insert(&L, 8, 1);
	List_Insert(&L, 9, 1);
	List_Insert(&L, 10, 1);


	printf("%d\n", List_Delete(&L, 1));

	printf("%d\n", Get_List(&L, 1));
	
	printf("%d\n", Get_List_Locate(&L, 2));
	
	Prin_List(&L);
	Insert_List_Tail(&L, 10);
	Prin_List(&L);


	return 0;
}