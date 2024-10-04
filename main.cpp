#include <stdio.h>
#include <conio.h>
#include <malloc.h>

/*
// Insertion in an array

 void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf(" \n");
}
int indInsertion(int arr[], int size, int element, int capacity, int index){
    if (size>=capacity)
    {
        return -1;
    }
    for (int i = size-1; i >=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main(){
    int arr[100] = {1,2,6,8};
    int size = 4, element = 5, index = 100;
    display(arr, 4);
    indInsertion(arr, size, element, 100, index);
    size +=1;
    display(arr ,size);

    return 0;
}

*/

/*

// array as an abstract data type

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray * a, int tSize, int uSize){
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));/

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void setVal(struct myArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the element %d : ",i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main(){
    struct myArray marks;
    createArray(&marks, 10, 2);
    printf("We are running setval now - \n");
    setVal(&marks);
    printf("We are running show now - \n ");
    show(&marks);

    return 0;
}
*/

// Deletion in an array

/*
void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf(" \n");
}
void indDeletion(int arr[], int size, int index){
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
}

int main(){
    int arr[100] = {1,2,6,8,10,12};
    int size = 6, index = 2;
    display(arr, size);
    indDeletion(arr, size, index);
    size -= 1;
    display(arr ,size);

    return 0;
}

*/

/*

// Linear Search

int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {24,5,7,8,34,732,34,324,6,436};
    int size = sizeof(arr)/sizeof(int);
    int element = 34;
    int searchIndex = linearSearch(arr,size,element);
    printf("The element %d found at index %d " ,element,searchIndex);

    return 0;
}

*/

/*
//Binary Saerch

int binarySearch(int arr[], int size, int element){
    int low,high,mid;
    low = 0;
    high = size-1;
    // Start Searching
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    // End Searching
    }
    return -1;
}
    int main(){
    int arr[] = {1,2,4,5,8,9,10,45,67,87,90,99};
    int size = sizeof(arr)/sizeof(int);
    int element = 67;
    int saerchIndex = binarySearch(arr, size, element);
    printf("The elmenet %d is found at index : %d ",element,saerchIndex);

    return 0;
}

*/

// Linked List

struct Node
{
    int data;
    struct Node * next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elment %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocates memory for linked lists in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Terminate the linked list at third node
    third->data = 66;
    third->next = NULL;

    linkedlistTraversal(head);

    return 0;
}