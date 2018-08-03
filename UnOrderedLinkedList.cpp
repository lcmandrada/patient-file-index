// UnOrderedLinkedList.cpp
#ifndef UnOrderedLinkedList_cpp
#define UnOrderedLinkedList_cpp

#include "UnOrderedLinkedList.h"
#include "LinkedListType.h"

template <class Type>
bool UnorderedLinkedList<Type>::
Search(const Type& searchItem) const
{
	nodeType<Type> *current; //pointer to traverse the list
	bool found = false;

	current = first; //set current to point to the first 
	//node in the list

	while (current != NULL && !found)    //search the list
	if (current->info == searchItem) //searchItem is found
		found = true;
	else
		current = current->link; //make current point to
	//the next node
	return found;
}//end search

// reminder linked list insertion sort
template<class Type>
void UnorderedLinkedList<Type>::reSort(nodeType<Type> *&reminderA, nodeType<Type> *&reminderB)
{
	nodeType<Type> *lastInOrder;
	nodeType<Type> *firstOutOfOrder;
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent;

	lastInOrder = reminderA;
	if (reminderA == NULL)
	{	}
		// cerr << "Cannot sort an empty list." << endl;
	else if (reminderA->link == NULL)
	{	}
		// cerr << "It is already in order." << endl;
	else
	while (lastInOrder->link != NULL)
	{
		firstOutOfOrder = lastInOrder->link;

		string foooInfo = firstOutOfOrder->info;
		string firstInfo = reminderA->info;

		if (firstInfo.compare(foooInfo) > 0)
		{
			lastInOrder->link = firstOutOfOrder->link;
			firstOutOfOrder->link = reminderA;
			reminderA = firstOutOfOrder;
		}
		else
		{
			trailCurrent = reminderA;
			current = reminderA->link;

			string currentInfo = current->info;

			while (foooInfo.compare(currentInfo) > 0 && current->link != NULL)
			{
				trailCurrent = current;
				current = current->link;
				currentInfo = current->info;
			}
			if (current != firstOutOfOrder)
			{
				lastInOrder->link = firstOutOfOrder->link;
				firstOutOfOrder->link = current;
				trailCurrent->link = firstOutOfOrder;
			}
			else
				lastInOrder = lastInOrder->link;
		}
	}

	if (reminderB != NULL)
		while (reminderB->link != NULL)
		{
			reminderB = reminderB->link;
		}
}

// surname linked list insertion sort
template<class Type>
int UnorderedLinkedList<Type>::LinkedInsertionSort(nodeType<Type> *&surnameXA, nodeType<Type> *&surnameXB, nodeType<Type> *&nameA, bool &ins1, bool &ins2)
{
	nodeType<Type> *lastInOrder;
	nodeType<Type> *firstOutOfOrder;
	nodeType<Type> *inLine1;
	nodeType<Type> *inLine2;
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent;

	int currentLocation = 0;

	if (surnameXA == NULL)
	{	}
		// cerr << "Cannot sort an empty list." << endl;
	else if (surnameXA->link == NULL)
	{	}
		// cerr << "It is already in order." << endl;
	else
	{
		lastInOrder = surnameXA;
		firstOutOfOrder = surnameXA->link;
		inLine1 = nameA->link;

		while (firstOutOfOrder->link != NULL)
		{
			lastInOrder = lastInOrder->link;
			firstOutOfOrder = firstOutOfOrder->link;
			inLine1 = nameA->link;
		}

		Type foooInfo = firstOutOfOrder->info + inLine1->info;
		Type surnameInfo = surnameXA->info + nameA->info;

		if (foooInfo.compare(surnameInfo) < 0)
		{
			lastInOrder->link = firstOutOfOrder->link;
			firstOutOfOrder->link = surnameXA;
			surnameXA = firstOutOfOrder;
			ins1 = true;
		}
		else
		{
			trailCurrent = surnameXA;
			current = surnameXA->link;
			inLine2 = nameA->link;

			Type currentInfo = current->info + inLine2->info;

			while (currentInfo.compare(foooInfo) < 0 && current != firstOutOfOrder)
			{
				trailCurrent = current;
				current = current->link;
				inLine2 = inLine2->link;
				currentInfo = current->info + inLine2->info;
				currentLocation++;
			}

			if (current != firstOutOfOrder)
			{
				lastInOrder->link = firstOutOfOrder->link;
				firstOutOfOrder->link = current;
				trailCurrent->link = firstOutOfOrder;
				ins2 = true;
			}
		}
	}

	while (surnameXB->link != NULL)
	{
		surnameXB = surnameXB->link;
	}

	return currentLocation;
}

template <class Type>
void UnorderedLinkedList<Type>::InsertFirst(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	newNode->info = newItem;    //store the new item in the node
	newNode->link = first;      //insert newNode before first
	first = newNode;            //make first point to the
	//actual first node
	count++;                    //increment count

	if (last == NULL)   //if the list was empty, newNode is also 
		//the last node in the list
		last = newNode;
}//end insertFirst

template <class Type>
void UnorderedLinkedList<Type>::InsertLast(const Type& newItem, nodeType<Type> *&XA, nodeType<Type> *&XB)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	newNode->info = newItem;  //store the new item in the node
	newNode->link = NULL;     //set the link field of newNode
	//to NULL

	if (XA == NULL)  //if the list is empty, newNode is 
		//both the first and last node
	{
		XA = newNode;
		XB = newNode;
		count++;        //increment count
	}
	else    //the list is not empty, insert newNode after last
	{
		XB->link = newNode; //insert newNode after last
		XB = newNode; //make last point to the actual 
		//last node in the list
		count++;        //increment count
	}
}//end insertLast

template <class Type>
int UnorderedLinkedList<Type>::DeleteNode(const Type& deleteItem, nodeType<Type> *&surnameXA, nodeType<Type> *&surnameXB, bool &del1, bool &del2, bool &delLast)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;
	int currentLocation = 0;

	del1 = del2 = delLast = false;

	if (surnameXA == NULL)    //Case 1; the list is empty. 
		cout << "Cannot delete from an empty list."
		<< endl;
	else
	{
		if (surnameXA->info == deleteItem) //Case 2 
		{
			current = surnameXA;
			surnameXA = surnameXA->link;
			count--;

			if (surnameXA == NULL)    //the list has only one node
				surnameXB = NULL;

			delete current;
			
			del1 = true;
		}
		else //search the list for the node with the given info
		{
			found = false;

			trailCurrent = surnameXA;  //set trailCurrent to point
			//to the first node
			current = surnameXA->link; //set current to point to 
			//the second node

			while (current != NULL && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
					currentLocation++;
				}
				else
					found = true;
			}//end while

			if (found) //Case 3; if found, delete the node
			{
				trailCurrent->link = current->link;
				count--;

				if (surnameXB == current)   //node to be deleted was the last node
				{
					surnameXB = trailCurrent; //update the value 
					//of last
					delLast = true;
				}
					
				delete current;  //delete the node from the list
				del2 = true;
			}
			else
				cout << "The item to be deleted is not in "
				<< "the list." << endl;
		}//end else
	}//end else

	return currentLocation;
}//end deleteNode

#endif