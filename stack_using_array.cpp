#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stack>
#include<stdlib.h>


struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmptry(struct stack* ptr){
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

int main(){
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    // s.arr[0] = 7;
    // s.top++;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // s->arr[0] = 7;
    // s->top++;

    if(isEmptry(s)){
        printf("The stack is empty");
    }
    else{
        printf("The stack is not empty");
    }
    printf("");
    return 0;
}
