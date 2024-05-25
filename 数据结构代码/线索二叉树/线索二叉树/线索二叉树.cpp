#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int Elemtype;

typedef struct BiThrNode {
	Elemtype data;
	struct BiThrNode* lchild, * rchild;
	int ltag, rtag;
}BiThrNode,*BiThrTree;

BiThrTree pre = NULL;//初始化全局变量pre，用于在构建线索二叉树的时候指向前一个节点

void visit(BiThrNode* q) {
	if (q->lchild == NULL) {
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre!=NULL&&pre->lchild==NULL)
	{
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}

void InOrderThrTree(BiThrTree T) {
	if (T != NULL) {
		InOrderThrTree(T->lchild);
		visit(T);
		InOrderThrTree(T->rchild);
	}
}

void CreateInThrTree(BiThrTree* T) {
	if (T != NULL) {
		InOrderThrTree(*T);
		if (pre->rchild == NULL) {
			pre->rtag = 1;
		}//处理最后一个有孩子节点
	}
}

BiThrTree FirstNode(BiThrTree p) {
	while (p->ltag == 0)
	{
		p = p->lchild;
	}//循环找到最左下的节点
	return p;
}//找到树中第一个被中序遍历的结点

BiThrTree NextNode(BiThrTree p) {
	if (p->rtag==0)
	{
		return FirstNode(p->rchild);
	}
	else
	{
		return p->rchild;
	}
}//找到后继节点

void InOrderThrTree(BiThrTree T) {
	for (BiThrTree p=FirstNode(T); p!=NULL; p=NextNode(p))
	{
		//visit(p);
	}
}//对中序线索二叉树进行中序遍历，时间复杂度为O（1）

BiThrTree LastNode(BiThrTree p) {
	while (p->rtag==0)
	{
		p = p->rchild;
	}//循环找到最右下的节点
	return p;
}//找到中序线索二叉树在中序遍历中的最后一个节点

BiThrTree PreNode(BiThrTree p) {
	if (p->ltag==0)
	{
		return LastNode(p->lchild);
	}
	else
	{
		return p->lchild;
	}
}//找到前驱节点

void RevOrderThrTree(BiThrTree T) {
	for (BiThrTree p = LastNode(T); p!=NULL; p=PreNode(p))
	{
		//visit(p);
	}
}//对中序线索二叉树进行逆向的中序遍历