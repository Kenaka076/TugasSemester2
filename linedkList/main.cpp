#include <iostream>
#include "LinkedList.h"

using namespace std;


int main(int argc, char** argv) {
	
		LinkedList list1;
		list1.insertToHead(10);
		list1.insertToHead(20);
		
		//inserttoTail
		list1.insertToTail(30);
		list1.insertToTail(40);
		
		//insertAfter
		list1.insertAfter(50, 10);
		list1.insertAfter(60, 50);
		
		cout<< "head:" <<list1.head->value <<endl;
	
		cout<< "tail:" <<list1.tail->value <<endl;
	
	
		
	list1.printAll();
	return 0;
}
