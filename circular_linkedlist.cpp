#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *InsertAtfirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last node of the circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr; 

    return head;
}
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * InsertAfterNode(struct Node *head,struct Node *prevNode,int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}
struct Node* InsertAtEnd(struct Node* head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node* p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;

    return head;
}



int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 15;
    second->next = third;

    third->data = 20;
    third->next = fourth;

    fourth->data = 25;
    fourth->next = head;

    printf("Circular linked list before insertion\n");
    linkedlisttraversal(head);
    printf("Circular linked list after insertion\n");
    //head = InsertAtfirst(head, 5);
    //head = insertAtIndex(head, 100, 2);
    //head = InsertAfterNode(head, fourth, 78);
    //head = InsertAtEnd(head, 30);

    linkedlisttraversal(head);

    return 0;
}