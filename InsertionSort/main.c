#include <stdio.h>

// 输出数组结果
int PrintArray(int* array, int array_length){
    int i;
    for(i = 0; i < array_length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 插入排序，结果按升序排列
int InsertionSort(int* array, int array_length){
    int i, j; // 循环使用的临时变量
    int num_to_insert; // 数组排序使用的临时变量

    for(i = 1; i < array_length; i++){
        num_to_insert = array[i];
        j = i - 1;
        // 将array[i]插入至已经排好序的array[0 ~ i-1]之间
        while(j >= 0 && array[j] > num_to_insert){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = num_to_insert;
    }
    return 0;
}


int main() {
    int array_to_sort[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    InsertionSort(array_to_sort, 10);
    PrintArray(array_to_sort, 10);
    return 0;
}
