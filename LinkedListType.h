// LinkedListType.h
#ifndef LinkedListType_h
#define LinkedListType_h

// node definition
template<class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template<class Type>
class LinkedListIterator
{
public:
	LinkedListIterator(); // default constructor

	LinkedListIterator(nodeType<Type> *ptr); // constructor with 1 parameter

	Type operator*(); // overload the dereference operator
	LinkedListIterator<Type> operator++(); // overload the pre-increment operator

	bool operator==(const LinkedListIterator<Type>& right) const; // overload the equality operator

private:
	nodeType<Type> *current; // pointer to point to the current node in the linked list
};

template<class Type>
class LinkedListType
{
public:
	// overload the assignment operator
	const LinkedListType<Type>& operator = (const LinkedListType<Type>&);
	void InitializeList();
	bool isEmptyList() const;
	void Print() const;
	int Length() const;
	void DestroyList();

	virtual bool Search(const Type& searchItem) const = 0;
	virtual void InsertFirst(const Type& newItem) = 0;
	virtual void InsertLast(const Type& newItem, nodeType<Type> *&XA, nodeType<Type> *&XB) = 0;
	virtual int DeleteNode(const Type& deleteItem, nodeType<Type> *&surnameXA, nodeType<Type> *&surnameXB, bool &del1, bool &del2, bool &delLast) = 0;

	LinkedListIterator<Type> begin();
	LinkedListIterator<Type> end();

	LinkedListType(); // default constructor
	LinkedListType(const LinkedListType<Type>& otherList); // copy constructor
	~LinkedListType(); // destructor

	int count;
	nodeType<Type> *first;
	nodeType<Type> *last;
	bool insertToFirst, insertToCurrent;

private:
	void CopyList(const LinkedListType<Type>& otherList);
};

#include "LinkedListType.cpp"
#endif