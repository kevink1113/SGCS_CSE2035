#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char c;
    struct _Node *link;
} Node;

Node *head = NULL, *tail = NULL;

void InsertNodeAtFront(char a);
void InsertNodeAtBack(char b);
void DeleteNodeAtFront();
void DeleteNodeAtBack();
void PrintList();
void FreeList();

int main() {
    InsertNodeAtFront('n');
    InsertNodeAtFront('e');
    InsertNodeAtFront('p');
    InsertNodeAtBack('l');
    InsertNodeAtFront('o');
    InsertNodeAtBack('a');
    InsertNodeAtBack('b');
    PrintList();

    DeleteNodeAtFront();
    DeleteNodeAtBack();
    DeleteNodeAtBack();
    DeleteNodeAtBack();
    PrintList();

    FreeList();

    return 0;
}

void InsertNodeAtFront(char a) {
    Node *new = (Node*)malloc(sizeof(Node));
    new->c = a;
    new->link = NULL;

    if (head == NULL) {
        head = new;
        tail = head;
    }
    else {
        new->link = head;
        head = new;
    }
}

void InsertNodeAtBack(char b) {
    Node *new = (Node*)malloc(sizeof(Node));
    new->c = b;
    new->link = NULL;

    if (head == NULL) {
        head = new;
        tail = head;
    }
    else {
        tail->link = new;
        tail = tail->link;
    }
}

void DeleteNodeAtFront() {
    Node* tmp = head;
    head = head->link;
    free(tmp);
}

void DeleteNodeAtBack() {
    Node *curr = head;

    while (1) {
        if (curr->link == NULL) break;
        if ((curr->link)->link == NULL) break;
        curr=curr->link;
    }
    free(curr->link);
    curr->link=NULL;
}

void PrintList() {
    Node *curr = head;

    while (1) {
        printf("%c", curr->c);
        if (curr->link==NULL) break;
        curr=curr->link;
    }

    printf("\n");
}

void FreeList() {
    Node *prev = head;
    Node *curr = prev->link;

    while (1) {
        free(prev);
        prev = curr;
        if (curr->link == NULL) break;
        curr = curr->link;
    }
    free(curr);
}
