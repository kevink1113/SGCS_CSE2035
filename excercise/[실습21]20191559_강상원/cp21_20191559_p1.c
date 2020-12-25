#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node{
	int data;
	struct node *link;
} NODE;

void Insert (NODE**, int );
void Delete(NODE**);
void PrintAll(NODE*);

int main() {
	int A[10]={3,9,8,2,5,10,7,1,4,6};
	nptr head=(nptr)malloc(sizeof(NODE));
	
	head->link=NULL;
	nptr idx=head;

	for(int i=0; i<10; i++){
		Insert(&idx, A[i]);
		idx=idx->link;
	}

	idx=head;

	for(int i=0; i<10; i++){
		Delete(&head);
		PrintAll(head);
	}
	idx->link=NULL;

	PrintAll(head);
	printf("Empty\n");
	free(idx); free(head); 
	
	return 0;
}
void Insert(nptr* idx, int input){
	(*idx)->link=(NODE*)malloc(sizeof(NODE));
	(*idx)->data=input;
}

void Delete(nptr* head){
	nptr tmp;
	tmp= *head;
	(*head)=tmp->link;
	free(tmp);
}

void PrintAll(nptr head){
	nptr curr=head;
	while(1){
		if (curr->link==NULL) break;
		printf("%d ", curr->data);
		curr=curr->link;
	}
	printf("\n");
	//free(curr);
/*
	for(int i=0; i<10; i++){
		printf("%d ", curr->data);
		curr=curr->link;
	}
	printf("\n");
	*/
}
