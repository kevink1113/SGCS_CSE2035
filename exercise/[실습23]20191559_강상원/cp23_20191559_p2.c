#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char command[10];
    struct node* next;
} QUEUE_NODE;

typedef struct {
    QUEUE_NODE* front;
    int count;
    QUEUE_NODE* rear;
} QUEUE;

void FreeQueue(QUEUE*);
int CheckCommand(char* command);
void EnqueueCommand(QUEUE*, char*);

int main() {
    QUEUE* pQueue = (QUEUE*) malloc(sizeof(QUEUE));
    pQueue->count = 0;
    pQueue->front = NULL;
    pQueue->rear = NULL;

    char command[10];
    
    while (1) {
        printf(">>");
        scanf("%s", command);

        if (CheckCommand(command)) {
            if (!strcmp("h", command) || !strcmp("history", command))
                printf("queue count = %d\n", pQueue->count);
            else if (!strcmp("q", command) || !strcmp("quit", command)) 
				break;
			else {
                printf("[Valid] %s\n", command);
                EnqueueCommand(pQueue, command);
            }
        }

        else printf("[Invalid]\n");
    }
    
    FreeQueue(pQueue);

    return 0;
}

int CheckCommand(char* command) {
    char valid_op[][8] = {
        "help", "dir", "mkdir", "cd", "history", "h", "quit", "q"
    };

    for (int i = 0; i < 8; i++){
        if (!strcmp(command, valid_op[i])) return 1;
	}
    return 0;
}

void FreeQueue(QUEUE* queue) {
    if (queue->count != 0) {
        QUEUE_NODE* prev, *curr = queue->front;

        while (curr != NULL) {
            prev = curr;
            curr = curr->next;
            free(prev);
        }
    }
    free(queue);
}

void EnqueueCommand(QUEUE * pQueue, char* dataIn) {
    QUEUE_NODE* input = (QUEUE_NODE*) malloc(sizeof(QUEUE_NODE));
    strcpy(input->command, dataIn);
    input->next = NULL;

    if (pQueue->count == 0) {
        pQueue->front = input;
        pQueue->rear = input;
    }
    else {
        pQueue->rear->next = input;
        pQueue->rear = input;
    }
    pQueue->count++;
}
