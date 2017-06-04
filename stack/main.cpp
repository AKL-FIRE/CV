/*
 * main.cpp
 *
 *  Created on: 2017年3月21日
 *      Author: lcy
 */

#include "linkedStack.hpp"

int main()
{
	linkedStack<int> a(10);
	for(int i = 0;i < 10;i++)
		a.push(i);
	a.output(std::cout);
	a.pop();
	a.output(std::cout);
	a.push(10);
	a.push(11);
	a.push(12);
	a.push(13);
	std::cout << a;
}


