#include <stdio.h>
#include <stdlib.h>

#define PARENT(i) (i / 2)
#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)

// 优先队列定义
typedef struct PriorityQueue{
    int* array;
    int max_size;
}PriorityQueue;

// 输出数组结果
int PrintPriorityQueue(PriorityQueue *priority_queue){
    int i;
    if(priority_queue->array[0] == 0){
        printf("Queue is empty!\n\n");
        return 0;
    }

    for(i = 1; i <= priority_queue->array[0]; i++){
        printf("%d ", priority_queue->array[i]);
    }
    printf("\n\n");
    return 0;
}

// 交换数组 下标i 和 下标j 对应的值
int swap(int *array, int i, int j){
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    return 0;
}

// 递归维护最大堆
int MaintainMaxHeap(int *heap, int i){
    int largest;
    int left = LEFT(i);
    int right = RIGHT(i);
    if(left <= heap[0] && heap[left] > heap[i]){
        largest = left;
    } else{
        largest = i;
    }
    if(right <= heap[0] && heap[right] > heap[largest]){
        largest = right;
    }
    if(largest != i){
        swap(heap, largest, i);
        MaintainMaxHeap(heap, largest);
    }
    return 0;
}

// 初始化优先队列
PriorityQueue* PriorityQueueInit(int max_size){
    PriorityQueue* priority_queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    priority_queue->array = (int*)malloc(sizeof(int) * (max_size + 1));
    priority_queue->array[0] = 0;
    priority_queue->max_size = max_size;
    return priority_queue;
}

// 判断优先队列是否已满
int PriorityQueueIsFull(PriorityQueue *priority_queue){
    return (priority_queue->array[0] == priority_queue->max_size);
}

// 判断优先队列是否已空
int PriorityQueueIsEmpty(PriorityQueue *priority_queue){
    return (priority_queue->array[0] == 0);
}

// 优先队列入队
int PriorityQueueEnqueue(PriorityQueue *priority_queue, int number_to_enqueue){
    int i;
    priority_queue->array[0] += 1;
    i = priority_queue->array[0];
    priority_queue->array[priority_queue->array[0]] = number_to_enqueue;
    while(i > 1 && priority_queue->array[PARENT(i)] < priority_queue->array[i]){
        swap(priority_queue->array, PARENT(i), i);
    }
    return 0;
}

// 优先队列队首元素
int PriorityQueueHead(PriorityQueue *priority_queue){
    return priority_queue->array[1];
}

// 优先队列出队
int PriorityQueueDequeue(PriorityQueue *priority_queue){
    int return_number = priority_queue->array[1];
    priority_queue->array[1] = priority_queue->array[priority_queue->array[0]];
    priority_queue->array[0] -= 1;
    MaintainMaxHeap(priority_queue->array, 1);
    return return_number;
}

int main() {
    PriorityQueue *priority_queue = PriorityQueueInit(4);
    PrintPriorityQueue(priority_queue);

    printf("Enqueue 10 (Should be 0): %d\n", PriorityQueueEnqueue(priority_queue, 10));
    printf("Is Queue empty? (Should be 0): %d\n", PriorityQueueIsEmpty(priority_queue));
    printf("Is Queue full? (Should be 0): %d\n", PriorityQueueIsFull(priority_queue));
    PrintPriorityQueue(priority_queue);

    printf("Enqueue 5 (Should be 0): %d\n", PriorityQueueEnqueue(priority_queue, 5));
    printf("Is Queue empty? (Should be 0): %d\n", PriorityQueueIsEmpty(priority_queue));
    printf("Is Queue full? (Should be 0): %d\n", PriorityQueueIsFull(priority_queue));
    PrintPriorityQueue(priority_queue);

    printf("Enqueue 20 (Should be 0): %d\n", PriorityQueueEnqueue(priority_queue, 20));
    printf("Is Queue empty? (Should be 0): %d\n", PriorityQueueIsEmpty(priority_queue));
    printf("Is Queue full? (Should be 0): %d\n", PriorityQueueIsFull(priority_queue));
    PrintPriorityQueue(priority_queue);

    printf("Enqueue 15 (Should be 0): %d\n", PriorityQueueEnqueue(priority_queue, 15));
    printf("Is Queue empty? (Should be 0): %d\n", PriorityQueueIsEmpty(priority_queue));
    printf("Is Queue full? (Should be 1): %d\n", PriorityQueueIsFull(priority_queue));
    PrintPriorityQueue(priority_queue);

    printf("Queue head(Should be 20):%d\n\n", PriorityQueueHead(priority_queue));

    if(!PriorityQueueIsEmpty(priority_queue)){
        printf("Dequeue (Should be 20):%d\n", PriorityQueueDequeue(priority_queue));
        PrintPriorityQueue(priority_queue);
    }

    if(!PriorityQueueIsEmpty(priority_queue)){
        printf("Dequeue (Should be 15):%d\n", PriorityQueueDequeue(priority_queue));
        PrintPriorityQueue(priority_queue);
    }

    printf("Queue head(Should be 10):%d\n\n", PriorityQueueHead(priority_queue));

    if(!PriorityQueueIsEmpty(priority_queue)){
        printf("Dequeue (Should be 10):%d\n", PriorityQueueDequeue(priority_queue));
        PrintPriorityQueue(priority_queue);
    }

    if(!PriorityQueueIsEmpty(priority_queue)){
        printf("Dequeue (Should be 5):%d\n", PriorityQueueDequeue(priority_queue));
        PrintPriorityQueue(priority_queue);
    }

    if(!PriorityQueueIsEmpty(priority_queue)){
        printf("Dequeue (You shouldn't see this):%d\n", PriorityQueueDequeue(priority_queue));
        PrintPriorityQueue(priority_queue);
    }

    return 0;
}
