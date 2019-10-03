#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Node
{
	int index;
	struct Node *next;
	struct Node *previous;
};

struct Node *head = NULL;

// Inserts the elements in tho the Doubly Linked List
void insert(int data)
{
	struct Node * ptrPreNode;
	ptrPreNode = head;

	struct Node * NewNode = (struct Node*)malloc(sizeof(struct Node));

	NewNode->index = data;
	NewNode->next = head;
	head = NewNode;
	if (ptrPreNode != NULL)
	{
		ptrPreNode->previous = head;
	}
}
// Prints the list
void display(void)
{
	struct Node * ptrNode = new struct Node;
	ptrNode = head;
	cout<<"\tIndex Val"<<" \t    "<<"Index Location"<<" \t    "<<"Next Location"<<" \t  "<<"Previous Location"<<endl;
	while(ptrNode != NULL)
	{
		cout<<"\tNode : "<<ptrNode->index<<" \t:\t "<<&(ptrNode->index)<<" \t:\t "<<ptrNode->next<<" \t:\t "<<ptrNode->previous<<endl;
		ptrNode = ptrNode->next;
	}
	delete ptrNode;
}

int main(int argc, char const *argv[])
{
	for(int i = 0; i<20 ; i++)
	{
		insert(i);
	}
	display();
	return 0;
}