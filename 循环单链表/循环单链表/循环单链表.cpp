#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//创建结构体
typedef struct LNode {
	int data;
	LNode* next;
}LNode, *LinkList;

//循环单链表的初始化
//创建一个头节点并且令头节点的next指向自己
bool Init_LinkList(LinkList* pHead)
{
	(*pHead) = (LNode*)malloc(sizeof(LNode));
	if (pHead == NULL)
	{
		printf("Initialization false!\n");
		return false;
	}
	(*pHead)->next = (*pHead);
	printf("Initialization successed!\n");
	return true;
}

//循环单链表的判空
//直接判断头节点的next是否指向自己即可
bool Empty_LinkList(LinkList* pHead)
{
	if((*pHead)->next == (*pHead))
	{
		printf("Error node is empty！\n");
		return true;
	}
	return false;
}

//计算循环单链表的长度
//通过建立一个临时指针p来遍历链表，经过一个节点就令count+1
int Length_LinkList(LinkList* pHead)
{
	int count = 0;
	LinkList p = (*pHead)->next;
	while (p != (*pHead)) //这里不能像双链表或者单链表一样写成 p != NULL 因为在循环单链表中，链表的结尾是从新指向头节点的，所以一个有效的循环单链表的next是不会出现NULL的。
	{
		++count;
		p = p->next;
	}
	return count;
}

//头插法建立链表
//建立一个新节点，使得新节点的next指向头节点next，由于头节点的next指向了自己，所以新节点的next也是指向头节点的，最后修改头节点的next指向新节点完成插入
LinkList Create_HEAD_LinkList(LinkList* pHead)
{
	LNode* pTemp;
	int val;
	printf("Enter number(end whit 999)：");
	scanf_s("%d", &val);
	while (val != 999)
	{
		pTemp = (LNode*)malloc(sizeof(LNode));
		pTemp->next = (*pHead)->next;
		(*pHead)->next = pTemp;
		pTemp->data = val;
		printf("Enter number(end whit 999)：");
		scanf_s("%d", &val);
	}
	return *pHead;
}

//尾插法创建链表
//创建一个临时节点的指针，再创建一个指针指向头节点方便后续操作。临时指针指向临时节点，表尾指针指向临时节点，移动表尾指针
LinkList Create_TAIL_LinkList(LinkList* pHead)
{
	int val;
	LNode* pTemp;
	LNode* pTail = (*pHead);
	printf("Enter number(end whit 999)：");
	scanf_s("%d", &val);
	while (val != 999)
	{
		pTemp = (LNode*)malloc(sizeof(LNode));
		pTail->next = pTemp;	//尾节点指针指向新节点
		pTemp->next = (*pHead); //新节点的next指向头节点形成循环
		pTail = pTemp;			//移动表尾指针到新节点
		pTemp->data = val;		//新节点赋值
		printf("Enter number(end whit 999)：");
		scanf_s("%d", &val);
	}
	return *pHead;
}

//按位序插入新节点
//建立一个临时的指针指向头节点，开始遍历链表找到插入节点的前一个节点-->创建新节点使得临时指针的next指向新节点的next-->最后临时指针指向新节点完成插入
bool Insert_LinkList(LinkList* pHead,int i,int e)
{
	if (i<1 || i>Length_LinkList(pHead) + 1) return false;
	int j = 0;
	LNode* p = (*pHead);
	while (p != NULL && j<i-1)
	{
		p = p->next;
		++j;
	}
	LNode* pTemp = (LNode*)malloc(sizeof(LNode));
	pTemp->next = p->next;
	p->next = pTemp;
	pTemp->data = e;
	return true;
}

//按位序删除节点
//先创建一个临时指针指向头节点，从头节点开始遍历链表，找到要删除节点的前一个节点，修改被删除节点前后节点的指针
bool Delete_LinkList(LinkList* pHead, int i)
{
	if (Empty_LinkList(pHead))
	{
		printf("Error,LinkList is null!\n");
		return false;
	}
	LNode* p = (*pHead);
	for (int j = 0; j < i - 1; ++j)
	{
		p = p->next;
	}
	LNode* q = p->next;
	p->next = p->next->next;
	free(q);
	return true;
}

//按值查找节点位置
//创建一个临时指针指向头节点的next，开始遍历链表并且对比每个节点的data是否等于查找的值，最后返回指针给主函数
LinkList Get_LinkList(LinkList* pHead, int e)
{
	if (Empty_LinkList(pHead))
	{
		printf("Error,LinkList is null!\n");
		exit;
	}
	LNode* p = (*pHead)->next;
	int j = 1;
	for (j; j < Length_LinkList(pHead)+1; ++j)
	{
		if (p->data == e)
		{
			printf("%dhas been successfully found!\n",e);
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	if (p == (*pHead))
	{
		printf("No such %d!\n", e);
	}
	exit;
}

//打印链表	
//建立一个指针指向头节点的next，遍历链表打印每个节点的data
void Print_LinkList(LinkList* pHead)
{
	if (Empty_LinkList(pHead))
	{
		printf("Error,LinkList is null!\n");
		exit;
	}
	int i = 1;
	LinkList p = (*pHead)->next;
	while (p !=(*pHead))
	{
		printf("Node %d is %d\n", i, p->data);
		++i;
		p = p->next;
	}
	return;
}

//销毁循环单链表
//先建立2个指针p和q，p指向头节点的下一个节点，q指向p。先移动p至下一个节点然后再释放q。等到循环结束之后再将头节点释放完成链表的销毁
bool Destory_LinkList(LinkList* pHead)
{
	LinkList p = (*pHead)->next;
	LinkList q;
	while (p->next != (*pHead))
	{
		q = p;
		p = p->next;
		free(q);
	}
	free((*pHead));
	printf("LinkList has destory!\n");
	return true;
}


int main()
{
	LinkList pHead;
	Init_LinkList(&pHead);
	//Empty_LinkList(&pHead);
	//printf("长度=%d\n", Length_LinkList(&pHead));
	Create_HEAD_LinkList(&pHead);
	printf("Length=%d\n", Length_LinkList(&pHead));
	//Create_TAIL_LinkList(&pHead);
	//printf("长度=%d\n", Length_LinkList(&pHead));
	//Insert_LinkList(&pHead, 1, 222);
	//printf("长度=%d\n", Length_LinkList(&pHead));
	//Delete_LinkList(&pHead, 3);
	//printf("长度=%d\n", Length_LinkList(&pHead));
	//Get_LinkList(&pHead,55);
	Print_LinkList(&pHead);
	Destory_LinkList(&pHead);
	return 0;
}