#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node {
	int data;
	nptr link;
} NODE;

void Insert(nptr*, int);
void PrintAll(nptr);

int main() {
	int A[10]={3,9,8,2,5,10,7,1,4,6};
	nptr head= (NODE*)malloc(sizeof(NODE));
	head->link=NULL;

	nptr idx=head;

	for(int i=0; i<10; i++){
		Insert(&idx, A[9-i]);
		idx=idx->link;
	}

	idx->link=NULL;
	
	PrintAll(head);

	free(idx);

	return 0;
}

void Insert(nptr* idx, int input){
	(*idx)->link=(NODE*)malloc (sizeof(NODE));
	(*idx)->data= input;
}

void PrintAll (nptr head){
	nptr idx= head;
	while (1){
		if (idx->link==NULL) break;
		printf("%d ", idx->data);
		idx=idx->link;
	}
	printf("\n");
}
