#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedlisttraversalforward(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}

void linkedlisttraversalbackward(struct Node *last)
{
    struct Node *ptr = last;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->prev;
    } while (ptr != NULL);
}

void InsertAtfirst(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return; 
    }

    newNode->data = newData;
    newNode->next = *headRef;

    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }

    newNode->prev = NULL;
    *headRef = newNode;
}

int main()
{
    struct Node *n1;
    struct Node *n2;
    struct Node *n3;
    struct Node *n4;

    n1 = (struct Node *)malloc(sizeof(struct Node));
    n2 = (struct Node *)malloc(sizeof(struct Node));
    n3 = (struct Node *)malloc(sizeof(struct Node));
    n4 = (struct Node *)malloc(sizeof(struct Node));

    n1->prev = NULL;
    n1->data = 1;
    n1->next = n2;

    n2->prev = n1;
    n2->data = 11;
    n2->next = n3;

    n3->prev = n2;
    n3->data = 111;
    n3->next = n4;

    n4->prev = n3;
    n4->data = 1111;
    n4->next = NULL;

    printf("Before Insertion\n");
    linkedlisttraversalforward(n1);
    printf("After Insertion\n");
    InsertAtfirst(&n1, 2);
    linkedlisttraversalforward(n1);
    return 0;
};