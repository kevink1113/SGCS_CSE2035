#include <stdio.h>
#include <stdlib.h>
typedef struct node *sptr;
typedef struct {
	int count;
	sptr link;
} STACK;
typedef struct node {
	int data;
	sptr link;
} STACK_NODE;

void Exit(STACK*);
void Push(STACK*);
void Pop(STACK*);
void PrintAll(STACK);

int main() {
	int opt=0;
	STACK stack;
	stack.link=NULL;
	stack.count=0;
	printf("****** Menu ******\n");
	printf("* 0 : Exit       *\n");
	printf("* 1 : Push       *\n");
	printf("* 2 : Pop        *\n");
	printf("* 3 : Print All  *\n");
	printf("******************\n");

	while(1){
		printf("Select > ");
		scanf("%d", &opt);
		
		switch(opt){
			case 0:
				Exit(&stack);
				return 0;
			case 1:
				Push(&stack);
				break;
			case 2:
				Pop(&stack);
				break;
			case 3:
				PrintAll(stack);
				break;
		}
	}
	return 0;
}

void Exit(STACK* stack) {
	sptr cur=stack->link;
	sptr prv;
	while(cur!=NULL){
		prv=cur;
		if (cur->link==NULL){
			free(cur);
			break;
		}
		cur=cur->link;
		free(prv);
	}
}

void Push(STACK* stack){
	int input;
	printf("Input Data > ");
	scanf("%d", &input);
	sptr pNew;

	pNew=(sptr)malloc(sizeof(STACK_NODE));
	
	pNew->data= input;
	pNew->link= stack->link;
	stack->link=pNew;
	stack->count++;
}

void Pop(STACK* stack){
	sptr pDlt;
	if (stack->link){
		pDlt=stack->link;
		printf("Pop %d\n", pDlt->data);
		stack->link=(stack->link)->link;
		stack->count--;
		free(pDlt);
	}
	else {
		printf("Stack is Empty!\n");
	}
}

void PrintAll(STACK stack){
	sptr curr= (&stack)->link;
	//printf("adsa\n");
	int arr[stack.count];
	/*if (curr){
		for(int i=0; i<count; i++){
			if (curr==NULL) break;
			printf("%d ", curr->data);
			curr=curr->link;
		}

		printf("\n");
	}*/

	if (curr){
		for(int i=0; i<stack.count; i++){
			arr[i]=curr->data;
			curr=curr->link;
		}
		for(int i=stack.count-1; i>=0; i--)
			printf("%d ", arr[i]);
		printf("\n");
		printf("Stack Level : %d\n", stack.count);
	}
	else printf("Stack is Empty!\n");

	free(curr);
}
