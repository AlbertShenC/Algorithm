#include <stdio.h>
#include <stdlib.h>

// 定义栈
typedef struct Stack{
    int* array;
    int top;
    int length;
}Stack;

// 初始化栈
Stack* StackInit(int stack_length){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->array = (int*)malloc(sizeof(int) * stack_length);
    stack->top = -1;
    stack->length = stack_length;
    return stack;
}

// 判断栈是否已满
int StackIsFull(Stack* stack){
    return (stack->top >= (stack->length - 1));
}

// 判断栈是否为空
int StackIsEmpty(Stack* stack){
    return (stack->top < 0);
}

// 压栈
int StackPush(Stack* stack, int number_to_push){
    if(StackIsFull(stack)){
        return -1;
    } else{
        stack->top ++;
        stack->array[stack->top] = number_to_push;
        return 0;
    }
}

// 出栈
int StackPop(Stack* stack){
    stack->top --;
    return stack->array[stack->top + 1];
}

// 输出栈
int PrintStack(Stack* stack){
    int i;

    printf("stack: |");
    for(i = 0; i <= stack->top; i++){
        printf(" %d |", stack->array[i]);
    }
    printf("\n\n");
    return 0;
}

int main() {
    Stack* stack = StackInit(4);
    PrintStack(stack);

    printf("Push 5 (Should be 0): %d\n", StackPush(stack, 5));
    PrintStack(stack);

    printf("Push 1 (Should be 0): %d\n", StackPush(stack, 1));
    PrintStack(stack);

    printf("Push 0 (Should be 0): %d\n", StackPush(stack, 0));
    PrintStack(stack);

    printf("Push 45 (Should be 0): %d\n", StackPush(stack, 45));
    PrintStack(stack);

    printf("Push 7 (Should be -1): %d\n", StackPush(stack, 7));
    PrintStack(stack);

    if(!StackIsEmpty(stack)){
        printf("Pop 45 (Should be 45): %d\n", StackPop(stack));
    }
    PrintStack(stack);

    if(!StackIsEmpty(stack)){
        printf("Pop 0 (Should be 0): %d\n", StackPop(stack));
    }
    PrintStack(stack);

    if(!StackIsEmpty(stack)){
        printf("Pop 1 (Should be 1): %d\n", StackPop(stack));
    }
    PrintStack(stack);

    if(!StackIsEmpty(stack)){
        printf("Pop 5 (Should be 5): %d\n", StackPop(stack));
    }
    PrintStack(stack);

    if(!StackIsEmpty(stack)){
        printf("Pop Fail (You Shouldn't see this): %d\n", StackPop(stack));
    }
    PrintStack(stack);

    return 0;
}