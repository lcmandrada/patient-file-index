// UnOrderedLinkedList.h
#ifndef UnOrderedLinkedList_h
#define UnOrderedLinkedList_h

#include "LinkedListType.h"

template<class Type>
class UnorderedLinkedList :public LinkedListType<Type>
{
public:
	bool Search(const Type& searchItem) const;
	void InsertFirst(const Type& newItem);
	void InsertLast(const Type& newItem, nodeType<Type> *&XA, nodeType<Type> *&XB);
	int DeleteNode(const Type& deleteItem, nodeType<Type> *&surnameXA, nodeType<Type> *&surnameXB, bool &del1, bool &del2, bool &delLast);

	void reSort(nodeType<Type> *&reminderA, nodeType<Type> *&reminderB);
	int LinkedInsertionSort(nodeType<Type> *&surnameXA, nodeType<Type> *&surnameXB, nodeType<Type> *&nameA, bool &ins1, bool &ins2);
};

#include "UnOrderedLinkedList.cpp"
#endif