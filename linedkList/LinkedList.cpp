#include "iostream"
#include "LinkedList.h"
using namespace std;

void LinkedList::insertToHead(int input){
	
	Node *newNode = new Node();
	newNode->value = input;
	
	newNode->next = head;
	head = newNode;
	
	if(tail==NULL)
	tail = head;
	
	
}


void LinkedList::insertToTail(int input){
	
	Node *newNode = new Node();
	newNode->value = input;
	
	tail->next = newNode;
	tail = newNode;
	
	
}

void LinkedList::insertAfter(int input1, int input2){
	
	Node *newNode = new Node();
	newNode->value = input1;
	
	Node *tmp = new Node();
	tmp->value = input1;

	Node *currentNode = head;
	while (currentNode != NULL && currentNode->value != input2) {
    currentNode = currentNode->next;
	}

	if (currentNode == NULL) {
    // Node dengan nilai input2 tidak ditemukan
    delete tmp;
    return;
	}
	
	tmp->next = currentNode->next;
	currentNode->next = tmp;

	
}

void LinkedList::printAll(){
	
	
Node *tmp = head;
while (tmp != NULL)	{
	
	cout << tmp->value << "->";
	
	tmp = tmp->next;
	
}
	
	
}
