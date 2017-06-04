/*
 * Stack.hpp
 *
 *  Created on: 2017年3月21日
 *      Author: lcy
 */

#ifndef STACK_HPP_
#define STACK_HPP_
#include <iostream>
#include <sstream>
#include "Exception.hpp"
template<typename T>
class stack
{
public:
	virtual ~stack() {}
	virtual bool empty() const =0;
	virtual int size() const =0;
	virtual T& top() =0;
	virtual void pop() =0;
	virtual void push(const T& theElement) =0;
	virtual void output(const std::ostream& out) =0;
};


#endif /* STACK_HPP_ */
