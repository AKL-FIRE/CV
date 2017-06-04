/*
 * linkedStack.hpp
 *
 *  Created on: 2017年3月21日
 *      Author: lcy
 */

#ifndef LINKEDSTACK_HPP_
#define LINKEDSTACK_HPP_
#include "Stack.hpp"
template<typename T>
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
class linkedStack : public stack<T>
{
public:
	linkedStack(int initialCapacity = 10) {stackTop = nullptr; stackSize = 0;}
	~linkedStack();
	bool empty() const {return stackSize == 0;}
	int size() const {return stackSize;}
	T& top()
	{
		if(stackSize == 0)
			throw illegalParameterValue("stack size is 0");
		return stackTop->element;
	}
	void pop();
	void push(const T& theElement)
	{
		stackTop = new chainNode<T>(theElement,stackTop);
		stackSize++;
	}
	void output(const std::ostream& out);
private:
	chainNode<T>* stackTop;
	int stackSize;
};

template<typename T>
linkedStack<T>::~linkedStack()
{
	while(stackTop != nullptr)
	{
		chainNode<T>* nextNode = stackTop->next;
		delete stackTop;
		stackTop = nextNode;
	}
}

template<typename T>
void linkedStack<T>::pop()
{
	if(stackSize == 0)
		throw illegalParameterValue("stack size is 0");
	chainNode<T>* nextNode = stackTop->next;
	delete stackTop;
	stackTop = nextNode;
	stackSize--;
}

template<typename T>
void linkedStack<T>::output(const std::ostream& out)
{
	if(stackTop == nullptr)
		throw illegalParameterValue("stack is empty");
	chainNode<T>* nextNode = stackTop;
	while(nextNode != nullptr)
	{
		std::cout << nextNode->element << std::endl;
		nextNode = nextNode->next;
	}
}

template<typename T>
const std::ostream& operator<<(const std::ostream& out, linkedStack<T>& stack)
{
	stack.output(out);
	return out;
}
#endif /* LINKEDSTACK_HPP_ */
