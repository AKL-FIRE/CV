/*
 * main.cpp
 *
 *  Created on: 2017年6月4日
 *      Author: lcy
 */


#include "BiTree.cpp"

int main()
{
	BiTNode<char>* p;
	CreateBiTree(p);
	PreOrderTraverse(p);
	std::cout << std::endl;
	InOrderTraverse(p);
	std::cout << std::endl;
	PostOrderTraverse(p);
}

