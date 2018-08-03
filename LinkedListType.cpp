// LinkedListType.cpp
#ifndef LinkedListType_cpp
#define LinkedListType_cpp

#include <stdio.h>
#include <string>

#include "LinkedListType.h"

// LinkedListType function definitions
template<class Type>
bool LinkedListType<Type>::isEmptyList() const
{
	return (first == NULL);
}

template<class Type>
void LinkedListType<Type>::DestroyList()
{
	nodeType<Type> *temp;
	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}

	last = NULL;
	count = 0;
}

template<class Type>
void LinkedListType<Type>::Print() const
{
	nodeType<Type> *current;
	current = first;
	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->link;
	}
}

template<class Type>
LinkedListType<Type>::LinkedListType(const LinkedListType<Type> &otherList)
{
	first = NULL;
	CopyList(otherList);
}

// default constructor
template<class Type>
LinkedListType<Type>::LinkedListType()
{
	first = NULL;
	last = NULL;
	count = 0;
}

// destructor
template<class Type>
LinkedListType<Type>::~LinkedListType()
{
	DestroyList();
}

// LinkedListIterator function definitions
template<class Type>
LinkedListIterator<Type>::LinkedListIterator()
{
	current = NULL;
}

template<class Type>
LinkedListIterator<Type>::LinkedListIterator(nodeType<Type> *prt)
{
	current = ptr;
}

template<class Type>
Type LinkedListIterator<Type>::operator*()
{
	return current->info;
}

template<class Type>
LinkedListIterator<Type> LinkedListIterator<Type>::operator++()
{
	current = current->link;
	return *this;
}

template<class Type>
bool LinkedListIterator<Type>::operator==(const LinkedListIterator<Type>& right) const
{
	return (current != right.current);
}

#endif