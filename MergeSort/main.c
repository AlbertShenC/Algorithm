#include <stdio.h>
#include <stdlib.h>

// 输出数组结果
int PrintArray(int* array, int array_length){
    int i;
    for(i = 0; i < array_length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

// 合并两个相连的数组
// 将已经有序的数组 array[0, array_length1 - 1] 与 array[array_length1, array_length1 + array_length2 - 1]
// 合并至 array[0, array_length1 + array_length2 - 1]，并依然保证有序
int Merge(int* array, int array_length1, int array_length2){
    int i, j, k; // 临时变量
    int* temp_array1 = (int*)malloc(sizeof(int) * (array_length1 + 1));
    int* temp_array2 = (int*)malloc(sizeof(int) * (array_length2 + 1));

    // 复制新数组，因为原数组将会用于储存结果
    for(i = 0; i < array_length1; i++){
        temp_array1[i] = array[i];
    }
    temp_array1[array_length1] = INT_MAX;
    for(i = 0; i < array_length2; i++){
        temp_array2[i] = array[array_length1 + i];
    }
    temp_array2[array_length2] = INT_MAX;

    // 进行归并操作
    j = 0;
    k = 0;
    for(i = 0; i < array_length1 + array_length2; i++){
        if(temp_array1[j] > temp_array2[k]){
            array[i] = temp_array2[k];
            k++;
        } else{
            array[i] = temp_array1[j];
            j++;
        }
    }

    // 释放申请的空间
    free(temp_array1);
    free(temp_array2);
    return 0;
}

// 归并排序，结果按升序排列
int MergeSort(int* array, int array_length){
    // 若数组长度为1，必然有序
    if(array_length == 1){
        return 0;
    }

    int half_array_length = array_length / 2;
    // 将数组分为两个部分，递归实现子数组的排序
    MergeSort(array, half_array_length);
    MergeSort(array + half_array_length, array_length - half_array_length);
    // 将已经排序完成的子数组合并，实现整个数组的排序
    Merge(array, half_array_length, array_length - half_array_length);

    return 0;
}

int main() {
    int array_to_sort[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    MergeSort(array_to_sort, 10);
    PrintArray(array_to_sort, 10);
    return 0;
}