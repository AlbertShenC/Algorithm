#include <stdio.h>

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

    if(i == j){
        return 0;
    }

    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    return 0;
}

// 数组划分
int Partition(int *array, int left, int right){
    int primary_element, i, j;
    primary_element = array[right];
    i = left - 1;
    for(j = left; j < right; j++){
        if(array[j] < primary_element){
            i += 1;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, right);
    return i + 1;
}

// 快速排序
int RealQuickSort(int *array, int left, int right){
    int middle;
    if(left < right){
        middle = Partition(array, left, right);
        RealQuickSort(array, left, middle - 1);
        RealQuickSort(array, middle + 1, right);
    }
    return 0;
}

// 快速排序（为了保持和其他排序相同的调用方式，对快速排序进行一定程度的封装）
int QuickSort(int *array, int array_length){
    RealQuickSort(array, 0, array_length - 1);
    return 0;
}

int main() {
    int array_to_sort[20] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
                             1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    QuickSort(array_to_sort, 20);
    PrintArray(array_to_sort, 20);
    return 0;
}
