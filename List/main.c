#include <stdio.h>
#include <stdlib.h>

// 列表节点
typedef struct ListNode{
    int data;
    struct ListNode* prev;
    struct ListNode* next;
}ListNode;

// 列表
typedef struct List{
    struct ListNode* head;
    int length;
}List;

// 初始化一个列表，不包含任何数据
List* ListInit(){
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->length = 0;
    return list;
}

// 在list列表中搜索data为number_to_search的第一个节点，并返回此节点
ListNode* ListSearch(List* list, int number_to_search){
    ListNode* node = list->head;
    while(node != NULL && node->data != number_to_search){
        node = node->next;
    }
    return node;
}

// 新建一个data为number_to_add的节点，并将其添加至list列表头部
int ListAdd(List* list, int number_to_add){
    // 新建节点
    ListNode* node_to_add = (ListNode*)malloc(sizeof(ListNode));
    node_to_add->data = number_to_add;
    node_to_add->next = list->head;
    node_to_add->prev = NULL;

    // 将新节点插入至列表头部
    if(list->head != NULL){
        list->head->prev = node_to_add;
    }
    list->head = node_to_add;
    list->length ++;
    return 0;
}

// 从list列表中删除node节点，并free掉node节点
int ListDelete(List* list, ListNode* node){
    if(node->prev == NULL){
        list->head = node->next;
    } else{
        node->prev->next = node->next;
    }

    if(node->next != NULL){
        node->next->prev = node->prev;
    }
    free(node);
    list->length --;

    return  0;
}

// 输出list列表
int PrintList(List* list){
    printf("list length: %d\n", list->length);
    printf("list -> ");
    ListNode* node = list->head;
    while(node != NULL){
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n\n");
    return 0;
}

int main() {
    List* list = ListInit();
    PrintList(list);

    ListAdd(list, 5);
    ListAdd(list, 10);
    ListAdd(list, 7);
    ListAdd(list, 1);
    PrintList(list);

    ListNode* node = ListSearch(list, 10);
    printf("list node data (should be 10): %d\n\n", node->data);

    ListDelete(list, node);
    PrintList(list);

    ListDelete(list, ListSearch(list, 1));
    ListDelete(list, ListSearch(list, 5));
    ListDelete(list, ListSearch(list, 7));
    PrintList(list);

    free(list);
    return 0;
}