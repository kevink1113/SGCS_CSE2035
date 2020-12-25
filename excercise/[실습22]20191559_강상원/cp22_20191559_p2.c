#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;

typedef struct {
    int count;
    nptr link;
} STACK;

typedef struct node {
	char data;
    nptr link;
} STACK_NODE;

void Push(STACK *, char);
int Pop(STACK *);

void Free(STACK *);
char Sangwon(STACK* stack);

int main() {
    char str[100];
    STACK stack;
    stack.count = 0;
    stack.link = NULL;

    int op = 1;

	scanf("%s", str);

    for (int i=0; ; i++) {
        if (str[i] == '\0') break;

        if (str[i] == '(') Push(&stack, '(');
        else if (str[i] == '[') Push(&stack, '[');
        else if (str[i] == '{') Push(&stack, '{');
        
		else if (str[i] == ')') {
            char in = Sangwon(&stack);
            if (in == '(') Pop(&stack);
            else {
                op = 0;
                break;
            }
        }
        else if (str[i] == ']') {
            char in = Sangwon(&stack);
            if (in == '[') Pop(&stack);
            else {
                op = 0;
                break;
            }
        }
        else if (str[i] == '}') {
            char in = Sangwon(&stack);
            if (in == '{') Pop(&stack);
            else {
                op = 0;
                break;
            }
        }

    }

    if (stack.count) op = 0;

    if (op) printf("Matched Parentheses!\n");
    else printf("Unmatched Parentheses!\n");

    Free(&stack);

    return 0;
}

void Free(STACK* stack) {
    nptr cur = stack->link;
    nptr prv;

    while (cur != NULL) {
        prv = cur;
        if (cur->link == NULL) {
            free(cur);
            break;
        }
        cur = cur->link;
        free(prv);
    }
}

void Push(STACK* stack, char c) {
    nptr newNode = (nptr)malloc(sizeof(STACK_NODE));
    newNode->data = c;
    newNode->link = stack->link;
    stack->link = newNode;
    stack->count++;
}

int Pop(STACK* stack) {
    if (stack->count == 0) return 0;

    nptr tmp = stack->link;
    stack->link = stack->link->link;
    free(tmp);
    stack->count--;
    return 1;
}

char Sangwon(STACK* stack) {
    if (stack->count == 0) return -1;
    return stack->link->data;
}
