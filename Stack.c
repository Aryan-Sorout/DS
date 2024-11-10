#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int top;
    int item[MAX];
}Stack;

void init(Stack*stack){
    stack->top=-1;
}

int isFull(Stack*stack){
    return stack->top==MAX-1;
}

int isEmpty(Stack*stack){
    return stack->top==-1;
}

void push(Stack*stack,int value){
    if(isFull(stack)){
        printf("Stack Overflowed!\n");
    }else{
        stack->item[++stack->top]=value;
    }
}

int pop(Stack*stack){
    if(isEmpty(stack)){
        printf("Stack Underflowed!");
        return -1;
    }else{
        return stack->item[stack->top--];
    }
}

int peek(Stack*stack){
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack->item[stack->top];
    }
}

void display(Stack*stack){
    if(isEmpty(stack)){
        printf("Stack Underflowed!");
        
}else{
    printf("Stack:\n");
    for(int i=stack->top;i>=0;i--){
        printf("%d",stack->item[i]);
    }
}
}


int main(){
    Stack stack;
    init(&stack);
     int choice, data;
    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                if (data != -1)
                    printf("Popped %d from the stack\n", data);
                break;
            case 3:
                data = peek(&stack);
                if (data != -1)
                    printf("Top element is %d\n", data);
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}