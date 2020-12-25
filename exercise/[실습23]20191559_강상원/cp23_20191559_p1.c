#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} QUEUE_NODE;

typedef struct {
	QUEUE_NODE* front;
	int count;
	QUEUE_NODE* rear;
} QUEUE;

void Exit(QUEUE*);
void Enqueue(QUEUE* queue);
void PrintAll(QUEUE);

int main() {
	int opt, input;
	printf("****** Menu ******\n");
	printf("* 0 : Exit       *\n");
	printf("* 1 : Enqueue    *\n");
	printf("* 2 : -------    *\n");
	printf("* 3 : Print All  *\n");
	printf("******************\n");
	
	QUEUE* queue=(QUEUE*)malloc (sizeof(QUEUE));
	queue->count=0;
	queue->front==NULL;
	queue->rear=NULL;

	while(1){
		printf("Select > ");
		int opt;
		scanf("%d", &opt);
		if (opt==0) return 0;
		else if (opt==1) Enqueue(queue);
		else PrintAll(*queue);
	}

	Exit(queue);

	return 0;
}

void Exit(QUEUE* queue){
	if(queue->count != 0){
		QUEUE_NODE* prv;
		QUEUE_NODE*idx=queue->front;

		while(idx != NULL){
			prv=idx;
			idx=idx->next;
			free(prv);
		}
	}
	free(queue);
}
void Enqueue(QUEUE* queue){
	printf("Input Data > ");
	int in;
	scanf("%d", &in);

	QUEUE_NODE* input =(QUEUE_NODE*)malloc (sizeof(QUEUE_NODE));
	input->data=in;
	input->next=NULL;
	if (queue->count==0){
		queue->front=input;
		queue->rear=input;
	}
	else {
		queue->rear->next=input;
		queue->rear=input;
	}
	(queue->count)++;
}
void PrintAll(QUEUE queue){
	QUEUE_NODE* idx/*=(QUEUE_NODE*)malloc(sizeof(QUEUE_NODE))*/;

	idx=queue.front;
	if (queue.count==0) printf("Empty!\n");
	else {
		while(1){
			printf("%d ", idx->data);
			if (idx->next == NULL) break;
			idx=idx->next;
		}
		printf("\nQueue Level : %d\n", queue.count);
	}

}
