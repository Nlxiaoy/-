#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//定义了一个双链表的结构体，名字是DNode，每个节点都有两个指针——prior和next
typedef struct DNode
{
	int data;
	struct DNode* prior, * next;
}DNode, *DLinkList;

//双链表的初始化
//创建头节点并且判断内存是否正常分配后直接让头节点的前后指针指向NULL
bool Init_DLinkList(DLinkList* pHead)
{
	*pHead = (DNode*)malloc(sizeof(DNode));
	if (*pHead == NULL)
		return false;
	(*pHead)->prior = NULL;
	(*pHead)->next = NULL;
	return true;
}

//双链表的判空
//看头节点的next指针是否指向了NULL
bool Empty_DLinkList(DLinkList pHead)
{
	if (pHead->next == NULL)
		return true;
	else
	{
		return false;
	}
}

//双链表的长度计算
//创建一个临时指针=头节点的next，遍历整个链表经过一个节点就+1,最后函数返回结果
int Length_DLinkList(DLinkList pHead)
{
	int count = 0;
	DNode* p = pHead->next;
	for (; p != NULL; p = p->next)
		++count;
	return count;
}

//头插法创建双链表（结果为倒叙）
//创建一个临时节点-->新节点的next指向头节点的next-->新节点的prior指向头节点-->修改头节点之后节点的prior指针-->头节点的next指向新节点
DLinkList Creat_HEAD_DLinkList(DLinkList pHead)
{
	DNode* pTemp;
	int val;
	printf("请输入需要插入的元素（输入999结束）：");
	scanf_s("%d", &val);
	while (val != 999)
	{
		pTemp = (DNode*)malloc(sizeof(DNode));
		pTemp->data = val;
		pTemp->next = pHead->next;
		pTemp->prior = pHead;
		if (pHead->next != NULL)
		{
			pHead->next->prior = pTemp;
		}
		pHead->next = pTemp;
		printf("请输入需要插入的元素（输入999结束）：");
		scanf_s("%d", &val);
	}
	return pHead;
}

//尾插法创建双链表
//创造一个新节点pTemp-->令前节点next成为新节点的next-->新节点prior指向前一个节点-->前一个节点的next指向新节点-->移动p指针使其指向新节点
bool Creat_TAIL_DLinkList(DLinkList pHead)
{
	DNode* p = pHead;
	DNode* pTemp;
	int val;
	printf("请输入需要插入的元素（输入999结束）：");
	scanf_s("%d", &val);
	while (val != 999)
	{
		pTemp = (DNode*)malloc(sizeof(DNode));
		pTemp->next = p->next;
		pTemp->prior = p;
		p->next = pTemp;
		p = p->next;
		pTemp->data = val;
		printf("请输入需要插入的元素（输入999结束）：");
		scanf_s("%d", &val);
	}
	p->next = NULL;
	return true;
}


//打印链表（从头开始）
//创建一个指针使其指向头节点的next，遍历每一个节点输出data
void Print_DLinkList(DLinkList pHead)
{
	int i=1;
	DNode* p = pHead->next;
	for (;p != NULL;)
	{
		printf("第%d个元素为%d\n", i, p->data);
		p = p->next;
		++i;
	}
	printf("\n");
	return;
}

//打印链表（从后往前）
//创建一个指针使其指向尾节点遍历每一个节点输出data
void Print_TAIL_DLinkList(DLinkList Phead)
{
	int i = 1;
	DNode* p = Phead;
	while (p->next != NULL)
	{
		p = p->next;
	}
	while (p->prior != NULL)
	{
		printf("第%d个元素为：%d\n", i, p->data);
		p = p->prior;
		++i;
	}
	printf("\n");
	return;
}

//按值查找
//创建一个指针指向头节点的next-->开始遍历链表找到与之相对应的值输出其位序
void Get_DLinkList(DLinkList pHead, int e)
{
	int i = 1; //头节点不存数据，所以直接从1开始，而非从零开始
	DNode* p = pHead->next;
	while (p != NULL)
	{
		if (p->data == e)
		{
			printf("元素%d位于第%d位\n", e, i);
			p = p->next;
			i++;
			continue;
		}
		p = p->next;
		i++;
	}
	return;
}

//按位查找
//创建一个指针指向头节点的next-->开始遍历链表找到与之相对应的位序输出其data
void Get_LOACL_DLinkList(DLinkList pHead, int i)
{
	DNode* p = pHead->next;
	if (p == NULL || i<1 || i>Length_DLinkList(pHead))
	{
		printf("无效查询！");
			return;
	}
	int j = 1;
	while (j<i)
	{
		p = p->next;
		j++;
	}
	printf("第%d位的元素为%d\n", i, p->data);
	return;
}

//按位删除
//创建一个指针p指向头节点-->开始遍历链表找到被删除节点的前一位-->再创建一个指针q指向被被删除节点（p的next）-->令p的next指向q的next-->如果被删除节点不是最后一个节点，q的下一个节点的prior指向p-->释放q
void Delete_LOCAL_DLinkList(DLinkList pHead, int i)
{
	if (i<1 || i>Length_DLinkList(pHead))
	{
		printf("无效删除！");
		return;
	}
	DNode* p = pHead;
	int j = 0;
	while (j<i-1)
	{
		p = p->next;
		j++;
	}
	DNode* q = p->next;
	p->next = q->next;
	if (q->next != NULL)
	{
		q->next->prior = p;
	}
	free(q);
	return;
}

//清除整张链表
//创建一个指针p指向头节点后依次遍历链表释放内存
void Delete_ALL_DLinkList(DLinkList pHead)
{
	DNode* p = pHead;
	DNode* q;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	printf("链表已清除\n");
	return;
}


int main()
{
	DLinkList pHead;
	printf("初始化：%d\n", Init_DLinkList(&pHead));
	printf("判空：%d\n", Empty_DLinkList(pHead));
	printf("长度：%d\n", Length_DLinkList(pHead));
	printf("\n------------------------------\n");
	//Creat_HEAD_DLinkList(pHead);
	//printf("长度：%d\n", Length_DLinkList(pHead));
	//printf("\n------------------------------\n");
	Creat_TAIL_DLinkList(pHead);
	printf("长度：%d\n", Length_DLinkList(pHead));
	Print_DLinkList(pHead);
	printf("\n------------------------------\n");
	//Print_TAIL_DLinkList(pHead);
	//printf("\n------------------------------\n");
	//Get_DLinkList(pHead,2);
	//Get_LOACL_DLinkList(pHead,7);
	//Delete_LOCAL_DLinkList(pHead, 2);
	//Print_DLinkList(pHead);
	//printf("\n------------------------------\n");
	Delete_ALL_DLinkList(pHead);

	return 0;

}