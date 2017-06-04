/*
 * chain.hpp
 *
 *  Created on: 2017年3月14日
 *      Author: lcy
 */

#ifndef CHAIN_HPP_
#define CHAIN_HPP_

#include "linearList.hpp"

template <typename T>
struct chainNode
{
	T element;
	chainNode<T> *next;

	chainNode() {this->next = nullptr;}
	chainNode(const T& element)
	{
		this->element = element;
		this->next = nullptr;
	}
	chainNode(const T& element, chainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
};


template<typename T>
class chain : public linearList<T>
{
public:
	chain(int iniatialCapacity = 10);
	chain(const chain<T>&);
	~chain();

	bool empty() const {return listSize == 0;}
	int size() const {return listSize;}
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(std::ostream& out) const;

protected:
	void checkIndex(int theIndex) const;
	chainNode<T>* firstNode;
	int listSize;
};

template<typename T>
chain<T>::chain(int initialCapacity)
{
	if(initialCapacity < 1)
	{
		std::ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	firstNode = nullptr;
	listSize = 0;

}

template <typename T>
chain<T>::chain(const chain<T>& theList)
{
	listSize = theList.listSize;

	if(listSize == 0)
	{
		firstNode = nullptr;
		return;
	}

	chainNode<T>* sourceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);
	sourceNode = sourceNode->next;
	chainNode<T>* targetNode = firstNode;
	while(sourceNode != nullptr)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = nullptr;
}

template<typename T>
chain<T>::~chain()
{
	while(firstNode != nullptr)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

template<typename T>
T& chain<T>::get(int theIndex) const
{
	checkIndex(theIndex);

	chainNode<T>* currentNode = firstNode;
	for(int i = 0;i < theIndex; i++)
		currentNode = currentNode->next;
	return currentNode->element;
}

template<typename T>
int chain<T>::indexOf(const T& theElement) const
{
	chainNode<T>* currentNode = firstNode;
	int index = 0;
	while(currentNode != nullptr && currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}

	if(currentNode == nullptr)
		return -1;
	else
		return index;
}

template<typename T>
void chain<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	chainNode<T>* deleteNode;
	if(theIndex == 0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		chainNode<T>* p = firstNode;
		for(int i = 0;i < theIndex - 1; i++)
			p = p->next;
		deleteNode = p->next;
		p->next = p->next->next;
	}
	listSize--;
	delete deleteNode;
}

template<typename T>
void chain<T>::insert(int theIndex, const T& theElement)
{
	if(theIndex < 0 || theIndex > listSize)
	{
		std::ostringstream s;
		s << "index = " << theIndex << "size = " << listSize;
		throw illegalIndex(s.str());
	}

	if(theIndex == 0)
		firstNode = new chainNode<T>(theElement,firstNode);
	else
	{
		chainNode<T>* p = firstNode;
		for(int i = 0;i < theElement - 1; i++)
			p = p->next;
		p->next = new chainNode<T>(theElement,p->next);
	}
	listSize++;
}

template<typename T>
void chain<T>::output(std::ostream& out) const
{
	for(chainNode<T>* currentNode = firstNode; currentNode != nullptr; currentNode = currentNode->next)
		out << currentNode->element << std::endl;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const chain<T>& x)
{
	x.output(out);
	return out;
}

template<typename T>
void chain<T>::checkIndex(int theIndex) const
{
    if(theIndex < 0 || theIndex >= listSize)
    {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
}

#endif /* CHAIN_HPP_ */
