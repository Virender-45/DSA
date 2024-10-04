#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflwo\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}
void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elment: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int peek(int pos)
{   
    struct Node *top = NULL;
    struct Node* ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}
int main()
{
    struct Node *top = NULL;
    top = push(top, 7);
    top = push(top, 22);
    top = push(top, 4);
    top = push(top, 3);

    printf("Value at position 1 is %d", peek(1));

    // linkedlistTraversal(top);

    // int element = pop(&top);
    // printf("Popped element is : %d\n ",element);

    linkedlistTraversal(top);

    return 0;
}