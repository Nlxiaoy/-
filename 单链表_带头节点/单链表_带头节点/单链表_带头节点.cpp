#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//定义一个链表结构体
//LNode是struct LNode的简称，LinkList是指向这个结构体的指针
typedef struct LNode { 
	int data;
	struct LNode* next;
}LNode, *LinkList;

//初始化链表
//创建头节点-->判断是否有足够的内存给Phead节点-->令头节点的指针指向NULL
bool Init_LinkList(LinkList* pHead)
{
	*pHead = (LNode*)malloc(sizeof(LNode));
	if (pHead == NULL)
		return false;
	(*pHead)->next = NULL;
	return true;
}

//判断链表是否位空
//看头节点的指针是否指向NULL,用return返回
bool Empty_LinkList(LinkList pHead)
{
	if (pHead->next == NULL)
		return true;
	else
	{
		return false;
	}
}

//统计链表长度（节点的个数）
//从头节点开始遍历整个表。经过一个节点就+1，用return返回个数
int Length_LinkList(LinkList pHead)
{
	int count = 0;
	for (LNode* z = pHead->next; z != NULL; z = z->next)
	{
		++count;
	}
	return count;
}

//头插法创建链表（倒叙输出）
//创建一个新的节点-->新节点的指针指向头节点的next-->头节点的next指向新节点。顺序不可乱
LinkList Create_HEAD_LinkList(LinkList pHead)
{
	int val;
	printf("请输入要录入链表的数字（输入999停止）：");
	scanf_s("%d", &val);
	while (val != 999)
	{
		LNode* pTemp = (LNode*)malloc(sizeof(LNode));
		pTemp->next = pHead->next;
		pHead->next = pTemp;
		pTemp->data = val;
		printf("请输入要录入链表的数字（输入999停止）：");
		scanf_s("%d", &val);
	}
	return pHead;
}

//尾插法创建链表
//创建2个指针，一个临时节点的指针指向临时节点，另一个是尾节点的指针指向表尾-->创建新节点并且使尾节点指针指向它-->新节点的next指向NULL
LinkList Create_TAIL_LinkList(LinkList pHead)
{
	int val;
	LNode* pTail = pHead;
	LNode* pTemp;
	printf("请输入要录入链表的数字（输入999停止）：");
	scanf_s("%d", &val);
	while (val != 999)
	{
		pTemp = (LNode*)malloc(sizeof(LNode));
		pTemp->data = val;
		pTail->next = pTemp;
		pTail = pTemp;
		printf("请输入要录入链表的数字（输入999停止）：");
		scanf_s("%d", &val);
	}
	pTail->next = NULL;
	return pHead;
}

//按位序插入元素
//判断插入是否合法-->遍历链表找到插入位置-->创建新的节点-->修改前后指针完成插入,一定要先后再前修改
void Insert_LinkList(LinkList pHead, int i, int e)
{
	if (i<1 || i>Length_LinkList(pHead) + 1)
		return;
	LNode* p = pHead;
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	LNode* pTemp = (LNode*)malloc(sizeof(LNode));
	pTemp->data = e;
	pTemp->next = p->next;
	p->next = pTemp;
	return;
}

//按值查找
//从头开始遍历链表，找到与之匹配的值之后直接在子函数内printf他的位置
void GET_LinkList(LinkList pHead, int e)
{
	LNode* p = pHead->next;
	int i = 0;
	while(p != NULL && p->data != e)
	{
		p = p->next;
		++i;
	}
	printf("该元素 %d 位于第%d位\n", e, i + 1);
	return;
}

//按位查找
//从头开始遍历链表，找到与之匹配的位序之后直接在子函数内printf他的data
void GET_LOCAL_LinkList(LinkList pHead, int i)
{
	if(i < 1 || i > Length_LinkList(pHead))
	{
		printf("非法查找！\n");
		return;
	}
	LNode* p = pHead->next;
	int j = 0;
	while (p->next != NULL && j<i-1)
	{
		p = p->next;
		++j;
	}
	printf("第%d位的元素的值为%d\n", i, p->data);
	return;
}

//按位序删除节点
//从头开始遍历链表找到与之对应的位序的节点-->free掉
void Delete_LOCAL_LinkList(LinkList pHead, int i)
{
	if (i < 1 || i > Length_LinkList(pHead))
	{
		printf("非法删除！\n");
		return;
	}
	LNode* p = pHead;
	int j = 0;
	for (j; j < i - 1; j++)
	{
		p = p->next;
	}
	LNode* q = p->next; //新建一个指针q指向待删除的节点
	if (q->next == NULL)
		p->next = NULL;
	else
	{
		p->next = q->next;  //直接让p指向下下个节点跳过q，完成删除
	}
	free(q);
	printf("已删除节点%d\n",i);
	return;
}

//按值删除节点
//从头开始遍历链表-->找到与之对应的值的节点-->删除该节点
void Delete_LinkList(LinkList pHead, int e)
{
	int count = 1;
	if (Length_LinkList(pHead) == 0)
	{										
		printf("链表为空无法删除！\n");
		return;
	}
	LNode* prev = pHead;	//新建一个指针用来指向当前节点的前一个节点
	LNode* p = pHead->next;
	while (p != NULL)
	{
		
		if (p->data == e)
		{
			prev->next = p->next; //让被删除的前一个节点直接指向被删除节点的下一个节点
			free(p);
			printf("已删除节点%d\n",count);
			return;
		}
		prev = p;
		p = p->next;
		++count;
	}
	printf("链表中未找到值为%d的节点\n", e);
	return;
}

//打印链表
//从头开始遍历链表-->依次输出每个节点的data
void Print_LinkList(LinkList pHead)
{
	int i = 1;
	LNode* p = pHead->next;
	for(; p != NULL ;)
	{
		printf("第%d号节点的值为%d\n",i, p->data);
		p = p->next;
		++i;
	}
	return;
}





int main()
{
	LinkList pHead;
	printf("初始化%d\n",Init_LinkList(&pHead));
	printf("判空%d\n",Empty_LinkList(pHead));
	printf("初始化之后的长度=%d\n", Length_LinkList(pHead));
	printf("\n------------------------------\n");
	
	Create_HEAD_LinkList(pHead);
	printf("头插法之后的长度=%d\n", Length_LinkList(pHead));
	printf("\n------------------------------\n");
	
	//Create_TAIL_LinkList(pHead);
	//printf("尾插法之后的长度=%d\n", Length_LinkList(pHead));
	//printf("\n------------------------------\n");
	
	Insert_LinkList(pHead,1,100);
	printf("中间插入之后的长度=%d\n", Length_LinkList(pHead));
	printf("\n------------------------------\n");
	
	//GET_LinkList(pHead, 55);
	//GET_LOCAL_LinkList(pHead, 3);
	//printf("\n------------------------------\n");
	
	//Delete_LOCAL_LinkList(pHead, 2);
	//printf("删除之后的长度=%d\n", Length_LinkList(pHead));
	//printf("\n------------------------------\n");
	
	Print_LinkList(pHead);
	printf("\n------------------------------\n");
	
	Delete_LinkList(pHead,5);
	Print_LinkList(pHead);
	return 0;
}