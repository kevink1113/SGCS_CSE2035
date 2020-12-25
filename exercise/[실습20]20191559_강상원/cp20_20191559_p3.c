#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node{
    int data;
    nptr *link;
} NODE;

void Insert(nptr*, int);
void Sort(nptr*);
void PrintAll(nptr);

int main(){
    int A[10] = { 3, 9, 8, 2, 5, 10, 7, 1, 4, 6 };
    nptr head = NULL;

    for (int i = 0; i < 10; i++)
        Insert(&head, A[i]);

    PrintAll(head);
    
    Sort(&head);
    PrintAll(head);
    
    return 0;
}

void Insert(nptr* head, int value){
    nptr curr = *head;
    int i;

    nptr newnode = (nptr)malloc(sizeof(NODE));
    newnode->data = value;
    newnode->link = NULL;

    if (curr == NULL) {
        *head = newnode;
        return;
    }

    while (1) {
        if (curr->link == NULL) break;
        curr = curr->link;
    }

    curr->link = newnode;
}

void Sort(nptr* head){
    nptr curr = *head;
    nptr pre = curr;
    int i, j, size = 0;

    while (1){
        if (curr == NULL) break;
        size++;
        curr = curr->link;
    }

    curr = *head;

    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if (pre->link == NULL) break;

            if ((pre->data) > ((nptr) pre->link)->data){
                int tmp = pre->data;
                pre->data = ((nptr)pre->link)->data;
            	((nptr)pre->link)->data = tmp;
            }
            pre = pre->link;
        }
        pre = curr;
    }
}

void PrintAll(nptr ptr){
    nptr curr = ptr;
    while (1) {
        if (curr == NULL) break;
        printf("%d ", curr->data);
        curr = curr->link;
    }
    printf("\n");
}
