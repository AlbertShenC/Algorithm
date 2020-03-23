#include <stdio.h>
#include <stdlib.h>

// 队列定义
typedef struct Queue{
    int* array;
    int length;
    int head;
    int tail;
}Queue;

// 初始化
Queue* QueueInit(int queue_length){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->array = (int*)malloc(sizeof(int) * (queue_length + 1));
    queue->head = 0;
    queue->tail = 0;
    queue->length = queue_length + 1;
    return queue;
}

// 判断队列是否已满
int QueueIsFull(Queue* queue){
    return (((queue->tail + 1) % queue->length) == queue->head);
}

// 判断队列是否为空
int QueueIsEmpty(Queue* queue){
    return (queue->head == queue->tail);
}

// 入队
int QueueEnqueue(Queue* queue, int number_to_enqueue){
    if(QueueIsFull(queue)){
        return -1;
    }

    queue->array[queue->tail] = number_to_enqueue;
    queue->tail  = (queue->tail + 1) % queue->length;
    return 0;
}

// 出队
int QueueDequeue(Queue* queue){
    int return_value = queue->array[queue->head];
    queue->head = (queue->head + 1) % queue->length;
    return return_value;
}

// 输出队列
int PrintQueue(Queue* queue){
    int i;

    printf("Queue: |");
    for(i = queue->head; i != queue->tail; i = (i + 1) % queue->length){
        printf(" %d |", queue->array[i]);
    }
    printf("\n\n");
}

int main() {
    Queue* queue = QueueInit(4);
    PrintQueue(queue);

    printf("Enqueue 10 (Should be 0): %d\n", QueueEnqueue(queue, 10));
    PrintQueue(queue);

    printf("Enqueue 56 (Should be 0): %d\n", QueueEnqueue(queue, 56));
    PrintQueue(queue);

    printf("Enqueue 7 (Should be 0): %d\n", QueueEnqueue(queue, 7));
    PrintQueue(queue);

    printf("Enqueue 14 (Should be 0): %d\n", QueueEnqueue(queue, 14));
    PrintQueue(queue);

    printf("Enqueue 88 (Should be -1): %d\n", QueueEnqueue(queue, 88));
    PrintQueue(queue);

    if(!QueueIsEmpty(queue)){
        printf("Dequeue 10 (Should be 10): %d\n", QueueDequeue(queue));
    }
    PrintQueue(queue);

    if(!QueueIsEmpty(queue)){
        printf("Dequeue 56 (Should be 56): %d\n", QueueDequeue(queue));
    }
    PrintQueue(queue);

    if(!QueueIsEmpty(queue)){
        printf("Dequeue 7 (Should be 7): %d\n", QueueDequeue(queue));
    }
    PrintQueue(queue);

    if(!QueueIsEmpty(queue)){
        printf("Dequeue 14 (Should be 14): %d\n", QueueDequeue(queue));
    }
    PrintQueue(queue);

    if(!QueueIsEmpty(queue)){
        printf("Dequeue ( You shouldn't see this): %d\n", QueueDequeue(queue));
    }
    PrintQueue(queue);

    return 0;
}