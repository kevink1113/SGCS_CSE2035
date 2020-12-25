#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} NODE;

typedef NODE* nptr;

nptr head=NULL, tail=NULL;

void Insert(nptr* head, int data, int index);
void PrintAll(nptr head);

int cnt=0;

int main() {
    int A[10]={3,9,8,2,5,10,7,1,4,6};
    int idx=0;
    
    nptr newnode=(NODE*)malloc (sizeof(NODE));
    Insert(&head, A[0], 0);
    PrintAll(head);

    Insert(&head, A[1], 0);
    PrintAll(head);

    Insert(&head, A[2], 1);
    PrintAll(head);

    Insert(&head, A[3], 2);
    PrintAll(head);
    
    Insert(&head, A[4], 0);
    PrintAll(head);
    
    Insert(&head, A[5], 1);
    PrintAll(head);

    Insert(&head, A[6], 10);
    PrintAll(head);

    Insert(&head, A[7], 4);
    PrintAll(head);

    Insert(&head, A[8], -1);
    PrintAll(head);
    
    Insert(&head, A[9], 3);
    PrintAll(head);


    return 0;
}

void Insert(nptr* head, int data, int index){
    nptr newnode=(NODE*)malloc (sizeof(NODE));
    
    newnode->data=data;
    if (index == -1) index = 0x7fffffff;
    
    if (index==0){
        newnode->link= (*head);
        *head=newnode;
    }
    /*
    else if (index==-1 || index>cnt){
        tail->link=newnode;
        cnt++;
        tail=newnode;
    }
    */
    
    else {
        nptr curr=(*head);
        
        for(int i=0; i<index-1; i++){
            if (curr->link == NULL) break;
            curr=curr->link;
        }
        newnode->link=curr->link;
        curr->link=newnode;

        cnt++;
    }

}

void PrintAll(nptr head){
    nptr curr3=head;
    while(1){
        printf("%d ",curr3->data);
        if (curr3->link ==NULL) break;
        curr3=curr3->link;
    }
    printf("\n");
}
