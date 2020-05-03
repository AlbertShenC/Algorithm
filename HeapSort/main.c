#include <stdio.h>

#define PARENT(i) (i / 2)
#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)
#define HEAP_LENGTH 20

// 输出数组结果
int PrintArray(int *array, int array_length){
    int i;
    for(i = 0; i < array_length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
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
    int i;
    BuildHeap(heap);
    for(i = heap[0]; i >= 1; i--){
        swap(heap, 1, heap[0]);
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