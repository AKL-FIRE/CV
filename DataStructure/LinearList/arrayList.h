#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "linearList.h"

template<typename T>
class arrayList : public linearList<T>
{
	public:
		arrayList(int initialCapacity = 10);
		arrayList(const arrayList<T>&);
		~arrayList() { delete [] element ;}

		bool empty() const { return listSize == 0;}
		int size() const { return listSize;}
		T& get(int theIndex) const;
		int indexOf(const T& theElement) const;
		void erase(int theIndex);
		void insert(int theIndex, const T& theElement);
		void output(std::ostream& out) const;

		int capacity() const { return arrayLength;}
		
		class iterator
		{
			public:
				iterator(T* thePosition = 0) {position = thePosition;}

				T& operator*() const {return *position;}
				T* operator->() const {return &*position;}
				
				iterator& operator++() {++position; return *this;}
				iterator operator++(int) {iterator old = *this; ++position; return old;}

				iterator& operator--() {--position; return *this;}
				iterator operator--(int)
				{
					iterator old = *this;
					--position;
					return old;
				}

				bool operator!=(const iterator right) const
				{
					return position != right.position;
				}
				bool operator==(const iterator right) const
				{
					return position == right.position;
				}
			protected:
				T* position;

		};

	protected:
		void checkIndex(int theIndex) const;
		T* element;
		int arrayLength;
		int listSize;
};

#endif
