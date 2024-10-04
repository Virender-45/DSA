#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elment %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *deletefirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

struct Node *deleteAtlast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("Value : %d not found!\n", value);
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocates memory for linked lists in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the linked list at third node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked List before deletion\n");
    linkedlistTraversal(head);

    printf("Linked List after deletion\n");
    // head = deletefirst(head);
    // head = deleteAtIndex(head, 2);
    // head = deleteAtlast(head);
    head = deleteAtValue(head, 13);
    linkedlistTraversal(head);

    return 0;
}