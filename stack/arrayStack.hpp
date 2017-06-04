/*
 * arrayStack.hpp
 *
 *  Created on: 2017年3月21日
 *      Author: lcy
 */

#ifndef ARRAYSTACK_HPP_
#define ARRAYSTACK_HPP_

#include "Stack.hpp"
template<typename T>
class arrayStack : public stack<T>
{
public:
	arrayStack(int initialCapacity = 10);
	~arrayStack() {delete [] stack;}
	bool empty() const {return stackTop == -1;}
	int size() const {return stackTop + 1;}
	T& top()
	{
		if(stackTop == -1)
			throw illegalParameterValue("stack is empty");
		return stack[stackTop];
	}
	void pop()
	{
		if(stackTop == -1)
			throw illegalParameterValue("stack is empty");
		stack[stackTop--].~T();
	}
	void push(const T& theElement);
	void output(const std::ostream& out);
private:
	int stackTop;
	int arrayLength;
	T* stack;
};

template<typename T>
arrayStack<T>::arrayStack(int initialCapacity)
{
	if(initialCapacity < 1)
	{
		std::ostringstream s;
		s << "Initial capacity = " << initialCapacity << " must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;
	stack = new T[arrayLength];
	stackTop = -1;
}

template<typename T>
void arrayStack<T>::push(const T& theElement)
{
	if(stackTop == arrayLength - 1)
	{
		T* temp = new T[arrayLength * 2];
		std::copy(stack,stack + arrayLength,temp);
		delete [] stack;
		stack = temp;
	}
	stack[++stackTop] = theElement;
}

template<typename T>
void arrayStack<T>::output(const std::ostream& out)
{
	if(stackTop == -1)
		throw illegalParameterValue("stack is empty");
	for(int i = 0;i <= stackTop;i++)
		std::cout << stack[i] << std::endl;
}

template<typename T>
const std::ostream& operator<<(const std::ostream& out, arrayStack<T>& stack)
{
	stack.output(out);
	return out;
}

#endif /* ARRAYSTACK_HPP_ */
