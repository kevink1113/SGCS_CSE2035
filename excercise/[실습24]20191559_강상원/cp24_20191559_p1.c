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
void Enqueue(QUEUE*);
void Dequeue(QUEUE*);
void PrintAll(QUEUE);

int main() {
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->count = 0;
    queue->front = NULL;
    queue->rear = NULL;

    int opt;

    printf("****** Menu ******\n");
    printf("* 0 : Exit       *\n");
    printf("* 1 : Enqueue    *\n");
    printf("* 2 : Dequeue    *\n");
    printf("* 3 : Print All  *\n");
    printf("******************\n");

    int exitopt = 0;

    while (!exitopt) {
        printf("Select > ");
        scanf("%d", &opt);

        switch (opt) {
        case 0:
            exitopt = 1;
            break;
        case 1:
            Enqueue(queue);
            break;
        case 2:
            Dequeue(queue);
            break;
        case 3:
            PrintAll(*queue);
            break;
        default:
            break;
        }
    }
    Exit(queue);

    return 0;
}

void Exit(QUEUE* queue) {
    if (queue->count != 0) {
        QUEUE_NODE* prv;
		QUEUE_NODE* cur = queue->front;

        while (cur != NULL) {
            prv = cur;
            cur = cur->next;
            free(prv);
        }
    }
    free(queue);
}

void Enqueue(QUEUE * queue) {
    int data;
    printf("Input Data > ");
    scanf("%d", &data);

    QUEUE_NODE* newNode = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->count == 0) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    (queue->count)++;
}

void Dequeue(QUEUE * queue) {
    if (queue->count == 0) {
        printf("Queue is empty!\n");
        return;
    }
    if (queue->count == 1) queue->rear == NULL;

    QUEUE_NODE* cur = queue->front;
    printf("Dequeue %d\n", cur->data);

    queue->front = cur->next;
    free(cur);
    (queue->count)--;
}

void PrintAll(QUEUE queue) {
    if (queue.count == 0) {
        printf("Queue is empty!\n");
        return;
    }

    QUEUE_NODE* cur = queue.front;

    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    printf("\n");
    printf("Queue Level : %d\n", queue.count);
}
