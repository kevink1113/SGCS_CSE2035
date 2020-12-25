#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char command[8];
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
int DequeuePrint(QUEUE*, char*);

int main() {
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->count = 0;
    queue->front = NULL;
    queue->rear = NULL;

    char opt[1000], tmp[1000];

    while (1) {
        printf(">>");
        scanf("%s", opt);

        if (CheckCommand(opt)) {
            if (!strcmp("h", opt) || !strcmp("history", opt)) {
                while (DequeuePrint(queue, tmp)) {
                    printf("%s\n", tmp);
                }
            }
            else if (!strcmp("q", opt) || !strcmp("quit", opt)) 
                break;
            
            else {
                printf("[Valid] %s\n", opt);
                EnqueueCommand(queue, opt);
            }
        }
        else printf("[Invalid]\n");
        
    }

    FreeQueue(queue);

    return 0;
}

int CheckCommand(char* command) {
    char valid_op[][8] = {
        "help", "dir", "mkdir", "cd", "history", "h", "quit", "q"
    };

    for (int i = 0; i < 8; i++) 
        if (!strcmp(command, valid_op[i])) return 1;

    return 0;
}

void FreeQueue(QUEUE* queue) {
    if (queue->count != 0) {
        QUEUE_NODE* prv, *cur = queue->front;

        while (cur != NULL) {
            prv = cur;
            cur = cur->next;
            free(prv);
        }
    }

    free(queue);
}

void EnqueueCommand(QUEUE * pQueue, char* dataIn) {
    QUEUE_NODE* newNode = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    strcpy(newNode->command, dataIn);
    newNode->next = NULL;

    if (pQueue->count == 0) {
        pQueue->front = newNode;
        pQueue->rear = newNode;
    }
    else {
        pQueue->rear->next = newNode;
        pQueue->rear = newNode;
    }

    pQueue->count++;
}

int DequeuePrint(QUEUE* pQueue, char* dataOut) {
    if (pQueue->count == 0) return 0;
    if (pQueue->count == 1) pQueue->rear == NULL;

    QUEUE_NODE* cur = pQueue->front;

    strcpy(dataOut, cur->command);
    pQueue->front = cur->next;
    free(cur);
    pQueue->count--;

    return 1;
}
