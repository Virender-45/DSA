#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stack>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;

};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}


int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
} 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("\nStack Overflow! Cannot push %d to the stack.\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("\nStack Underflow! Cannot pop from the stack.\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack* sp, int i){
    int arrayInd = sp->top-i+1;
    if(arrayInd < 0){
        printf("Not a valid position");
        return -1;
    }
    else
    return sp->arr[arrayInd];
}

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
int stackBottom(struct stack* sp){
    return sp->arr[0];
}

int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    // printf("Before Pushing : Full %d\n", isFull(sp));
    // printf("Before Pushing : Empty %d\n", isEmpty(sp));
    push(sp, 10);
    push(sp, 20);
    push(sp, 30);
    push(sp, 40);
    push(sp, 50);
    push(sp, 60);
    push(sp, 70);
    push(sp, 80);
    push(sp, 90);
    push(sp, 100);
    // printf("After Pushing : full %d\n", isFull(sp));
    // printf("After Pushing : Empty %d\n", isEmpty(sp));

    // printf("Popped %d from the stack " ,pop(sp));

    // for (int j = 1; j <= sp->top+1; j++)
    // {
    //     printf("The value at position %d is %d \n",j ,peek(sp,j));
    // }
    printf("The top most element in the stack is : %d\n ", stackTop(sp));
    printf("The bottom most element in the stack is : %d\n", stackBottom(sp));

    return 0;
}