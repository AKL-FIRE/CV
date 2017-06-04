/*
 * extendedChain.hpp
 *
 *  Created on: 2017年3月14日
 *      Author: lcy
 */

#ifndef EXTENDEDCHAIN_HPP_
#define EXTENDEDCHAIN_HPP_
#include "chain.hpp"

template<typename T>
class extendedChain : public chain<T>
{
private:
	chainNode<T>* lastNode;
public:
	extendedChain(int initial = 10) : chain<T>(initial),lastNode(nullptr){}
	~extendedChain();
	//void clear();
	void push_back(const T& theElement);
	void erase(int theIndex);
	void insert(int theIndex,const T& theElement);
};

template<typename T>
extendedChain<T>::~extendedChain()
{
}

template<typename T>
void extendedChain<T>::push_back(const T& theElement)
{
	if(chain<T>::listSize != 0)
	{
		lastNode->next = new chainNode<T>(theElement,nullptr);
		lastNode = lastNode->next;
	}
	else
	{
		insert(0,theElement);
		chain<T>::listSize--;
	}
	chain<T>::listSize++;
}

template<typename T>
void extendedChain<T>::erase(int theIndex)
{
	chain<T>::checkIndex(theIndex);
	chainNode<T>* deleteNode;
	if(theIndex == 0)
	{
		if(chain<T>::listSize == 1)
		{
			deleteNode = chain<T>::firstNode;
			chain<T>::firstNode = chain<T>::firstNode->next;
			lastNode = nullptr;
		}
		else
		{
			deleteNode = chain<T>::firstNode;
			chain<T>::firstNode = chain<T>::firstNode->next;
		}
	}
	else if(theIndex == chain<T>::listSize - 1)
	{
		chainNode<T>* p = chain<T>::firstNode;
		for(int i = 0;i < theIndex - 1; i++)
			p = p->next;
		deleteNode = p->next;
		lastNode = p;
	}
	else
	{
		chainNode<T>* p = chain<T>::firstNode;
		for(int i = 0;i < theIndex - 1; i++)
			p = p->next;
		deleteNode = p->next;
		p->next = p->next->next;
	}
	chain<T>::listSize--;
	delete deleteNode;
}

template<typename T>
void extendedChain<T>::insert(int theIndex,const T& theElement)
{
	if(theIndex < 0 || theIndex > chain<T>::listSize)
		{
			std::ostringstream s;
			s << "index = " << theIndex << "size = " << chain<T>::listSize;
			throw illegalIndex(s.str());
		}

		if(theIndex == 0)
		{
			if(chain<T>::listSize == 0)
			{
				lastNode = chain<T>::firstNode = new chainNode<T>(theElement,chain<T>::firstNode);
			}
			else
			{
				chain<T>::firstNode = new chainNode<T>(theElement,chain<T>::firstNode);
			}
		}
		else if(theIndex == chain<T>::listSize)
		{
			lastNode->next = new chainNode<T>(theElement,nullptr);
			lastNode = lastNode->next;
		}
		else
		{
			chainNode<T>* p = chain<T>::firstNode;
			for(int i = 0;i < theElement - 1; i++)
				p = p->next;
			p->next = new chainNode<T>(theElement,p->next);
		}
		chain<T>::listSize++;
}
#endif /* EXTENDEDCHAIN_HPP_ */
