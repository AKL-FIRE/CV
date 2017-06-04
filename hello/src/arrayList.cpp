#include "arrayList.h"
#include <sstream>
#include <iterator>
#include <algorithm>
#include "exception.cpp"
using namespace std;

template<typename T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
	if(newLength < 0)
		throw illegalParameterValue("new length must be >= 0");

	T* temp = new T[newLength];
	int number = min(oldLength, newLength);
	copy(a, a + number, temp);
	delete [] a;
	a = temp;
}

template<typename T>
arrayList<T>::arrayList(int initialCapacity)
{
	if(initialCapacity < 1)
	{
		std::ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}

template<typename T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element, theList.element + listSize, element);
}

template<typename T>
void arrayList<T>::checkIndex(int theIndex) const
{
	if(theIndex < 0 || theIndex >= listSize)
	{
		std::ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}
}

template<typename T>
T& arrayList<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}

template<typename T>
int arrayList<T>::indexOf(const T& theElement) const
{
	int theIndex = 0;
	for(int i = 0;i <= listSize;i++)
	{
		if(element[i] == theElement)
			break;
		theIndex++;
	}
	if(theIndex == listSize)
		return -1;
	else
		return theIndex;
}

template<typename T>
void arrayList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T();
}

template<typename T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	if(theIndex < 0 || theIndex > listSize)
	{
		std::ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}

	if(listSize == arrayLength)
	{
		changeLength1D(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}

	copy_backward(element + theIndex, element + listSize, element + listSize + 1);
	element[theIndex] = theElement;
	listSize++;
}

template<typename T>
void arrayList<T>::output(std::ostream& out) const
{
	copy(element, element + listSize, ostream_iterator<T>(std::cout, " "));
}
