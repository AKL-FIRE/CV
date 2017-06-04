/*
 * BST.CPP
 *
 *  Created on: 2017年5月22日
 *      Author: lcy
 */
#include<iostream>
#include<stack>
typedef int keytype;
typedef struct node
{
	keytype key;
	struct node *lchild,*rchild;
}bstnode;

void INSERT1(bstnode *t,bstnode *s)
{
	if(s->key < t->key)
	{
		if(t->lchild == nullptr)
			t->lchild = s;
		else
			INSERT1(t->lchild,s);
	}else
	{
		if(t->rchild == nullptr)
			t->rchild = s;
		else
			INSERT1(t->rchild,s);
	}
}

void INSERTBST1(bstnode* t,bstnode *s)
{
	if(t==nullptr)
		t=s;
	else
	{
		INSERT1(t,s);
	}
}

bstnode* CREATBST()
{
	bstnode *t,*s;
	keytype key,endflag=0;
	t=nullptr;
	std::cin >> key;
	while(key!=endflag)
	{
		s = new bstnode;
		s->lchild=s->rchild=nullptr;
		s->key = key;
		if(t == nullptr)
			t = s;
		else
			INSERT1(t,s);
		std::cin >> key;
	}
	return t;
}

void inorder(bstnode*p)
{
	if(p != nullptr)
	{
		inorder(p->lchild);
		std::cout << p->key << "  ";
		inorder(p->rchild);
	}
}

bool IsBinarySortTree(bstnode* bt)
{
    std::stack<bstnode*> s;
    bstnode* p = bt;
    bstnode* pre = nullptr;   // pre保持为p的中序前驱
    while(p || !s.empty())
    {
        if(p)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top(); s.pop();
            if( pre && (p->key <= pre->key) )  return false;  // 不是二叉排序树
            pre = p;   // 记下前驱结点
            p = p->rchild;
        }
    }
    return true;  // 二叉排序树
}

int main()
{
	bstnode *root = CREATBST();
	inorder(root);
	std::cout << std::endl;
	std::cout << IsBinarySortTree(root);
}
