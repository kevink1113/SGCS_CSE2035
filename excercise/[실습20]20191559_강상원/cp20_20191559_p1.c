#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node {
	char data;
	nptr link;
} NODE;

nptr head = NULL, tail = NULL;

void InsertNodeAtFront(char);
void InsertNodeAtBack(char);
void PrintList();

int main() {	
	InsertNodeAtFront('p');
	InsertNodeAtFront('p');
	InsertNodeAtFront('a');
	InsertNodeAtBack('l');
	InsertNodeAtBack('e');
	PrintList();

	return 0;
}

void InsertNodeAtFront(char a) {
	nptr newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = a;
	newNode->link = NULL;

	if (head == NULL) {
		head = newNode;
		tail = head;
	}
	else {
		newNode->link = head;
		head = newNode;
	}
}

void InsertNodeAtBack(char b) {
	nptr newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = b;
	newNode->link = NULL;

	if (head == NULL) {
		head = newNode;
		tail = head;
	}
	else {
		tail->link = newNode;
		tail = tail->link;
	}
}

void PrintList() {
	nptr curr = head;

	while (1) {
		printf("%c", curr->data);
		if (curr->link == NULL) break;
		curr = curr->link;
	}
	printf("\n");
}
