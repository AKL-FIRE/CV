/*
 * BiTree.cpp
 *
 *  Created on: 2017年6月4日
 *      Author: lcy
 */
#include<iostream>
#include<queue>

template<typename T>
struct BiTNode
{
	T data;
	struct BiTNode<T> *lchild,*rchild;
};

template<typename T>
void CreateBiTree(BiTNode<T>*& p)
{
	BiTNode<T>* ptt = NULL;
	std::cout << "Input node's data,end by '#'\n";
	T ch;
	std::queue<BiTNode<T>*> que;
	while((ch = std::cin.get()) != '#')
	{
		BiTNode<T> *temp = new BiTNode<T>;
		temp->data = ch;
		temp->lchild = temp->rchild = NULL;
		if(que.empty())
		{
			p = ptt = temp;
			que.push(ptt);
		}
		else if(ptt->lchild == NULL)
		{
			ptt->lchild = temp;
			que.push(ptt->lchild);
		}
		else if(ptt->lchild != NULL && ptt->rchild == NULL)
		{
			ptt->rchild = temp;
			que.push(ptt->rchild);
			que.pop();
			ptt = que.front();
		}
	}
}

template<typename T>
void PreOrderTraverse(BiTNode<T>* p)
{
	if(p != NULL)
	{
		std::cout << p->data << "   ";
		PreOrderTraverse(p->lchild);
		PreOrderTraverse(p->rchild);
	}
}

template<typename T>
void InOrderTraverse(BiTNode<T>* p)
{
	if(p != NULL)
	{
		InOrderTraverse(p->lchild);
		std::cout << p->data << "   ";
		InOrderTraverse(p->rchild);
	}
}

template<typename T>
void PostOrderTraverse(BiTNode<T>* p)
{
	if(p != NULL)
	{
		PostOrderTraverse(p->lchild);
		PostOrderTraverse(p->rchild);
		std::cout << p->data << "   ";
	}
}
