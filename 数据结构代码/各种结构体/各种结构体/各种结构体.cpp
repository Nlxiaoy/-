#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 10
typedef int ElemType;


typedef struct {
	ElemType data[MAX_SIZE];
	int length;
}SqList;//顺序表_静态分配

typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}DSqList;//顺序表_动态分配

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;//单链表

typedef struct DNode {
	ElemType data;
	struct DNode* prior;
	struct DNode* next;
}DNode,*DLinkList;//双链表

typedef struct {
	ElemType data[MAX_SIZE];
	int top;
}SqStack;//栈_顺序表

typedef struct {
	ElemType data[MAX_SIZE];
	int top1;
	int top2;
}SqDStack;//共享栈

//链栈
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode,*LinkStackPtr;

typedef struct {
	LinkStackPtr top;
	int count;
}LinkStack;

typedef struct {
	ElemType data[MAX_SIZE];
	int front;
	int rear;
}SqQueue;//循环队列

//链队列
typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode,*QNodePtr;

typedef struct {
	QNodePtr rear;
	QNodePtr front;
}LinkQueue;

//树_双亲表示法
typedef struct PTNode {
	ElemType data;
	struct PTNode* next;
}PTNode;

typedef struct {
	PTNode nodes[MAX_SIZE];
	int r, n;
}PTree;

//树_孩子表示法
typedef struct CTNode {
	ElemType data;
	struct CTNode* next;
}*childPtr;

typedef struct {
	ElemType data;
	childPtr firstchild;
}CTBOX;

typedef struct {
	CTBOX nodes[MAX_SIZE];
	int r, n;
}CTree;

//树_孩子兄弟表示法
typedef struct CSNode {
	ElemType data;
	struct CSNode* firstchild;
	struct CSNode* rightsib;
}CSNode,*CSTree;


typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,* BiTree;//二叉树_链表

typedef struct BiThrNode {
	ElemType data;
	struct BiThrNode* lchild;
	struct BiThrNode* rchild;
	int ltag, rtag;
}BiThrNode,*BiThrTree;//线索二叉树