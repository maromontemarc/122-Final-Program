#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>
class LinkedList {

private:
	struct ListNode {
		T value;
		struct ListNode *next;
		int roll;
	};
	ListNode *head;

public:
	LinkedList()
	{
		head = nullptr;
	}
	LinkedList(const LinkedList &);
	~LinkedList();
	
	void appendNode(T);
	void insertNode(T, int);
	void reverse();
	int search(T);
	void deleteNode();
	void deleteAt(int);
	void print() const;
	void print(int) const;
	void destroy();
	void sortList();
	T getNodeAt(int);

	int getNodeNum();
	void operator[](const int &);

};
#endif

template <class T>
LinkedList<T>::LinkedList(const LinkedList &listObj)
{
	ListNode *nodePtr = nullptr;

	head = nullptr;

	nodePtr = listObj.head;

	while (nodePtr)
	{
		appendNode(nodePtr->value);

		nodePtr = nodePtr->next;
	}
}

// Appends node
//
template <class T>
void LinkedList<T>::appendNode(T newValue) {

	ListNode *newNode;
	ListNode *nodePtr;

	newNode = new ListNode;
	newNode->value = newValue;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else {
		nodePtr = head;
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;
	}
}

// Sorts list
//
template <class T>
void LinkedList<T>::sortList() {

	ListNode * temphead = head;
	int temproll;
	int count = 0;

	while (temphead)
	{
		temphead = temphead->next;
		count++;
	}
	temphead = head;

	for (int j = 0; j < count; j++)
	{
		while (temphead->next)
		{
			if (temphead->value > temphead->next->value)
			{
				temproll = temphead->value;
				temphead->value = temphead->next->value;
				temphead->next->value = temproll;

				temphead = temphead->next;
			}
			else
				temphead = temphead->next;
		}
		temphead = head;
	}
}

// Reverses list
//
template <class T>
void LinkedList<T>::reverse() {

	ListNode *current = head;
	ListNode *prev = nullptr;
	ListNode *next = nullptr;

	while (current != nullptr)
	{
		
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}
	head = prev;
}

// Searches list
//
template <class T>
int LinkedList<T>::search(T searchValue) {

	int index = -1, temp = 0;
	ListNode *nodePtr;
	nodePtr = head;

	while (nodePtr->value != searchValue && nodePtr->next != nullptr) {

		temp++;
		nodePtr = nodePtr->next;
	}

	if (nodePtr->value == searchValue) {

		index = temp;
	}

	return index;
}

// Counts nodes
//
template <class T>
int LinkedList<T>::getNodeNum() {

	int nodeNum = 0;
	ListNode *nodePtr;
	nodePtr = head;

	while (nodePtr) {

		nodePtr = nodePtr->next;
		nodeNum++;
	}
	return nodeNum;
}

// Overloads bracket operator
//
template <class T>
void LinkedList<T>::operator[](const int &sub) {
	const char * error = "Invalid subscript";

	if (sub < 0 || sub >= getNodeNum()) {
		throw error;
	}
	else {
		print(sub);
	}
}

// Prints list
//
template <class T>
void LinkedList<T>::print() const {

	ListNode *nodePtr;
	nodePtr = head;

	while (nodePtr) {

		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
}

// Prints at position
//
template <class T>
void LinkedList<T>::print(int pos) const {

	ListNode *nodePtr;
	nodePtr = head;

	for (int i = 0; i <= pos; i++) {

		if (i == pos) {
			cout << nodePtr->value << endl;
		}
		else {
			nodePtr = nodePtr->next;
		}
	}
}

// Inserts node at position
//
template <class T>
void LinkedList<T>::insertNode(T newValue, int pos) {

	ListNode *newNode = new ListNode;
	newNode->value = newValue;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	if (pos == 0)
	{
		newNode->next = head;
		head = newNode;
		return;
	}

	ListNode *p = head; 
	int numberToSkip = 1; 
	while (numberToSkip <= pos)
	{
		if (p->next == nullptr || numberToSkip == pos)
		{
			ListNode *tempPtr = p->next;
			p->next = newNode;
			newNode->next = tempPtr;
			return;
		}
		p = p->next;
		numberToSkip++;
	}
}

// Deletes last node
//
template <class T>
void LinkedList<T>::deleteNode() {

	if (head == nullptr) {
		return;
	}

	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}

	ListNode *nodePtr = head;

	while (nodePtr->next && nodePtr->next->next != nullptr) {

		nodePtr = nodePtr->next;
	}

	delete nodePtr->next;
	nodePtr->next = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {

	destroy();
}

// Deletes at position
//
template <class T>
void LinkedList<T>::deleteAt(int pos) {

	ListNode *nodePtr;
	ListNode *nextNode;
	ListNode *previousNode;

	nodePtr = head;
	previousNode = nullptr;

	if (head == nullptr) {
		return;
	}

	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}

	if (pos == getNodeNum() || pos > getNodeNum()) {
		return;
	}

	if (pos == 0) {

		nextNode = nodePtr->next;
		head = nextNode;
		delete nodePtr;
	}
	else {
		for (int i = 0; i <= pos; i++) {

			if (i == pos) {
				nextNode = nodePtr->next;
				previousNode->next = nextNode;
				delete nodePtr;
			}
			else {
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}
		}
	}
}

// Destroys list
//
template<class T>
void LinkedList<T>::destroy() {

	ListNode *nodePtr, *nextNode = nullptr;

	nodePtr = head;
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}

	head = nullptr;
}

// Returns node at position
//
template <class T>
T LinkedList<T>::getNodeAt(int n) {
	ListNode *nodePtr;
	nodePtr = head;

	for (int i = 0; i <= n; i++) {

		if (i == n) {
			return nodePtr->value;
		}
		else {
			nodePtr = nodePtr->next;
		}
	}
}