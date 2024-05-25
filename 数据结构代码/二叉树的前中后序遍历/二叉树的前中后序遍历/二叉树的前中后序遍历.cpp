#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode {
	int data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;

bool PreOrderTraverse(BiTree T) {
	if (T == NULL)
	{
		return false;
	}
	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

bool InOrderTraverse(BiTree T) {
	if (T == NULL)
	{
		return false;
	}
	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}

bool PostOrderTraverse(BiTree T) {
	if (T==NULL)
	{
		return false;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}
