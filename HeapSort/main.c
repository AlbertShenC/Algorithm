#include <stdio.h>

#define PARENT(i) (i / 2)
#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)
#define HEAP_LENGTH 20

// 输出数组结果
int PrintArray(int* array, int array_length){
    int i;
    for(i = 0; i < array_length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

// 递归维护最大堆
int MaintainMaxHeap(int *heap, int i){
    int largest, temp;
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
        temp = heap[largest];
        heap[largest] = heap[i];
        heap[i] = temp;
        MaintainMaxHeap(heap, largest);
    }
    return 0;
}

// 建堆
int BuildHeap(int *heap){
    int i;
    for(i = PARENT(heap[0]); i >= 1; i--){
        MaintainMaxHeap(heap, i);
    }
    return 0;
}

// 堆排序
int HeapSort(int *heap){
    int i, temp;
    BuildHeap(heap);
    for(i = heap[0]; i >= 1; i--){
        temp = heap[1];
        heap[1] = heap[heap[0]];
        heap[heap[0]] = temp;
        heap[0] -= 1;
        MaintainMaxHeap(heap, 1);
    }
}


int main() {
    int array_to_sort[HEAP_LENGTH + 1] = {HEAP_LENGTH, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                          20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    HeapSort(array_to_sort);
    PrintArray((array_to_sort + 1), HEAP_LENGTH);

    return 0;
}